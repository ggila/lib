/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 09:39:13 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/20 17:41:48 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_H
# define BST_H

# include "stdlib.h"
# include <stdbool.h>

/*
** Do not forget to bzero t_bst at initialization
*/

typedef struct	s_bst_node
{
	int					val;
	struct s_bst_node	*left;
	struct s_bst_node	*right;
}				t_bst_node;

typedef struct	s_bst
{
	t_bst_node	*root;
	size_t		size;
}				t_bst;

/*
** For bfs and dfs, we need lists of node
*/

t_bst_node	*bst_new_node(int val);
char		bst_insert(t_bst *bst, int val);
void		bfs(t_bst *bst, void (*f)());

#endif
