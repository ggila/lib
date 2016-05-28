/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_getnextkv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 10:00:07 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/12 19:15:33 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

void			*set_getnextelem(t_set *set)
{
	static unsigned int			i = -1;
	static t_set_node			*node = NULL;

	if (i == set->size)
		i = -1;
	if (node && node->next)
		node = node->next;
	else
	{
		i++;
		while ((i < set->size) && (set->nodes[i] == NULL))
			i++;
		node = (i == set->size) ? NULL : set->nodes[i];
	}
	return (node ? &(node->elem) : NULL);
}
