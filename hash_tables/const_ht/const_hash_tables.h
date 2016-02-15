/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_hash_tables.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 18:16:02 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/13 19:42:57 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLES_H
# define HASH_TABLES_H

# include <stdlib.h>
# include "libft.h"

/*
** separate chaining hash tables implemententation:
** - no malloc
**
** -> read const_ht.c
*/

# ifndef OK
#  define OK 0
# endif
# ifndef KO
#  define KO 1
# endif

/*
** those tokens should be replace:
** <n> : name
** <kt> : key type
** <vt> : value type
** <s> : number of key/value
**
*/

#define DATA_<N>_SIZE <ds>
#define HT_<N>_SIZE <htss>

/*
** typdef fot key_value
**
** <kt> and <vt> must be const !
*/

typedef <kt> t_<n>_key;
typedef <vt> t_<n>_val;

/*
** typedef for node
*/

typedef struct	s_<n>_node
{
	t_<n>_key	*key;
	t_<n>_val	*val;
}				t_<n>_node

typedef struct			s_<n>_data
{
	t_<n>_key		key;
	t_<n>_val		val;
}						t_<n>_data;

/*
** typedef for htab
*/

typedef struct s_<n>_ht
{
	t_<n>_data	data[<ds>]
	t_<n>_node	node[<hts>];
}

/*
** struct_const_key_value
*/

typedef struct	s_<n>
{
	const t_<n>_key		*key;
	const t_<n>_value	*value;
}				t_<n>;

typedef struct	s_<n>_data
{
	const t_<n>_key		key;
	const t_<n>_value	value;
}				t_<n>_data;

/*
**
*/

/*
** struct {node, node->next}
*/

typedef struct	s_const_hash_node
{
	t_ckv						ckv;
	struct s_const_hash_node	*next;
}				t_hash_node;

/*
**  t_const_hash_tbl:
**     - **nodes: pointer to 
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

void			ht_print(t_hash_tbl *ht, void (*key_print)(),
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

/*
**    to-do: insert ht_get in ht_put, such as in:
**    
**    char *strdup(char *);
**    // install: put (name, defn) in hashtab
**    struct nlist *install(char *name, char *defn)
**    {
**        struct nlist *np;
**        unsigned hashval;
**        if ((np = lookup(name)) == NULL) { // not found 
**            np = (struct nlist *) malloc(sizeof(*np));
**            if (np == NULL || (np->name = strdup(name)) == NULL)
**              return NULL;
**            hashval = hash(name);
**            np->next = hashtab[hashval];
**            hashtab[hashval] = np;
**        } else // already there
**            free((void *) np->defn); //free previous defn
**        if ((np->defn = strdup(defn)) == NULL)
**           return NULL;
**        return np;
**    }
*/
