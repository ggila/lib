/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 20:40:43 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/28 13:02:49 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"
#include <stdlib.h>

static char	set_node(t_hash_node h, char *str, void *value)
{
	if (!(h.str = ft_strdup(str)))
		return (KO);
	h.value = value;
	return (OK);
}

static char	set_new_node(t_hash_node h, char *str, void *value)
{
	t_hash_node	*new;

	while (h.next)
		h = h.next;
	if (!(new = malloc(sizeof(t_hash_node))))
		return (KO);
	h.next = new;
	new.next = NULL;
	return (set_node(new, str, value));
}

char	ht_add(t_hash_tb *ht, char *str, void *value, int size)
{
	unsigned long	i;
	t_hash_node		*ht_tab;

	i = ht->key_hash(value) % ht->size;
	ht_tab = ht->nodes;
	while (ht_tab[i].next != NULL)
	if (httab[i].value != NULL)
		return (set_new_node(hasht[i], str, value));
	else
		return (set_node(hasht[i], str, value));
}

