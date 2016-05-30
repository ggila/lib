/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_puts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 21:47:57 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/30 16:13:08 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

static bool	set_new_node(t_set_node **node, void *const elem,
							size_t size, char m)
{
	t_set_node	*new;

	if (!(new = malloc(sizeof(t_set_node))))
		return (false);
	if (m)
	{
		if (!(new->elem = malloc(size)))
			return (false);
		ft_memcpy(new->elem, elem, size);
	}
	else
		new->elem = elem;
	new->size = size;
	new->next = NULL;
	if (*node)
		(*node)->next = new;
	else
		*node = new;
	return (true);
}

static bool	set_add(t_set *const set,
		void *const elem, size_t size, char m)
{
	unsigned long	i;
	t_set_node		*node;

	if (set_isin(set, elem))
		return true;
	i = set->elem_hash(elem) % set->size;
	node = set->nodes[i];
	if (node == NULL)
	{
		if (!set_new_node(&(set->nodes[i]), elem, size, m))
			return (false);
	}
	else
	{
		while (node->next)
			node = node->next;
		if (!set_new_node(&node, elem, size, m))
			return (false);
	}
	set->nb_nodes += 1;
	return (true);
}

bool		set_putm(t_set *const set, void *const elem, size_t size)
{
	return (set_add(set, elem, size, 1));
}

bool		set_put(t_set *const set, void *const elem, size_t size)
{
	return (set_add(set, elem, size, 0));
}
