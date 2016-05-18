/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 09:39:13 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/18 11:25:14 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_H
# define BST_H

#include "stdlib.h"

/*
** Do not forget to bzero t_bst at initialization
*/

# ifndef OK
#  define OK 0
# endif
# ifndef KO
#  define KO 1
# endif

typedef struct	s_bst_node
{
	int					value;
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

t_bst_node	*bst_new_node(t_bst *bst, int val);
char		bst_insert(int val);
void		bfs(t_bst *bst, void (*f)());

#endif
