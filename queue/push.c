/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 11:24:43 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/20 17:22:45 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

char	push(t_queue *queue, void *addr)
{
	t_queue_node	*new;

	if (addr == NULL)
		return (false);
	if ((new = malloc(sizeof(t_queue_node))) == NULL)
		return (false);
	new->addr = addr;
	new->next = queue->next;
	new->prev = (t_queue_node*)queue;
	queue->next->prev = new;
	queue->next = new;
	return (true);
}
