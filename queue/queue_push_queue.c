/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_insert.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 11:21:50 by ggilaber          #+#    #+#             */
/*   Updated: 2016/06/01 11:44:41 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	queue_push_queue(t_queue *queue, t_queue *add)
{
	if (!add->head)
		return;
	if (!queue->tail)
		queue->head = add->head;
	else
		queue->tail->next = add->head;
	queue->tail = add->tail;
}
