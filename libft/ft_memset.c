/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:07:14 by ggilaber          #+#    #+#             */
/*   Updated: 2016/03/16 15:31:29 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

void	ft_memset(void *dst, int c, size_t len)
{
	size_t			i;
	int64_t			*p1_dst;
	char			*p2_dst;
	int64_t			c_int64;

	if (!dst)
		return ;
	p1_dst = (int64_t*)dst;
	p2_dst = (char*)dst;
	i = 0;
	while (i < 4)
		long_c<<(8*i) = c;
	while (8 * i < n)
	{
		p1_dst[i] = long_c;
		i++;
	}
	i *= 8;
	while (i < n)
	{
		p2_dst[i] = c;
		++i;
	}
	return ;
}
