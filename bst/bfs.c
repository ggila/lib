/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:10:00 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/18 19:21:12 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"
#include "queue.h"

#include "stdio.h"

static void	inspect_child(t_bst_node *node, t_queue *queue)
{
	if (node->left)
		push(queue, node->left);
	if (node->right)
		push(queue, node->right);
}

static void	rec_bfs(t_bst_node *node, t_queue *queue, void (*f)())
{
	t_bst_node	*next_visit;

	f(node);
	inspect_child(node, queue);
	next_visit = pop(queue);
	if (next_visit)
		rec_bfs(next_visit, queue, f);
}

void		bfs(t_bst *bst, void (*f)())
{
	t_queue	queue;

	queue_init(&queue);
	if (!bst->root)
		return;
	rec_bfs(bst->root, &queue, f);
}
