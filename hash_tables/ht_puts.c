/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 21:47:57 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/05 08:31:04 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"
#include <stdlib.h>

static char	set_new_node(t_hash_node *node, t_kv *kv, char malloc)
{
	t_hash_node	*new;

	if (!(new = malloc(sizeof(t_hash_node))))
		return (KO);
	if (malloc)
	{
		if (!(new = malloc(sizeof(kv->key_size))))
			return (KO);
		if (!(new = malloc(sizeof(kv->value_size))))
			return (KO);
		ft_memcopy(new->key, kv->key, kv->key_size);
		ft_memcopy(new->value, kv->value, kv->value_size);
	}
	else
	{
		new->key = kv->key;
		new->value = kv->value;
	}
	new->key_size = kv->key_size;
	new->value_size = kv->value_size;
	new->next = NULL;
	node->next = new;
	return (OK);
}

static char	reset_value(t_hash_node *node, t_kv *kv, char malloc)
{
	free(node->value);
	if (malloc)
	{
		if (!(new = malloc(sizeof(kv->value_size))))
			return (KO);
		ft_memcopy(node->value, kv->value, kv->value_size);
	}
	else
		node->value = kv->value;
	node->value_size;
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
