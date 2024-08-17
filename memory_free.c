/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:02:37 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/17 17:34:20 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_free(char **str)
{
    size_t i;

    i = 0;
    while (str[i])
        free(str[i++]);
    free(str);
}
void    messagen_erro(char **str)
{
    ft_free(str);
    write(1, "Error in map structer\n", 22);
    exit(1);
}
void   map_init(t_data *zona)
{
    zona->ptr = NULL;
    zona->map = NULL;
    zona->img_col = NULL;
    zona->img_exit = NULL;
    zona->img_player = NULL;
    zona->img_sp = NULL;
    zona->img_wall = NULL;
    zona->point.x = 0;
    zona->point.y = 0;
    zona->C1 = 0;
    zona->C = 0;
    zona->E = 0;
    zona->P = 0;
    zona->img_x = 0;
    zona->img_y = 0;
    zona->ix = 0;
    zona->iy = 0;
    zona->count = 0;
}
size_t  ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}