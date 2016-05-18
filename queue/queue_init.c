/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 11:22:56 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/18 12:12:12 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	queue_init(t_queue *queue)
{
	queue->addr = NULL;
	queue->next = (t_queue_node*)queue;
	queue->prev = (t_queue_node*)queue;
}
