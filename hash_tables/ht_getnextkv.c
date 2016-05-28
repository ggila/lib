/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_getnextkv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 10:00:07 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/12 19:15:33 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"

void			*ht_getnextkv(t_hash_tbl *ht)
{
	static unsigned int			i = -1;
	static t_hash_node			*node = NULL;

	if (i == ht->size)
		i = -1;
	if (node && node->next)
		node = node->next;
	else
	{
		i++;
		while ((i < ht->size) && (ht->nodes[i] == NULL))
			i++;
		node = (i == ht->size) ? NULL : ht->nodes[i];
	}
	return (node ? &(node->kv) : NULL);
}
