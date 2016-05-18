/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 10:10:00 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/18 11:21:45 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"
#include "queue.h"

static void	inspect(t_bst_node *node, t_queue *queue)
{
	if (node->right)
		push(queue, node->right);
	if (node->left)
		push(queue, node->left);
}

static void	rec_bfs(t_bst_node *node, t_queue *queue; void (*f)())
{
	t_bst_node	*next_visit;

	f(node);
	inspect(node->left, queue);
	inspect(node->right, queue);
	next_visit = pop(queue);
	rec_bfs(next_visit);
}

void		bfs(t_bst *bst, void (*f)())
{
	t_bst_queue	queue;

	queue_init(&queue);
	if (!bst->root)
		return;
	rec_bfs(bst->root, &head, f);
}
