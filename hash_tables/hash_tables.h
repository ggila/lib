/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_tables.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 18:16:02 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/05 09:21:05 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLES_H
# define HASH_TABLES_H

# define KEY_VAL(a, b) (t_kv){a, size(a), b, size(b)}
# define ADD(h, a, b) {t_kv k = KEY_VAL(a, b); ht_add(h, &k)}

/*
** separate chaining hash tables implemententation:
**     - null value are forbidden:
**           - ht_get() return null if key not found
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
	size_t			size;
	int				(*key_cmp)(const void *a, const void *b);
	unsigned long	(*key_hash)(const void *key);
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

char			ht_init(const t_hash_tbl ht, const int size
					, int (*key_cmp)(const void *a, const void *b)
					, unsigned long (*key_hash)(const void *key));

/*
**  ht_put and ht_putm:
**     - ht_put assumes key and value are both pointer to immutable data
**     - ht_putm malloc space for key and value snd copy them
**     - Use one or the other, not both, or implement your own free func
*/

char			ht_put(t_hash_tbl *ht, t_kv key_value);
char			ht_putm(t_hash_tbl *ht, t_kv key_value);

/*
**  ht_get:
**     - return null if key not found
*/

void			*ht_get(t_hash_tbl *ht, void *key);

/*
**  ht_free and ht_freem
**      - ht_free for ht_put
**      - ht_freem for ht_putm
*/

void			ht_free(t_hash_tbl *ht);
void			ht_freem(t_hash_tbl *ht);

/*
** key_string:
**     - key_cmp: ft_strcmp
**     - key_hash: hash_djb2
*/

unsigned long	hash_djb2(const char *str);
int				ft_strcmp(const char *s1, const char *s2);

/*
** key_int:
*/

int				int_cmp(int *a, int *b);
int				int_hash(int i);

#endif
