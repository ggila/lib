/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _strvect_extend.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 16:35:24 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/20 17:22:29 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "strvect.h"

#include <stdlib.h>

char	_strvect_extend(t_strvect *vect)
{
	char		*new;
	uint32_t	new_capacity;

	new_capacity = 2 * vect->capacity;
	if ((new = malloc(new_capacity * sizeof(char))) == NULL)
		return (false);
	ft_memcpy(new, vect->str, vect->size + 1);
	vect->capacity = new_capacity;
	free(vect->str);
	vect->str = new;
	return (true);
}
