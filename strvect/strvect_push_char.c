/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strvect_push_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 16:25:31 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/20 16:56:13 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strvect.h"

char	strvect_push_char(t_strvect *vect, char c)
{
	if (vect->size + 1 == vect->capacity && _strvect_extend(vect) == KO)
		return (KO);
	vect->str[vect->size] = c;
	vect->size += 1;
	vect->str[vect->size] = '\0';
	return (OK);
}
