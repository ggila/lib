/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 11:39:38 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/18 12:11:47 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	*pop(t_queue *queue)
{
	void			*addr;
	t_queue_node	*tmp;

	if (queue->next == queue)
		return NULL;
	addr = queue->prev->addr;
	tmp = queue->prev;
	queue->prev->prev->next = (t_queue_node*)queue;
	queue->prev = queue->prev->prev;
	free(tmp);
	return (addr);
}
