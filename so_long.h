/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:00:18 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/19 16:03:42 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct s_point
{
	size_t	x;
	size_t	y;
}	t_point;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img_player;
	void	*img_exit;
	void	*img_col;
	void	*img_wall;
	void	*img_sp;
	char	**ptr;
	char	**map;
	size_t	c;
	size_t	c1;
	size_t	p;
	size_t	e;
	size_t	e1;
	int		img_x;
	int		img_y;
	int		ix;
	int		iy;
	int		count;
	t_point	point;
}	t_data;

void	open_zona(t_data *zona, char *str);
void	ft_free(char **str);
void	map_init(t_data *zona);
void	messagen_erro(char **str);
void	copy_map(t_data *map);
void	fool_fill(t_data *tab, t_point size, t_point start);
void	val_retangulo(t_data *zona);
void	val_valuer(t_data *zona);
void	val_components(t_data *zona);
void	position(t_data *zona, t_point *position, char c);
void	event_down(t_data *zona, t_point player);
void	event_top(t_data *zona, t_point player);
void	event_left(t_data *zona, t_point player);
void	event_rigth(t_data *zona, t_point player);
void	ft_putnbr(int nbr);
void	ft_putchar(char c);
void	check_map(t_data *zona, char *str);
void	total_free(t_data *zona, int c);
void	*ft_memset(void *ptr, int value, int size);

char	**ft_split(char *str, char c);

size_t	ft_strlen(char *str);
int		close_win(t_data *zona);
#endif
