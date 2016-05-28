/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 17:19:16 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/26 16:44:55 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"
#include "ft_printf.h"

void			str_print(const char *str)
{
	ft_printf("%s", str);
}

void			int_print(const int *i)
{
	ft_printf("%d", *i);
}

static void		node_print(t_set_node *node, void (*elem_print)())
{
	while (node)
	{
		elem_print(node->elem);
		node = node->next;
		if (node)
			ft_printf("\t");
	}
}

void			set_print(t_set *set, void (*elem_print)())
{
	size_t	i;

	i = -1;
	if (set)
	{
		while (++i < set->size)
		{
			if (set->nodes[i] != NULL)
				node_print(set->nodes[i], elem_print);
		}
	}
}
