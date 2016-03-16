/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:53:48 by ggilaber          #+#    #+#             */
/*   Updated: 2016/03/15 17:22:45 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"

void	ht_freem(t_hash_tbl *ht)
{
	size_t		i;
	t_hash_node	*node;
	t_hash_node	*tmp;

	i = 0;
	while (i < ht->size)
	{
		node = ht->nodes[i];
		while (node)
		{
			tmp = node;
			node = node->next;
			free(tmp->kv.key);
			free(tmp->kv.value);
			free(tmp);
		}
		i++;
	}
	free(ht->nodes);
}
