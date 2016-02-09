/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 15:54:09 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/09 16:23:00 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

#define COMMA "."

void	write_float(int fd, float x, int dec)
{
	int		i;
	double	virg;

	if (dec > 50)
		dec = 50;
	ft_putnbr_fd(fd, (int)x);
	my_write(1, COMMA, 1);
	virg = x - (int)x;
	i = 0;
	while (i++ < dec)
		virg *= 10;
	ft_putnbr_fd(fd, (int)virg);
}
