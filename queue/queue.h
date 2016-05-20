/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 11:19:21 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/20 17:42:34 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "stdlib.h"
# include <stdbool.h>

/*
** Dumb implementation, no need of double link list, simple ll is good enough,
** with head and tail (push at tail, pop at head)
*/

/*
** NULL value as add are forbidden in this implementation, pop() return NULL
** if queue is empty
*/

typedef struct	s_queue_node
{
	void	*addr;
	struct 	s_queue_node *next;
	struct 	s_queue_node *prev;
}				t_queue_node;

typedef t_queue_node t_queue;

void	queue_init(t_queue *queue);
void	*pop(t_queue *queue);
char	push(t_queue *queue, void *addr);
void	print_queue(t_queue *queue);

#endif
