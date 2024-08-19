/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almanuel <almanuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:45:01 by almanuel          #+#    #+#             */
/*   Updated: 2024/08/19 11:58:05 by almanuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	close_win(t_data *zona)
{
	total_free(zona, 6);
	return (0);
}

void	*ft_memset(void *ptr, int value, int size)
{
	unsigned char	*p;
	unsigned char	val;

	p = ptr;
	val = (unsigned char)value;
	while (size--)
		*p++ = val;
	return (ptr);
}
