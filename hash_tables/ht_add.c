/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 20:40:43 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/26 21:08:19 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"

static char	set_node(t_htnode h, char *str, void *value)
{
	if (!(h.str = ft_strdup(str)))
		return (KO);
	h.value = value;
	return (OK);
}

static char	set_new_node(t_htnode h, char *str, void *value)
{
	t_htnode	*new;

	if (!(new = malloc(sizeof(t_htnode))))
		return (KO);
	h.next = new;
	new.next = NULL;
	return (set_node(new, str, value));
}

char		ht_add(t_htnode hasht[], char *str, void *value)
{
	unsigned long	i;

	i = hash_djb2(str) % SIZE;
	if (hasht[i].next == NULL)
		return (set_new_node(hasht[i], str, value));
	else
		return (set_node(hasht[i], str, value));
}

