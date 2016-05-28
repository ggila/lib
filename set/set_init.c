/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 08:45:34 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/26 16:04:21 by ggilaber         ###   ########.fr       */
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
	set->size = size;
	set->elem_cmp = elem_cmp;
	set->elem_hash = elem_hash;
	return (true);
}
