/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_verification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:11:29 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/15 12:11:58 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static
    void    fill(t_data *tab, t_point size, t_point start, char F)
{
    size_t a = 0;

    if (tab->map[start.y][start.x] == 'C')
    {
        tab->C--;
        tab->map[start.y][start.x] = '0';
    }
    if (start.x < a || start.x > (size.x - 1) ||
            start.y < a || start.y > (size.y - 1) ||
                tab->map[start.y][start.x] != F)
        return ;
    tab->map[start.y][start.x] = 'F';
    fill(tab, size, (t_point){start.x - 1, start.y}, F);
    fill(tab, size, (t_point){start.x + 1, start.y}, F);
    fill(tab, size, (t_point){start.x, start.y - 1}, F);
    fill(tab, size, (t_point){start.x, start.y + 1}, F);
}

void    fool_fill(t_data *tab, t_point size, t_point start)
{
    tab->map[start.y][start.x] = '0';
    fill(tab, size, start, tab->map[start.y][start.x]);
}