/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 16:01:14 by ggilaber          #+#    #+#             */
/*   Updated: 2016/06/02 16:15:11 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

t_set	*set_copy(t_set *set)
{
	t_set	*new;
	void	*elem;

	if (!(new = malloc(sizeof(t_set))) ||
			!set_init(new, set->size, set->elem_cmp, set->elem_hash))
		return (NULL);
	while ((elem = set_getnextelem(set)))
	{
		if (!set_put(new, elem))
			return (NULL);
	}
	return (new);
}
