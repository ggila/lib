/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 11:19:21 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/30 18:39:34 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "stdlib.h"
# include <stdbool.h>

/*
** NULL value as addr are forbidden in this implementation, queue_pop()
** return NULL if queue is empty
*/

typedef struct	s_queue_node
{
	void	*addr;
	void	*next;
}				t_queue_node;

typedef struct	s_queue
{
	struct 	s_queue_node *head;
	struct 	s_queue_node *tail;
}				t_queue;

void	queue_init(t_queue *queue);
void	*queue_pop(t_queue *queue);
bool	queue_push(t_queue *queue, void *addr);
void	queue_print(t_queue *queue, void (*my_print)());

#endif
