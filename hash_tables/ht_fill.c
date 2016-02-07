/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 16:55:40 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/07 18:11:27 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"

void	ht_fill(t_hash_tbl *const ht, t_kv kv_tab[])
{
	int	i;

	i = 0;
	while (kv_tab[i].key_size != -1)
		ht_put(ht, &(kv_tab[i++]));
}
