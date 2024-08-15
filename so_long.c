/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:58:32 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/15 17:04:53 by almanuel         ###   ########.fr       */
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
    while (y < zona->point->y)
    {
        x = 0;
        ix = 0;
        while (x < zona.point.x)
        {
            if (zona.ptr[y][x] == '1')
                zona.img = mlx_xpm_file_to_image(zona.mlx, "imagens/parede.xpm", &zona.img_x, &zona.img_y);
            else if (zona.ptr[y][x] == 'P')
                zona.img = mlx_xpm_file_to_image(zona.mlx, "imagens/parado.xpm", &zona.img_x, &zona.img_y);
            else if (zona.ptr[y][x] == 'C')
                zona.img = mlx_xpm_file_to_image(zona.mlx, "imagens/fruta.xpm", &zona.img_x, &zona.img_y);
            else
                zona.img = mlx_xpm_file_to_image(zona.mlx, "imagens/fundo.xpm", &zona.img_x, &zona.img_y);
            mlx_put_image_to_window(zona.mlx, zona.mlx_win, zona.img, ix, iy);
            x++;
            ix +=50;
        }
        y++;
        iy +=50;
    }
}

int main(void)
{
    int ix;
    int iy;

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
    open_game(&zona, ix, iy);    
    if (zona.img == NULL)
    {
        mlx_destroy_window(zona.map, zona.mlx_win);
        mlx_destroy_display(zona.mlx);
        free(zona.mlx);
        return 1;
    }
    
    mlx_loop(zona.mlx);
    ft_free(zona.map);
    ft_free(zona.ptr);
    mlx_destroy_image(zona.mlx, zona.img);
    mlx_destroy_window(zona.mlx, zona.mlx_win);
    mlx_destroy_display(zona.mlx);
    free(zona.mlx);
    return (0);
}