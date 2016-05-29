/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 17:19:16 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/29 21:01:55 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"
#include "ft_printf.h"

static void		node_print(t_hash_node *node, void (*key_print)(),
					void (*value_print)())
{
	while (node)
	{
		ft_printf("k: ");
		key_print(node->kv.key);
		ft_printf("\tv: ");
		value_print(node->kv.value);
		ft_printf("\n");
		node = node->next;
	}
}

void			ht_print(t_hash_tbl *ht, void (*key_print)(),
					void (*value_print)())
{
	size_t	i;

	i = -1;
	if (ht)
	{
		while (++i < ht->size)
		{
			if (ht->nodes[i] != NULL)
				node_print(ht->nodes[i], key_print, value_print);
		}
	}
}
