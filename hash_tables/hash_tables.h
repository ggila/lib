/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_tables.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 18:16:02 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/27 18:25:39 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLES_H
# define HASH_TABLES_H

/*
** separate chaining hash tables implemententation
** - null value are forbidden:
**       - ht_get() return null (null key means 'no node here')
**       - deletion could be implemented with node.value = NULL
** - hash tables should be initialize to 0 right after its declaration
** - depending on what value point to, ht_free_value() should be implemented in
**   ht_free.c
*/

typedef struct	s_htnode
{
	void			*key;
	void			*value;
	struct s_htnode	*next;
}				t_htnode;

typedef struct	s_hash_tbl
{
	t_htnode		**nodes;
	int				(*key_cmp)(const void *a, const void *b);
	unsigned long	(*key_index)(const void *key);
}

unsigned long	hash_djb2(const char *str);
char			ht_add(t_htnode hasht[], char *str, void *value);
void			*ht_get(t_htnode hasht[], char* str);
void			ht_free(t_htnode hasht[]);

#endif
