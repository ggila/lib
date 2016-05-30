/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 08:45:34 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/30 15:40:56 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

bool	set_init(t_set *const set, int size,
			int (*elem_cmp)(), unsigned long (*elem_hash)())
{
	if ((set->nodes =
				(t_set_node**)malloc(sizeof(t_set_node*) * size)) == NULL)
		return (false);
	ft_bzero(set->nodes, size * sizeof(t_set_node*));
	set->nb_nodes = 0;
	set->size = size;
	set->elem_cmp = elem_cmp;
	set->elem_hash = elem_hash;
	return (true);
}
