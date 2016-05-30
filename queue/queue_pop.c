/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 11:39:38 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/30 18:03:20 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	*queue_pop(t_queue *queue)
{
	void			*addr;
	t_queue_node	*tmp;

	if (!queue->head)
		return (NULL);
	addr = queue->head->addr;
	tmp = queue->head;
	if (queue->tail == queue->head)
		queue->tail = NULL;
	queue->head = queue->head->next;
	free(tmp);
	return (addr);
}
