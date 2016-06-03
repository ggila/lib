/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_getnextkv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 10:00:07 by ggilaber          #+#    #+#             */
/*   Updated: 2016/06/03 08:22:14 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

void			set_it_init(t_set_it *it)
{
	it->bucket = -1;
	it->node = NULL;
}

void			*set_getnextelem(t_set *set, t_set_it *it)
{
	unsigned int	i;
	t_set_node		*node;

	if ((i = it->bucket) == set->size)
		return (NULL);
	node = it->node;
	if (node && node->next)
		node = node->next;
	else
	{
		i++;
		while ((i < set->size) && (set->nodes[i] == NULL))
			i++;
		node = (i == set->size) ? NULL : set->nodes[i];
	}
	it->bucket = i;
	it->node = node;
	return (node ? node->elem : NULL);
}
