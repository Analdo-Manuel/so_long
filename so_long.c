/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:58:32 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/17 17:44:23 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static
    void    check_map(t_data *zona, char *str)
{
    t_point player;
    size_t  i;

    i = ft_strlen(str);
    if (str[i - 4] != '.' || str[i - 3] != 'b' || 
            str[i - 2] != 'e' || str[i - 1] != 'r')
    {   
        write(1, "Error wrong file extension\n", 27);
        exit (1);
    }
    open_zona(zona, str);
    val_retangulo(zona);
    val_valuer(zona);
    val_components(zona);
    position(zona, &player, 'P');
    copy_map(zona);
    fool_fill(zona, zona->point, player);
    if (zona->C > 0)
    {
        ft_free(zona->ptr);
        messagen_erro(zona->map);
    } 
}

void    open_game(t_data *zona, size_t x, size_t y)
{
    zona->ix = 0;
    zona->iy = 0;
    y = 0;
    while (y < zona->point.y)
    {
        x = 0;
        zona->ix = 0;
        while (x < zona->point.x)
        {
            if (zona->ptr[y][x] == '1')
                mlx_put_image_to_window(zona->mlx, zona->mlx_win, zona->img_wall, zona->ix, zona->iy);
            else if (zona->ptr[y][x] == 'P')
                mlx_put_image_to_window(zona->mlx, zona->mlx_win, zona->img_player, zona->ix, zona->iy);
            else if (zona->ptr[y][x] == 'C')
                mlx_put_image_to_window(zona->mlx, zona->mlx_win, zona->img_col, zona->ix, zona->iy);
            else if (zona->ptr[y][x] == 'E')
                mlx_put_image_to_window(zona->mlx, zona->mlx_win, zona->img_exit, zona->ix, zona->iy);
            else
                mlx_put_image_to_window(zona->mlx, zona->mlx_win, zona->img_sp, zona->ix, zona->iy);
            x++;
            zona->ix +=50;
        }
        y++;
        zona->iy +=50;
    }
}
size_t    init_img(t_data *zona)
{
    zona->img_player = mlx_xpm_file_to_image(zona->mlx, "imagens/parado.xpm", &zona->img_x, &zona->img_y);
    if (!zona->img_player)
        return (1);
    zona->img_col = mlx_xpm_file_to_image(zona->mlx, "imagens/fruta.xpm", &zona->img_x, &zona->img_y);
    if (!zona->img_col)
        return (2);
    zona->img_wall = mlx_xpm_file_to_image(zona->mlx, "imagens/parede.xpm", &zona->img_x, &zona->img_y);
    if (!zona->img_wall)
        return (3);
    zona->img_sp = mlx_xpm_file_to_image(zona->mlx, "imagens/fundo.xpm", &zona->img_x, &zona->img_y);
    if (!zona->img_sp)
        return (4);
    zona->img_exit = mlx_xpm_file_to_image(zona->mlx, "imagens/porta.xpm", &zona->img_x, &zona->img_y);
    if (!zona->img_exit)
        return (5);
    return (0);
}
void    img_free(t_data *zona, int c)
{
    if (c >= 2)
        mlx_destroy_image(zona->mlx, zona->img_player);
    if (c >= 3)
        mlx_destroy_image(zona->mlx, zona->img_col);
    if (c >= 4)
        mlx_destroy_image(zona->mlx, zona->img_wall);
    if (c >= 5)
        mlx_destroy_image(zona->mlx, zona->img_sp);
    if (c >= 6)
        mlx_destroy_image(zona->mlx, zona->img_exit);
}
void    total_free(t_data *zona, int c)
{
    ft_free(zona->map);
    ft_free(zona->ptr);
    img_free(zona, c);
    mlx_destroy_window(zona->mlx, zona->mlx_win);
    mlx_destroy_display(zona->mlx);
    free(zona->mlx);
    exit(1);
}
void    ft_putchar(char c)
{
    write(1, &c, 1);
}
void    ft_putnbr(int nbr)
{
    if (nbr > 9)
        ft_putnbr(nbr / 10);
    ft_putchar(nbr % 10 + '0');
}
int    key_event(int keycode, t_data *zona)
{
    t_point player;

    position(zona, &player, 'P');    
    if (keycode == 65307)
        total_free(zona, 6);
    else if (keycode == 65361)
        event_left(zona, player);
    else if (keycode == 65362)
        event_down(zona, player);
    else if (keycode == 65363)
        event_rigth(zona, player);
    else if (keycode == 65364)
        event_top(zona, player);
    open_game(zona, 0, 0);
    if (zona->E == 0)
    {
        write(1, "\033[32m\033[1mYOU WIN\033[0m\n", 22);
        total_free(zona, 6);
    }
    return (0);
}
int     close_win(t_data *zona)
{
    total_free(zona, 6);
    return (0);
}
int main(int ac, char **av)
{
    t_data  zona;
    int i;

    if (ac != 2)
        exit(1);
    map_init(&zona);
    check_map(&zona, av[1]);
    zona.mlx = mlx_init();
    if (zona.mlx == NULL)
        free(zona.mlx);
    zona.mlx_win = mlx_new_window(zona.mlx, zona.point.x*50, zona.point.y*50, "so_long");
    if (zona.mlx_win == NULL)
        mlx_destroy_window(zona.mlx, zona.mlx_win);
    i = init_img(&zona);
    if (i)
        total_free(&zona, i);
    open_game(&zona, 0, 0);
    mlx_key_hook(zona.mlx_win, key_event, &zona);
    mlx_hook(zona.mlx_win, 17, 0, close_win, &zona);
    mlx_loop(zona.mlx);
    return (0);
}
