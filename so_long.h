/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:00:18 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/13 20:30:47 by almanuel         ###   ########.fr       */
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
    char    **ptr;
    t_point     point;
    size_t  C;
    size_t  s_C;
    size_t  P;
    size_t  E;
}              t_data;

#endif