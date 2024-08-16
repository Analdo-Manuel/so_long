/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:58:32 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/16 14:40:27 by almanuel         ###   ########.fr       */
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
    position(zona, &player, 'P');
    position(zona, &porta, 'P');
    copy_map(zona);
    fool_fill(zona, zona->point, player);
    if (zona->C > 0)
    {
        ft_free(zona->ptr);
        messagen_erro(zona->map);
    } 
}

void    open_game(t_data *zona, int ix, int iy)
{
    size_t y;
    size_t x;

    y = 0;
    while (y < zona->point.y)
    {
        x = 0;
        ix = 0;
        while (x < zona->point.x)
        {
            if (zona->ptr[y][x] == '1')
                mlx_put_image_to_window(zona->mlx, zona->mlx_win, zona->img_wall, ix, iy);
            else if (zona->ptr[y][x] == 'P')
                mlx_put_image_to_window(zona->mlx, zona->mlx_win, zona->img_player, ix, iy);
            else if (zona->ptr[y][x] == 'C')
                mlx_put_image_to_window(zona->mlx, zona->mlx_win, zona->img_col, ix, iy);
            else if (zona->ptr[y][x] == 'E')
                mlx_put_image_to_window(zona->mlx, zona->mlx_win, zona->img_exit, ix, iy);
            else
                mlx_put_image_to_window(zona->mlx, zona->mlx_win, zona->img_sp, ix, iy);
            x++;
            ix +=50;
        }
        y++;
        iy +=50;
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

int    key_event(int keycode, void *param)
{
    static size_t  count = 1;
    printf("%ld\n", count++);
    if (keycode == 65307) { // Tecla 'Esc' em muitos sistemas
        printf("Tecla 'Esc' pressionada.\n");
        mlx_loop_end(param); // Encerra o loop principal da janela
    } else {
        printf("Tecla com código %d pressionada.\n", keycode);
    }
    return (0);
}
int main(int ac, char **av)
{
    int ix;
    int iy;

    (void)ac;
    (void)av;
    ix = 0;
    iy = 0;
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
    open_game(&zona, ix, iy);
    mlx_key_hook(zona.mlx_win, key_event, zona.mlx);
    mlx_loop(zona.mlx);
    
    ft_free(zona.map);
    ft_free(zona.ptr);
    mlx_destroy_window(zona.mlx, zona.mlx_win);
    mlx_destroy_display(zona.mlx);
    free(zona.mlx);
    return (0);
}