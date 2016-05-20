/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 09:42:36 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/20 17:23:18 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"
#include "stdio.h"

static t_bst_node	**rec_insert(t_bst_node *node, int val)
{
	if (val < node->val)
	{
		if (node->left)
			return (rec_insert(node->left, val));
		return (&node->left);
	}
	else
	{
		if (node->right)
			return (rec_insert(node->right, val));
		return (&node->right);
	}
}

char	bst_insert(t_bst *bst, int val)
{
	t_bst_node	*new;
	t_bst_node	**place_to_insert;

	if ((new = bst_new_node(val)) == NULL)
		return (false);
	if (bst->root == NULL)
		place_to_insert = &bst->root;
	else
		place_to_insert = rec_insert(bst->root, val);
	*place_to_insert = new;
	bst->size += 1;
	return (false);
}
