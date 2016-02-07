/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_isset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:12:25 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/07 18:14:59 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"

char	ht_isset(t_hash_tbl *ht, void *key)
{
	unsigned long	i;
	t_hash_node		*node;

	i = ht->key_hash(key) % ht->size;
	node = ht->nodes[i];
	while (ht->key_cmp(node->kv.key, key) && node->next)
		node = node->next;
	return (ht->key_cmp(node->kv.key, key) == 0 ? 1 : 0);
}
