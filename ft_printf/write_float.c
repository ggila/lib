/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 15:54:09 by ggilaber          #+#    #+#             */
/*   Updated: 2015/12/06 16:10:54 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#define COMMA "."

void	write_float(int fd, float x, int dec)
{
	int		i;
	int		virg;

	if (dec > 50)
		dec = 50;
	ft_putnbr((int)x);
	my_write(1, COMMA, 1);
	virg = x - (int)x;
	i = 0;
	while (i++ < dec)
		virg *= 10;
	ft_putnbr(virg);
}
