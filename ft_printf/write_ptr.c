/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:48:05 by ggilaber          #+#    #+#             */
/*   Updated: 2015/12/04 16:56:37 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include <stdarg.h>
#define MASK_PTR 0xf000000000000000

void	write_ptr(int fd, void *ptr)
{
	char					str[16];
	int						i;
	char					add[16];
	long long unsigned int	p;

	ft_memcpy(str, "0123456789abcdef", 17);
	p = (long long unsigned int)ptr;
	i = -1;
	while (++i < 16)
	{
		add[i] = str[(p & MASK_PTR) >> 60];
		p = p << 4;
	}
	i = 0;
	while (i < 15 && add[i] == '0')
		i++;
	write(fd, "0x", 2);
	write(fd, add + i, 16 - i);
}
