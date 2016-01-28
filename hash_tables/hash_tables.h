/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_tables.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 18:16:02 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/28 13:02:49 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLES_H
# define HASH_TABLES_H

/*
** separate chaining hash tables implemententation
** - null value are forbidden:
**       - ht_get() return null (null key means 'no node here')
**       - deletion could be implemented with node.value = NULL
** - depending on what ht.value point to, ht_free_value() should be implemented
**   in ht_free.c
*/

# define OK 0
# define KO -1

typedef struct	s_hash_node
{
	void			*key;
	void			*value;
	struct s_htnode	*next;
}				t_hash_node;

typedef struct	s_hash_tbl
{
	t_hash_node		**nodes;
	int				size;
	int				(*key_cmp)(const void *a, const void *b);
	unsigned long	(*key_hash)(const void *key);
}				t_hash_tbl;

char	ht_init(t_hash_tbl *ht, int size
			, int (*key_cmp)(const void *a, const void *b)
			,unsigned long	(*key_index)(const void *key));
char			ht_add(t_hash_tb *ht, char *str, void *value, int size);
void			*ht_get(t_hash_tbl *ht, char* str);
void			ht_free(t_hash_tbl *ht);

unsigned long	hash_djb2(const char *str);

#endif
