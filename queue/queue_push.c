/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 11:24:43 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/30 18:38:27 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

bool	queue_push(t_queue *queue, void *addr)
{
	t_queue_node	*new;

	if (addr == NULL)
		return (false);
	if ((new = malloc(sizeof(t_queue_node))) == NULL)
		return (false);
	new->addr = addr;
	new->next = NULL;
	if (queue->tail)
		queue->tail->next = new;
	else
		queue->head = new;
	queue->tail = new;
	return (true);
}
