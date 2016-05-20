/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 08:45:34 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/20 17:23:11 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"

char			ht_init(t_hash_tbl *const ht, int size,
					int (*key_cmp)(), unsigned long (*key_hash)())
{
	if ((ht->nodes =
				(t_hash_node**)malloc(sizeof(t_hash_node*) * size)) == NULL)
		return (false);
	ft_bzero(ht->nodes, size * sizeof(t_hash_node*));
	ht->size = size;
	ht->key_cmp = key_cmp;
	ht->key_hash = key_hash;
	return (true);
}
