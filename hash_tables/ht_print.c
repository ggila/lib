/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 17:19:16 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/09 16:00:16 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"
#include "ft_printf.h"

#define NODE_HEADER "---------------------\nnode n*%lu:\n"
#define NODE_SEP "---/\n  /\n /-->"

void			str_print(const char *str)
{
	ft_printf("%s", str);
}

void			int_print(const int *i)
{
	ft_printf("%d", *i);
}

static void	node_print(t_hash_node *node, void (*key_print)(),
				void (*value_print)())
{
	while (node)
	{
		ft_printf("addr: %p\n", node);
		ft_printf("key: ");
		key_print(node->kv.key);
		ft_printf("\nkey size: %d\n", (int)node->kv.key_size);
		ft_printf("value: ");
		value_print(node->kv.value);
		ft_printf("\nvalue size: %d\n", (int)node->kv.value_size);
		ft_printf("next: ");
		if (node->next == NULL)
			ft_printf("NULL\n");
		else
			ft_printf("%p\n%s", node->next, NODE_SEP);
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
		ft_printf("size: %d\n", (int)ht->size);
		while (++i < ht->size)
		{
			ft_printf(NODE_HEADER, i);
			if (ht->nodes[i] == NULL)
				ft_printf("NULL\n");
			else
				node_print(ht->nodes[i], key_print, value_print);
		}
		ft_printf("---------------------\n");
	}
}
