/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:07:14 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/06 19:09:37 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

void	ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	int64_t			*p1_dst;
	char			*p2_dst;
	const int64_t	*p1_src = (const int64_t*)src;
	const char		*p2_src = (const char*)src;

	if (!dst)
		return;
	p1_dst = (int64_t*)dst;
	p2_dst = (char*)dst;
	i = 0;
	while (8 * i < n)
	{
		p1_dst[i] = p1_src[i];
		i++;
	}
	i *= 8;
	while (i < n)
	{
		p2_dst[i] = p2_src[i];
		++i;
	}
	return;
}
