/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:53:48 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/12 19:12:43 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"
#include <stdlib.h>

void	set_free(t_set *set)
{
	size_t	i;

	i = 0;
	while (i < set->size)
		free(set->nodes[i++]);
	free(set->nodes);
}
