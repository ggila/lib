/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 21:40:57 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/11 22:37:56 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** doc in options.h
*/

#include <stdint.h>
#include "options.h"

static const t_char_opt	char_opt[] = {{'h', MASK_HELP},
										NULL_CHAR_OPT};

static const t_str_opt	string_opt[] = {{"help", MASK_HELP},
							NULL_STR_OPT};

extern uint64_t	flag;

static void		init_hash_tbl(const t_hash_tlb *ht_char,
								const t_hash_tlb *ht_str);
{
	ht_init(ht_char, HT_CHAR_SIZE);
	ht_init(ht_str, HT_STR_SIZE);
}

int		check_opt(int ac, const char **av)
{
	t_hash_tbl	ht_char;
	t_hash_tbl	ht_str;

	init_hash_tbl(&ht_char, &ht_str);
}
char			ht_init(t_hash_tbl *const ht, int size,
char			ht_init(t_hash_tbl *const ht, int size,
					int (*key_cmp)(), unsigned long (*key_hash)());

