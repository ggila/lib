/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_queue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 18:40:30 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/30 18:38:56 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <stdio.h>

void	rec_print(t_queue_node *node, void (*f)())
{
	f(node->addr);
	if (node->next)
		rec_print(node->next, f);
}

void	queue_print(t_queue *queue, void (*my_print)())
{
	if (queue->head)
		rec_print(queue->head, my_print);
}
