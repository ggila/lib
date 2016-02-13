/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 21:47:57 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/13 10:23:44 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"
#include <unistd.h>

static char	set_new_node(t_hash_node **node, const t_kv *const kv, char m)
{
	t_hash_node	*new;

	if (!(new = malloc(sizeof(t_hash_node))))
		return (KO);
	if (m)
	{
		if (!(new->kv.key = malloc(sizeof(kv->key_size)))
				|| !(new->kv.value = malloc(sizeof(kv->value_size))))
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
	if (*node)
		(*node)->next = new;
	else
		*node = new;
	return (OK);
}

static char	reset_value(t_hash_node *const node, const t_kv *const kv, char m)
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
	node->kv.value_size = kv->value_size;
	return (OK);
}

static char	ht_add(t_hash_tbl *const ht,
		const t_kv *const key_value, char m)
{
	unsigned long	i;
	t_hash_node		*node;

	i = ht->key_hash(key_value->key) % ht->size;
	if ((node = ht->nodes[i]) == NULL)
		return (set_new_node(&(ht->nodes[i]), key_value, m));
	while (ht->key_cmp(key_value->key, node->kv.key) && node->next)
		node = node->next;
	if (ht->key_cmp(key_value->key, node->kv.key) == 0)
		return (reset_value(node, key_value, m));
	else
		return (set_new_node(&node, key_value, m));
}

char		ht_putm(t_hash_tbl *const ht, const t_kv *const key_value)
{
	return (ht_add(ht, key_value, 1));
}

char		ht_put(t_hash_tbl *const ht, const t_kv *const key_value)
{
	return (ht_add(ht, key_value, 0));
}
