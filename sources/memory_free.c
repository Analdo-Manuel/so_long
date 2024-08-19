/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:02:37 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/19 16:03:33 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	messagen_erro(char **str)
{
	ft_free(str);
	write(1, "Error in map structer\n", 22);
	exit(1);
}

static
	void	img_free(t_data *zona, int c)
{
	if (c >= 2)
		mlx_destroy_image(zona->mlx, zona->img_player);
	if (c >= 3)
		mlx_destroy_image(zona->mlx, zona->img_col);
	if (c >= 4)
		mlx_destroy_image(zona->mlx, zona->img_wall);
	if (c >= 5)
		mlx_destroy_image(zona->mlx, zona->img_sp);
	if (c >= 6)
		mlx_destroy_image(zona->mlx, zona->img_exit);
}

void	total_free(t_data *zona, int c)
{
	ft_free(zona->map);
	ft_free(zona->ptr);
	img_free(zona, c);
	mlx_destroy_window(zona->mlx, zona->mlx_win);
	mlx_destroy_display(zona->mlx);
	free(zona->mlx);
	exit(1);
}

void	map_init(t_data *zona)
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
	zona->c1 = 0;
	zona->c = 0;
	zona->e = 0;
	zona->e1 = 0;
	zona->p = 0;
	zona->img_x = 0;
	zona->img_y = 0;
	zona->ix = 0;
	zona->iy = 0;
	zona->count = 0;
}
