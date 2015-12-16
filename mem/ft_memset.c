/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:37:51 by ggilaber          #+#    #+#             */
/*   Updated: 2015/12/04 08:54:41 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

//Does not work

void	ft_memset(void *dst, char c, size_t n)
{
	size_t				i;
	long unsigned int	s;

	if (!dst)
		return;
	i = -1;
	while (++i < 3)
		s += c << (i * 8);
	i = 0;
	while (i < n / 8)
	{
		*((long unsigned int*)dst + i) = s;
		i += 8;
	}
	while (i < n)
	{
		((char*)dst)[i] = c;
		++i;
	}
	return;
}
