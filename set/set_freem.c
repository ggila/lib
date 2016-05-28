/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:53:48 by ggilaber          #+#    #+#             */
/*   Updated: 2016/03/15 17:22:45 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

void	set_freem(t_set *set)
{
	size_t		i;
	t_set_node	*node;
	t_set_node	*tmp;

	i = 0;
	while (i < set->size)
	{
		node = set->nodes[i];
		while (node)
		{
			tmp = node;
			node = node->next;
			free(tmp->elem);
			free(tmp);
		}
		i++;
	}
	free(set->nodes);
}
