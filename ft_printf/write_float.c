/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 15:54:09 by ggilaber          #+#    #+#             */
/*   Updated: 2016/03/15 16:36:45 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

#define COMMA "."
#define ZERO "0000000000000000000000"

void	write_float(int fd, float x, int dec)
{
	int		i;
	int		zero;
	double	virg;

	if (dec > 50)
		dec = 50;
	ft_putnbr_fd(fd, (int)x);
	my_write(1, COMMA, 1);
	virg = x - (int)x;
	i = 0;
	zero = 0;
	while (i++ < dec)
	{
		virg *= 10;
		if (((int)virg) == 0)
			zero++;
	}
	my_write(1, ZERO, zero);
	if ((int)virg)
		ft_putnbr_fd(fd, (int)virg);
}
