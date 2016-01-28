/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:53:48 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/29 00:04:22 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"
#include <stdlib.h>

void	ht_free(t_hash_tbl *ht)
{
	int	i;

	i = 0;
	while (i < ht[i]->size)
	{
		if (ht[i]->value != NULL)
		{
			free(ht[i]->key);
			free(ht[i]->value);
			free(ht[i]);
		}
		i++;
	}
	free(ht);
}
