/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:00:18 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/15 16:57:00 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"
#include <fcntl.h>
#include <unistd.h>

typedef struct s_point
{
    size_t  x;
    size_t  y;
}              t_point;

typedef struct s_data
{
    void    *mlx;
    void    *mlx_win;
    void    *img;
    char    **ptr;
    char    **map;
    t_point     point;
    size_t  C;
    size_t  s_C;
    size_t  P;
    size_t  E;
    int     img_x;
    int     img_y;
}              t_data;

void    open_zona(t_data *zona);
void    ft_free(char **str);
void    map_init(t_data *zona);
void    messagen_erro(char **str);
void    copy_map(t_data *map);
void    fool_fill(t_data *tab, t_point size, t_point start);
void    val_retangulo(t_data *zona);
void    val_valuer(t_data *zona);
void    val_components(t_data *zona);
void    position(t_data *zona, t_point *position, char c);

char    **ft_split(char *str, char c);

size_t  ft_strlen(char *str);

#endif