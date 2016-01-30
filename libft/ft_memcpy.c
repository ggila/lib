/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:07:14 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/30 18:05:43 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst)
		return;
	i = 0;
	while (i < n / 8)
	{
		*((long unsigned int*)dst + i) = *((long unsigned int*)src + i);
		i += 8;
	}
	while (i < n)
	{
		((char*)dst)[i] = ((char*)src)[i];
		++i;
	}
	return;
}
