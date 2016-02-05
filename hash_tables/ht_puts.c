/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 21:47:57 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/05 11:31:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"
#include <stdlib.h>

static char	set_new_node(t_hash_node *node, t_kv *kv, char m)
{
	t_hash_node	*new;

	if (!(new = malloc(sizeof(t_hash_node))))
		return (KO);
	if (m)
	{
		if (!(new->kv.key = malloc(sizeof(kv->key_size))))
			return (KO);
		if (!(new->kv.value = malloc(sizeof(kv->value_size))))
			return (KO);
		ft_memcpy(new->kv.key, kv->key, kv->key_size);
		ft_memcpy(new->kv.value, kv->value, kv->value_size);
	}
	else
	{
		new->kv.key = kv->key;
		new->kv.value = kv->value;
	}
	new->kv.key_size = kv->key_size;
	new->kv.value_size = kv->value_size;
	new->next = NULL;
	node->next = new;
	return (OK);
}

static char	reset_value(t_hash_node *node, t_kv *kv, char m)
{
	if (m)
	{
		free(node->kv.value);
		if (!(node->kv.value = malloc(sizeof(kv->value_size))))
			return (KO);
		ft_memcpy(node->kv.value, kv->value, kv->value_size);
	}
	else
		node->kv.value = kv->value;
	node->kv.value_size;
	return (OK);
}

static char	ht_add(t_hash_tb *ht, t_kv *key_value, char malloc)
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

char	ht_putm(t_hash_tb *ht, t_kv *key_value)
{
	return (ht_add(ht, key_value, 1));
}

char	ht_put(t_hash_tb *ht, t_kv *key_value)
{
	return (ht_add(ht, key_value, 0));
}