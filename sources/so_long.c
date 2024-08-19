/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:58:32 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/19 13:23:18 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static
	void	loop_game(t_data *zona, size_t x, size_t y)
{
	if (zona->ptr[y][x] == '1')
		mlx_put_image_to_window(zona->mlx,
			zona->mlx_win, zona->img_wall, zona->ix, zona->iy);
	else if (zona->ptr[y][x] == 'P')
		mlx_put_image_to_window(zona->mlx,
			zona->mlx_win, zona->img_player, zona->ix, zona->iy);
	else if (zona->ptr[y][x] == 'C')
		mlx_put_image_to_window(zona->mlx,
			zona->mlx_win, zona->img_col, zona->ix, zona->iy);
	else if (zona->ptr[y][x] == 'E')
		mlx_put_image_to_window(zona->mlx,
			zona->mlx_win, zona->img_exit, zona->ix, zona->iy);
	else
		mlx_put_image_to_window(zona->mlx,
			zona->mlx_win, zona->img_sp, zona->ix, zona->iy);
}

static
	void	open_game(t_data *zona, size_t x, size_t y)
{
	zona->ix = 0;
	zona->iy = 0;
	y = 0;
	while (y < zona->point.y)
	{
		x = 0;
		zona->ix = 0;
		while (x < zona->point.x)
		{
			loop_game(zona, x, y);
			x++;
			zona->ix += 50;
		}
		y++;
		zona->iy += 50;
	}
}

size_t	init_img(t_data *zona)
{
	zona->img_player = mlx_xpm_file_to_image(zona->mlx,
			"imagens/parado.xpm", &zona->img_x, &zona->img_y);
	if (!zona->img_player)
		return (1);
	zona->img_col = mlx_xpm_file_to_image(zona->mlx,
			"imagens/fruta.xpm", &zona->img_x, &zona->img_y);
	if (!zona->img_col)
		return (2);
	zona->img_wall = mlx_xpm_file_to_image(zona->mlx,
			"imagens/parede.xpm", &zona->img_x, &zona->img_y);
	if (!zona->img_wall)
		return (3);
	zona->img_sp = mlx_xpm_file_to_image(zona->mlx,
			"imagens/fundo.xpm", &zona->img_x, &zona->img_y);
	if (!zona->img_sp)
		return (4);
	zona->img_exit = mlx_xpm_file_to_image(zona->mlx,
			"imagens/porta.xpm", &zona->img_x, &zona->img_y);
	if (!zona->img_exit)
		return (5);
	return (0);
}

int	key_event(int keycode, t_data *zona)
{
	t_point	player;

	position(zona, &player, 'P');
	if (keycode == 65307)
		total_free(zona, 6);
	else if (keycode == 65361)
		event_left(zona, player);
	else if (keycode == 65362)
		event_down(zona, player);
	else if (keycode == 65363)
		event_rigth(zona, player);
	else if (keycode == 65364)
		event_top(zona, player);
	open_game(zona, 0, 0);
	if (zona->e == 0)
	{
		write(1, "\033[32m\033[1mYOU WIN\033[0m\n", 22);
		total_free(zona, 6);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	zona;
	int		i;

	if (ac != 2)
		exit(1);
	map_init(&zona);
	check_map(&zona, av[1]);
	zona.mlx = mlx_init();
	if (zona.mlx == NULL)
		free(zona.mlx);
	zona.mlx_win = mlx_new_window(zona.mlx,
			zona.point.x * 50, zona.point.y * 50, "so_long");
	if (zona.mlx_win == NULL)
		mlx_destroy_window(zona.mlx, zona.mlx_win);
	i = init_img(&zona);
	if (i)
		total_free(&zona, i);
	open_game(&zona, 0, 0);
	mlx_key_hook(zona.mlx_win, key_event, &zona);
	mlx_hook(zona.mlx_win, 17, 0, close_win, &zona);
	mlx_loop(zona.mlx);
	return (0);
}
