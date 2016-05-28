/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_isin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:12:25 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/26 16:04:48 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

bool	set_isin(t_set *set, void *elem)
{
	unsigned long	i;
	t_set_node		*node;

	i = set->elem_hash(elem) % set->size;
	node = set->nodes[i];
	while (node && set->elem_cmp(node->elem, elem) && node->next)
		node = node->next;
	return (node && set->elem_cmp(node->elem, elem) == 0 ? 1 : 0);
}
