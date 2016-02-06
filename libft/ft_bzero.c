/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:05:02 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/06 19:10:50 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

void	ft_bzero(void *dst, size_t n)
{
	size_t	i;
	int64_t	*p1;
	char	*p2;

	if (!dst)
		return;
	p1 = (int64_t*)dst;
	p2 = (char*)dst;
	i = 0;
	while (8 * i < n)
	{
		p1[i] = (int64_t)0;
		i++;
	}
	i *= 8;
	while (i < n)
	{
		p2[i] = (char)0;
		++i;
	}
	return;
}
