/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:53:48 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/28 13:02:49 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"
#include <stdlib.h>

void	ht_free_node(t_hash_node h)
{
	if (h.next != NULL)
	{
		ht_free_node(h.next);
		free(h.next);
	}
	free(h.key);
}

void	ht_free(t_hash_node hasht[])
{
	int	i;

	i = 0;
	while (i < HT_SIZE)
	{
		if (hasht[i].value != NULL)
			ht_free_node(hasht[i]);
		i++;
	}
}
