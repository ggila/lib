/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 21:47:57 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/28 23:44:33 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"
#include <stdlib.h>

static char	set_new_node(t_hash_node *node, t_kv *kv)
{
	t_hash_node	*new;

	if (!(new = malloc(sizeof(t_hash_node))))
		return (KO);
	if (!(new = malloc(sizeof(kv->key_size))))
		return (KO);
	if (!(new = malloc(sizeof(kv->value_size))))
		return (KO);
	ft_memcopy(new->key, value, kv->key_size);
	ft_memcopy(new->value, value, kv->value_size);
	new->next = NULL;
	node->next = new;
	return (OK);
}

static char	reset_value()
{
	ft_memcpy(node->value, value, size);
}

char	ht_putm(t_hash_tb *ht, t_kv *key_value)
{
	unsigned long	i;
	t_hash_node		*node;

	i = ht->key_hash(key_value->value) % ht->size;
	node = ht->nodes[i];
	while (ht->key_cmp(key_value->key, key) && node->next)
		node = node->next;
	if (node->next)
		return (reset_value(node, value));
	else
		return (set_new_node(node, key_value));
}
