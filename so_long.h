/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:00:18 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/13 14:34:37 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"
#include <fcntl.h>
#include <unistd.h>

typedef struct s_data
{
    char    **p;
    int     x;
    int     y;
}           t_data;

#endif