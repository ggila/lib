/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_queue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 18:40:30 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/18 18:51:37 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <stdio.h>

void	print_queue(t_queue *queue)
{
	t_queue_node	*tmp;

	tmp = queue->next;
	while (tmp != queue)
	{
		printf("%p\n", tmp->addr);
		tmp = tmp->next;
	}
}
