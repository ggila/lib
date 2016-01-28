/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 08:45:34 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/28 10:35:41 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"

char	ht_init(t_hash_tbl ht, int size
			, int (*key_cmp)(const void *a, const void *b)
			, unsigned long (*key_index)(const void *key))
{
	if ((ht.nodes = (t_hash_node**)malloc(sizeof(t_hash_node) * size)) == NULL)
		return (KO);
	ht.size = size;
	ht.key_cmp = key_cmp;
	ht.key_index = key_index;
	return (OK);
}
