/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 08:45:34 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/05 08:14:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"

char			ht_init(t_hash_tbl *const ht, const int size,
					const int (*key_cmp)(const void *a, const void *b),
					const unsigned long (*key_hash)(const void *key))
{
	if ((ht->nodes = (t_hash_node**)malloc(sizeof(t_hash_node) * size)) == NULL)
		return (KO);
	ht->size = size;
	ht->key_cmp = key_cmp;
	ht->key_hash = key_hash;
	return (OK);
}
