/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_verification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:11:29 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/19 16:07:04 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static
	void	fill(t_data *tab, t_point size, t_point start, char F)
{
	size_t	a;

	a = 0;
	if (tab->map[start.y][start.x] == 'C')
	{
		tab->c--;
		tab->map[start.y][start.x] = '0';
	}
	if (tab->map[start.y][start.x] == 'E')
		tab->e1++;
	if (start.x < a || start.x > (size.x - 1)
		|| start.y < a || start.y > (size.y - 1)
		|| tab->map[start.y][start.x] != F)
		return ;
	tab->map[start.y][start.x] = 'F';
	fill(tab, size, (t_point){start.x - 1, start.y}, F);
	fill(tab, size, (t_point){start.x + 1, start.y}, F);
	fill(tab, size, (t_point){start.x, start.y - 1}, F);
	fill(tab, size, (t_point){start.x, start.y + 1}, F);
}

void	fool_fill(t_data *tab, t_point size, t_point start)
{
	tab->map[start.y][start.x] = '0';
	fill(tab, size, start, tab->map[start.y][start.x]);
}

void	check_map(t_data *zona, char *str)
{
	t_point	player;
	size_t	i;

	i = ft_strlen(str);
	if (str[i - 4] != '.' || str[i - 3] != 'b'
		|| str[i - 2] != 'e' || str[i - 1] != 'r')
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
	if (zona->c > 0 || zona->e1 == 0)
	{
		ft_free(zona->ptr);
		messagen_erro(zona->map);
	}
}
