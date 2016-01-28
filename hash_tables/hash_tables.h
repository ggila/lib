/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_tables.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 18:16:02 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/28 23:59:15 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLES_H
# define HASH_TABLES_H

# define KEY_VAL(a, b) (t_kv){a, size(a), b, size(b)}
# define ADD(h, a, b) {t_kv k = KEY_VAL(a, b); ht_add(h, &k)}

/*
** separate chaining hash tables implemententation
** - null value are forbidden:
**       - ht_get() return null if key not found (null key means 'no node here')
*/

# define OK 0
# define KO -1

typedef struct	s_kv
{
	void	*key;
	size_t	key_size;
	void	*value;
	size_t	value_size;
}				t_kv;

typedef struct	s_hash_node
{
	t_kv			*kv;
	struct s_htnode	*next;
}				t_hash_node;

typedef struct	s_hash_tbl
{
	t_hash_node		**nodes;
	size_t				size;
	int				(*key_cmp)(const void *a, const void *b);
	unsigned long	(*key_hash)(const void *key);
}				t_hash_tbl;

char			ht_init(t_hash_tbl *ht, int size
					, int (*key_cmp)(const void *a, const void *b)
					, unsigned long (*key_index)(const void *key));
char			ht_put(t_hash_tb *ht, t_kv key_value);
char			ht_putm(t_hash_tb *ht, t_kv key_value);
void			*ht_get(t_hash_tbl *ht, void *key);
void			ht_free(t_hash_tbl *ht);

unsigned long	hash_djb2(const char *str);

#endif
