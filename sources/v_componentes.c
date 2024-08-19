/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_componentes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:07:53 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/19 13:23:18 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	val_retangulo(t_data *zona)
{
	size_t	ix;
	size_t	iy;
	size_t	ix1;

	ix1 = ft_strlen(zona->ptr[0]);
	iy = 0;
	while (zona->ptr[iy])
	{
		ix = 0;
		while (zona->ptr[iy][ix])
			ix++;
		if (ix1 != ix)
			messagen_erro(zona->ptr);
		ix1 = ix;
		iy++;
	}
	if (ix == iy)
		messagen_erro(zona->ptr);
	zona->point.x = ix;
	zona->point.y = iy;
}

void	val_valuer(t_data *zona)
{
	size_t	ix;
	size_t	iy;

	iy = 0;
	while (iy < zona->point.y)
	{
		ix = 0;
		while (ix < zona->point.x)
		{
			if (iy == 0 && zona->ptr[iy][ix] != '1')
				messagen_erro(zona->ptr);
			if (iy > 0 && iy < zona->point.y)
				if ((ix == 0 || ix == (zona->point.x - 1))
					&& zona->ptr[iy][ix] != '1')
					messagen_erro(zona->ptr);
			if (iy == (zona->point.y - 1) && zona->ptr[iy][ix] != '1')
				messagen_erro(zona->ptr);
			ix++;
		}
		iy++;
	}
}

static
	void	val_components_2(t_data *zona, size_t iy, size_t ix)
{
	if (zona->ptr[iy][ix] != '1' && zona->ptr[iy][ix] != '0'
		&& zona->ptr[iy][ix] != 'P' && zona->ptr[iy][ix] != 'E'
		&& zona->ptr[iy][ix] != 'C')
		messagen_erro(zona->ptr);
}

void	val_components(t_data *zona)
{
	size_t	ix;
	size_t	iy;

	iy = 0;
	while (iy < zona->point.y)
	{
		ix = 0;
		while (ix < zona->point.x)
		{
			if (zona->ptr[iy][ix] == 'P')
				zona->p++;
			if (zona->ptr[iy][ix] == 'E')
				zona->e++;
			if (zona->ptr[iy][ix] == 'C')
			{
				zona->c1++;
				zona->c++;
			}
			val_components_2(zona, iy, ix);
			ix++;
		}
		iy++;
	}
	if (zona->p != 1 || zona->e != 1 || zona->c < 1)
		messagen_erro(zona->ptr);
}

void	position(t_data *zona, t_point *position, char c)
{
	position->y = 0;
	while (position->y < zona->point.y)
	{
		position->x = 0;
		while (position->x < zona->point.x)
		{
			if (zona->ptr[position->y][position->x] == c)
				return ;
			position->x++;
		}
		position->y++;
	}
}
