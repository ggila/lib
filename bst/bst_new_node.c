/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_bst_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 09:49:22 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/18 10:56:40 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"

t_bst_node	*bst_new_node(int val)
{
	t_bst_node	*new;

	if (!(new = (t_bst_node*)malloc(sizeof(t_bst_node))))
		return (KO);
	new->value = val;
	new->left = NULL;
	new->right = NULL;
	return (OK);
}
