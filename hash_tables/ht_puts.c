/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 21:47:57 by ggilaber          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/02/05 11:31:09 by ggilaber         ###   ########.fr       */
||||||| merged common ancestors
<<<<<<< Temporary merge branch 1:hash_tables/ht_puts.c
/*   Updated: 2016/02/05 08:31:04 by ggilaber         ###   ########.fr       */
||||||| merged common ancestors
/*   Updated: 2016/01/28 23:58:04 by ggilaber         ###   ########.fr       */
=======
/*   Updated: 2016/02/05 11:31:09 by ggilaber         ###   ########.fr       */
>>>>>>> Temporary merge branch 2:hash_tables/ht_puts.c
=======
<<<<<<< HEAD:hash_tables/ht_puts.c
/*   Updated: 2016/02/05 11:31:09 by ggilaber         ###   ########.fr       */
||||||| merged common ancestors
/*   Updated: 2016/01/28 23:58:04 by ggilaber         ###   ########.fr       */
=======
/*   Updated: 2016/02/05 08:31:04 by ggilaber         ###   ########.fr       */
>>>>>>> origin:hash_tables/ht_puts.c
>>>>>>> 415d971bf9b76099d0caf80bc064b33dd132923d
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

static char	ht_add(t_hash_tbl *ht, t_kv *key_value, char m)
{
	unsigned long	i;
	t_hash_node		*node;

	i = ht->key_hash(key_value->value) % ht->size;
	node = ht->nodes[i];
	while (ht->key_cmp(key_value->key, node->kv.key) && node->next)
		node = node->next;
	if (node->next)
		return (reset_value(node, key_value, m));
	else
		return (set_new_node(node, key_value, m));
}

char	ht_putm(t_hash_tbl *ht, t_kv *key_value)
{
	return (ht_add(ht, key_value, 1));
}

char	ht_put(t_hash_tbl *ht, t_kv *key_value)
{
	return (ht_add(ht, key_value, 0));
}
