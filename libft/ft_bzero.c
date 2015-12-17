/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:37:51 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/27 11:05:45 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

void	ft_bzero(void *dst, size_t n)
{
	size_t	i;

	if (!dst)
		return;
	i = 0;
	while (i < n / 8)
	{
		*((long unsigned int*)dst + i) = (long unsigned int)0;
		i += 8;
	}
	while (i < n)
	{
		((char*)dst)[i] = (char)0;
		++i;
	}
	return;
}
