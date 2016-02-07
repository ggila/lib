/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 17:19:16 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/07 12:43:38 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"
#include <stdio.h>

#define NODE_HEADER "---------------------\nnode n*%lu:\n"
#define NODE_SEP "---/\n  /\n /-->"

static void	node_print(t_hash_node *node, void (*key_print)(),
				void (*value_print)())
{
	while (node)
	{
		printf("key: ");
		key_print(node->kv.key);
		printf("\nkey size : %lu\n", node->kv.key_size);
		printf("value: ");
		value_print(node->kv.value);
		printf("\nvalue size : %lu\n", node->kv.value_size);
		printf("next: ");
		if (node->next == NULL)
			printf("NULL\n");
		else
			printf("%p\n%s", node->next, NODE_SEP);
		node = node->next;
	}
}

void		ht_print(t_hash_tbl *ht, void (*key_print)(),
				void (*value_print)())
{
	size_t	i;

	i = -1;
	if (ht)
	{
		printf("size: %lu\n", ht->size);
		while (++i < ht->size)
		{
			printf(NODE_HEADER, i);
			if (ht->nodes[i] == NULL)
				printf("NULL\n");
			else
				node_print(ht->nodes[i], key_print, value_print);
		}
	}
}
