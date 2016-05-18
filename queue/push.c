/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 11:24:43 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/18 18:51:26 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

char	push(t_queue *queue, void *addr)
{
	t_queue_node	*new;

	if (addr == NULL)
		return (KO);
	if ((new = malloc(sizeof(t_queue_node))) == NULL)
		return (KO);
	new->addr = addr;
	new->next = queue->next;
	new->prev = (t_queue_node*)queue;
	queue->next->prev = new;
	queue->next = new;
	return (OK);
}
