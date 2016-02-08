/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_getnextkv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 10:00:07 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/08 10:45:34 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"

#include <stdio.h>

void			*ht_getnextkv(t_hash_tbl *ht)
{
	static int			i = 0;
	static t_hash_node	*node = NULL;

	if (i == ht->size)
		i = 0;
	if (node && node->next)
		node = node->next;
	else
	{
		printf("%d\n", i);
		while ((i < ht->size) && (ht->nodes[i] == NULL))
			i++;
		node = (i == ht->size) ? NULL : ht->nodes[i];
	}
	printf("%p\n", &node->kv);
	return (node ? NULL : &(node->kv));
}
