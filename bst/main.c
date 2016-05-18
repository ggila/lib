/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 16:43:44 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/18 19:37:42 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.h"
#include <stdio.h>

void	a(t_bst_node *b)
{
	printf("%i\n", b->val);
}

int main(void)
{
	t_bst	bst;

	bst.root = NULL;
	bst.size = 0;
	bst_insert(&bst, 7);
	bst_insert(&bst, 3);
	bst_insert(&bst, 11);
	bst_insert(&bst, 15);
	bst_insert(&bst, 23);
	bst_insert(&bst, 5);
	bst_insert(&bst, 9);
	bfs(&bst, a);
}
