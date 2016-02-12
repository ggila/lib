/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 16:55:40 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/12 19:34:55 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"

void	ht_fill(t_hash_tbl *const ht, t_kv const kv_tab[])
{
	int	i;

	i = 0;
	while (kv_tab[i].value != NULL)
		ht_put(ht, &(kv_tab[i++]));
}
