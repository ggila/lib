/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:47:40 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/11 19:00:34 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

#include "ft_printf.h"

#include <stdio.h>

#define MASK_PTR 0xf000000000000000

void	write_hex(int fd, unsigned int nb)
{
	char					str[16];
	int						i;
	char					add[16];
	long long unsigned int	p;

	ft_memcpy(str, "0123456789abcdef", 16);
	p = (long long unsigned int)nb;
	printf("nb: %d\nptr: %p\nllu: %llu\n", nb,  (void*)p, p);
	i = -1;
	while (++i < 16)
	{
		add[i] = str[(p & MASK_PTR) >> 60];
		p = p << 4;
	}
	i = 0;
	while (i < 15 && add[i] == '0')
		i++;
	write(fd, add + i, 16 - i);
}
