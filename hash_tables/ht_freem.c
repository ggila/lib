/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:53:48 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/06 19:14:44 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"

void	ht_freem(t_hash_tbl *ht)
{
	int	i;

	i = 0;
	while (i < ht->size)
	{
		if (ht->nodes[i])
		{
			free(ht->nodes[i]->kv.key);
			free(ht->nodes[i]->kv.value);
		}
		free(ht->nodes[i]);
		i++;
	}
}
