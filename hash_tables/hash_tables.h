/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_tables.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 18:16:02 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/09 16:18:07 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLES_H
# define HASH_TABLES_H

#include <stdlib.h>
#include "libft.h"

/*
** separate chaining hash tables implemententation:
**     - null value are forbidden:
**           - ht_get() return null if key not found
*/

# ifndef OK
#  define OK 0
# endif
# ifndef KO
#  define KO 1
# endif

typedef struct	s_kv
{
	void	*key;
	size_t	key_size;
	void	*value;
	size_t	value_size;
}				t_kv;

# define KV_NULL (t_kv){0, -1, 0, -1}

typedef struct	s_hash_node
{
	t_kv				kv;
	struct s_hash_node	*next;
}				t_hash_node;

/*
**  t_hash_tbl:
**     - **nodes and not *nodes because it makes ht_put easier
*/

typedef struct	s_hash_tbl
{
	t_hash_node		**nodes;
	size_t			size;
	int				(*key_cmp)();
	unsigned long	(*key_hash)();
}				t_hash_tbl;

/*
**  ht_init:
**     - ht
**     - size: number of nodes
**     - key_cmp: pointer to a function which compare two keys
**     - key_hash: - pointer to a function which transform key to int
**                 - {key, value} is inserted at node with index:
**                   key_hash(key) % size
*/

char			ht_init(t_hash_tbl *const ht, int size,
					int (*key_cmp)(), unsigned long (*key_hash)());

/*
**  ht_put and ht_putm:
**     - put or putm:
**         - ht_put assumes key and value are both pointer to immutable data
**         - ht_putm malloc space for key and value snd copy them
**         - Use one or the other, not both, or implement your own free func
**     - t_kv key_value
**         - here is an exemple of helping macros:
**           # define KEY_VAL(a, b) (t_kv){a, size(a), b, size(b)}
**           # define ADD(h, a, b) {t_kv k = KEY_VAL(a, b); ht_add(h, &k)}
*/

char			ht_put(t_hash_tbl *const ht, const t_kv *const key_value);
char			ht_putm(t_hash_tbl *const ht, const t_kv *const key_value);

/*
**  ht_fill:
**     - add a t_kv table to a hash table 
**     - table must end with KV_NULL
*/

void			ht_fill(t_hash_tbl *const ht, const t_kv kv_tab[]);

/*
**  ht_get:
**     - return null if key not found
*/

void			*ht_get(t_hash_tbl *ht, void *key);

/*
**  ht_getnextkv:
**     - iterate on ht
**     - return a pointer on t_kv, NULL when over
*/

void			*ht_getnextkv(t_hash_tbl *ht);

/*
**  ht_isset:
**     - return 1 or 0
*/

char			ht_isset(t_hash_tbl *ht, void *key);

/*
**  ht_free and ht_freem
**      - ht_free for ht_put
**      - ht_freem for ht_putm
*/

void			ht_free(t_hash_tbl *ht);
void			ht_freem(t_hash_tbl *ht);

/*
**  ht_print 
*/

void		ht_print(t_hash_tbl *ht, void (*key_print)(),
				void (*value_print)());

/*
**  key_string:
**     - key_cmp: ft_strcmp
**     - key_hash: hash_djb2
*/

int				ft_strcmp(const char *s1, const char *s2);
unsigned long	hash_djb2(const char *str);
void			str_print(const char *str);

/*
**  key_int:
*/

int				int_cmp(const int *a, const int *b);
unsigned long	int_hash(const int *i);
void			int_print(const int *i);

#endif
