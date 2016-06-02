/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 18:16:02 by ggilaber          #+#    #+#             */
/*   Updated: 2016/06/02 16:17:23 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_H
# define SET_H

# include "libft.h"

# include <stdbool.h>
# include <stdlib.h>

/*
** set implementation, adaption of my hash tables implemententation
** (in ../hash_tables):
*/

typedef struct	s_set_node
{
	void				*elem;
	size_t				size;
	struct s_set_node	*next;
}				t_set_node;

/*
**  t_set:
**     - **elem and not *elem because:
**           - we don't want to malloc all space, not necessarly needed
**           - it makes set_put easier
**     - size should be two times the expected number of element :
**           - probes for search hit ~= 3/2
**           - probes for miss->insertion hit ~= 5/2
*/

typedef struct	s_set
{
	t_set_node		**nodes;
	size_t			nb_nodes;
	size_t			size;
	int				(*elem_cmp)();
	unsigned long	(*elem_hash)();
}				t_set;

/*
**  set_init:
**     - set
**     - size: number of nodes
**     - elem_cmp: pointer to a function which compare two keys
**     - elem_hash: - pointer to a function which transform elem to int
**                  - elem is inserted at node with index:
**                    elem_hash(key) % size
*/

bool			set_init(t_set *const set, int size,
					int (*elem_cmp)(), unsigned long (*elem_hash)());

/*
**  set_put and set_putm:
**     - put or putm:
**         - set_put assumes elem is a pointer to immutable data
**         - set_putm malloc space for elem and copy it
**         - Use one or the other, not both, or implement your own free func
*/

bool			set_put(t_set *const set, void *const elem);
bool			set_putm(t_set *const set, void *const elem, size_t size);

/*
**  set_getnextelem:
**     - iterate on set
**     - return a pointer on elem
**
** BE CAREFULL using this function. Static are used in it. To be redone with
** something like:
** struct         set_it
** {
**      int       bucket;
**      set_node  *node;
** }
*/

void			*set_getnextelem(t_set *set);

/*
**  set_isset:
**     - return 1 or 0
*/

bool			set_isin(t_set *set, void *elem);

/*
**  set_free and set_freem
**      - set_free for set_put
**      - set_freem for set_putm
*/

void			set_free(t_set *set);
void			set_freem(t_set *set);

/*
**  set_print
*/

void			set_print(t_set *set, void (*elem_print)());

/*
**  set_copy
*/

t_set			*set_copy(t_set *set);

/*
**  elem_string:
**     - elem_cmp: ft_strcmp
**     - elem_hash: hash_djb2
*/

int				ft_strcmp(const char *s1, const char *s2);
unsigned long	hash_djb2(const char *str);

/*
**  elem_int:
*/

int				int_cmp(const int *a, const int *b);
unsigned long	int_hash(const int *i);

#endif
