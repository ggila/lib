/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_tables.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 18:16:02 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/26 21:01:46 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLES_H
# define HASH_TABLES_H

# define SIZE

typedef struct	s_htnode
{
	char			*key;
	void			*value;
	struct s_htnode	*next;
}				t_htnode;

unsigned long	hash_djb2(char *str);
char			ht_add(t_htnode hasht[], char *str, void *value);
void			*ht_get(t_htnode hasht[], char* str);
void			ht_free(t_htnode hasht[]);

#endif
