/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 21:07:26 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/29 00:01:04 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"

void	*ht_get(t_hash_tbl *ht, void *key)
{
	unsigned long	i;
	t_hash_node		*node;

	i = ht->key_hash(key) % ht->size;
	node = ht->nodes[i];
	while (ht->key_cmp(node->kv.key, key) && node->next)
		node = node->next;
	if (node->next)
		return (node->kv.value);
	else
		return (NULL);
}
