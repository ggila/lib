/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strvect_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 16:32:32 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/20 17:22:20 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strvect.h"
#include <stdlib.h>

char	strvect_init(t_strvect *vect)
{
	if ((vect->str = malloc(16 * sizeof(char))) == NULL)
		return (false);
	vect->str[0] = '\0';
	vect->size = 0;
	vect->capacity = 16;
	return (true);
}
