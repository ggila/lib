/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 09:42:36 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/18 11:52:04 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"

static t_bst_node	**rec_insert(t_bst_node *bst, int val)
{
	if (val < bst->val)
	{
		if (bst->left)
			return (rec_insert(bst->left, val));
		return (&bst_left);
	}
	else
	{
		if (bst->right)
			return (rec_insert(bst->right, val));
		return (&bst_right);
	}
}

char	bst_insert(t_bst *bst, int val)
{
	t_bst_node	*new;
	t_bst_node	**place_to_insert;

	if ((new = bst_new_node(val)) == NULL)
		return (KO);
	if (bst->root == NULL)
		place_to_insert = &bst->root;
	else
		place_to_insert = rec_insert(bst->root, val);
	*place_to_insert = new;
	bst->size += 1;
	return (KO);
}
