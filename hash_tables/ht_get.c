/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 21:07:26 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/27 17:33:28 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"

void	*ht_get(t_hash_tbl *ht, void *key)
{
	unsigned long	i;
	t_hash_node		*node;

	i = ht->key_hash(key) % ht->size;
	if ((node = ht->nodes[i]) == NULL)
		return (NULL);
	while (ht->key_cmp(node->kv.key, key) && node->next)
		node = node->next;
	if (ht->key_cmp(node->kv.key, key) == 0)
		return (node->kv.value);
	else
		return (NULL);
}
