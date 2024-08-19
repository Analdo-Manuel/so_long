/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:40:14 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/19 13:23:18 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static
	void	count_move(t_data *zona)
{
	zona->count++;
	ft_putnbr(zona->count);
	ft_putchar('\n');
}

void	event_rigth(t_data *zona, t_point player)
{
	if (zona->ptr[player.y][player.x + 1] != '1')
	{
		if (zona->ptr[player.y][player.x + 1] == '0')
		{
			zona->ptr[player.y][player.x] = '0';
			zona->ptr[player.y][player.x + 1] = 'P';
			count_move(zona);
		}
		else if (zona->ptr[player.y][player.x + 1] == 'C')
		{
			zona->c1--;
			zona->ptr[player.y][player.x] = '0';
			zona->ptr[player.y][player.x + 1] = 'P';
			count_move(zona);
		}
		else if (zona->ptr[player.y][player.x + 1] == 'E' && zona->c1 == 0)
		{
			zona->e--;
			zona->ptr[player.y][player.x] = '0';
			zona->ptr[player.y][player.x + 1] = 'P';
			count_move(zona);
		}
	}
}

void	event_left(t_data *zona, t_point player)
{
	if (zona->ptr[player.y][player.x - 1] != '1')
	{
		if (zona->ptr[player.y][player.x - 1] == '0')
		{
			zona->ptr[player.y][player.x] = '0';
			zona->ptr[player.y][player.x - 1] = 'P';
			count_move(zona);
		}
		else if (zona->ptr[player.y][player.x - 1] == 'C')
		{
			zona->c1--;
			zona->ptr[player.y][player.x] = '0';
			zona->ptr[player.y][player.x - 1] = 'P';
			count_move(zona);
		}
		else if (zona->ptr[player.y][player.x - 1] == 'E' && zona->c1 == 0)
		{
			zona->e--;
			zona->ptr[player.y][player.x] = '0';
			zona->ptr[player.y][player.x - 1] = 'P';
			count_move(zona);
		}
	}
}

void	event_top(t_data *zona, t_point player)
{
	if (zona->ptr[player.y + 1][player.x] != '1')
	{
		if (zona->ptr[player.y + 1][player.x] == '0')
		{
			zona->ptr[player.y][player.x] = '0';
			zona->ptr[player.y + 1][player.x] = 'P';
			count_move(zona);
		}
		else if (zona->ptr[player.y + 1][player.x] == 'C')
		{
			zona->c1--;
			zona->ptr[player.y][player.x] = '0';
			zona->ptr[player.y + 1][player.x] = 'P';
			count_move(zona);
		}
		else if (zona->ptr[player.y + 1][player.x] == 'E' && zona->c1 == 0)
		{
			zona->e--;
			zona->ptr[player.y][player.x] = '0';
			zona->ptr[player.y + 1][player.x] = 'P';
			count_move(zona);
		}
	}
}

void	event_down(t_data *zona, t_point player)
{
	if (zona->ptr[player.y - 1][player.x] != '1')
	{
		if (zona->ptr[player.y - 1][player.x] == '0')
		{
			zona->ptr[player.y][player.x] = '0';
			zona->ptr[player.y - 1][player.x] = 'P';
			count_move(zona);
		}
		else if (zona->ptr[player.y - 1][player.x] == 'C')
		{
			zona->c1--;
			zona->ptr[player.y][player.x] = '0';
			zona->ptr[player.y - 1][player.x] = 'P';
			count_move(zona);
		}
		else if (zona->ptr[player.y - 1][player.x] == 'E' && zona->c1 == 0)
		{
			zona->e--;
			zona->ptr[player.y][player.x] = '0';
			zona->ptr[player.y - 1][player.x] = 'P';
			count_move(zona);
		}
	}
}
