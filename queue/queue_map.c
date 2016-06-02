/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 14:55:11 by ggilaber          #+#    #+#             */
/*   Updated: 2016/06/02 15:02:23 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	queue_map(t_queue *queue, void (*f)())
{
	t_queue_node	*tmp;

	tmp = queue->head;
	while (tmp)
	{
		f(tmp->addr);
		tmp = tmp->next;
	}
}
