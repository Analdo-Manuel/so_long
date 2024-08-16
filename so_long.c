/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:58:32 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/16 15:51:05 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static
    void    check_map(t_data *zona)
{
    t_point porta;
    t_point player;

    map_init(zona);
    open_zona(zona);
    val_retangulo(zona);
    val_valuer(zona);
    val_components(zona);
    position(zona, &porta, 'P');
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
        return (0);
    zona->img_col = mlx_xpm_file_to_image(zona->mlx, "imagens/fruta.xpm", &zona->img_x, &zona->img_y);
    if (!zona->img_col)
        return (0);
    zona->img_wall = mlx_xpm_file_to_image(zona->mlx, "imagens/parede.xpm", &zona->img_x, &zona->img_y);
    if (!zona->img_wall)
        return (0);
    zona->img_sp = mlx_xpm_file_to_image(zona->mlx, "imagens/fundo.xpm", &zona->img_x, &zona->img_y);
    if (!zona->img_sp)
        return (0);
    zona->img_exit = mlx_xpm_file_to_image(zona->mlx, "imagens/porta.xpm", &zona->img_x, &zona->img_y);
    if (!zona->img_exit)
        return (0);
    return (1);
}

int    key_event(int keycode, t_data *zona)
{
    static size_t  count = 1;
    t_point player;
    size_t j = 0;

    position(zona, &player, 'P');    
    printf("%ld\n", count++);
    if (keycode == 65307) { // Tecla 'Esc' em muitos sistemas
        printf("Tecla 'Esc' pressionada.\n");
        exit(1); // Encerra o loop principal da janela
    }
    else if (keycode == 65363)
    {
        zona->ptr[player.y][player.x] = '0';
        zona->ptr[player.y][player.x+1] = 'P';
        while(j < zona->point.y)
        {
            printf("%s\n", zona->ptr[j]);
            j++;
        }
        open_game(zona, 0, 0);
    }
    else {
        printf("Tecla com código %d pressionada.\n", keycode);
    }
    return (0);
}
int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    t_data  zona;

    check_map(&zona);
    zona.mlx = mlx_init();
    if (zona.mlx == NULL)
        free(zona.mlx);
    zona.mlx_win = mlx_new_window(zona.mlx, zona.point.x*50, zona.point.y*50, "so_long");
    if (zona.mlx_win == NULL)
        mlx_destroy_window(zona.mlx, zona.mlx_win);
    if (!init_img(&zona))
        printf("Fail Opening\n");
    open_game(&zona, 0, 0);
    mlx_key_hook(zona.mlx_win, key_event, &zona);
    mlx_loop(zona.mlx);
    ft_free(zona.map);
    ft_free(zona.ptr);
    mlx_destroy_window(zona.mlx, zona.mlx_win);
    mlx_destroy_display(zona.mlx);
    free(zona.mlx);
    return (0);
}