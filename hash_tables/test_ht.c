/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ht.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 10:44:09 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/26 16:47:00 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdio.h>
#include "ft_printf.h"
#include "hash_tables.h"
#include "test.h"

void			test_insertion(t_hash_tbl *ht, int nb_insert)
{
	int				i;
	clock_t			begin;
	clock_t			end;

	begin = clock();
	i = 0;
	while (i < nb_insert)
	{
		ADD_INT(ht, i, i);
		i++;
	}
	end = clock();
	ft_printf("\t%d -> %.7f\n", nb_insert,
			(double)(end - begin) / CLOCKS_PER_SEC);
}

void			insertion_routine(char *mess, unsigned long (*hash_func)())
{
	t_hash_tbl	ht;
	int			*nb_ins;
	int			i;
	int			size;

	ft_printf("%s:\n", mess);
	nb_ins = ft_strcmp(mess, "worst case") ? TAB : WORST_TAB;
	size = ft_strcmp(mess, "worst case") ? 6 : 4;
	i = 0;
	while (i < size)
	{
		ht_init(&ht, 2 * nb_ins[i], int_cmp, hash_func);
		test_insertion(&ht, nb_ins[i]);
		ht_freem(&ht);
		i++;
	}
	ft_printf("--------------\n", mess);
}

void			basic_insertion(t_hash_tbl *ht, int nb_insert)
{
	int				i;

	i = 0;
	while (i < nb_insert)
	{
		ADD_INT(ht, i, i);
		i++;
	}
}

void			test_basic(void)
{
	t_hash_tbl	ht;

	ht_init(&ht, 2 * 5, int_cmp, my_rand);
	basic_insertion(&ht, 5);
	ht_print(&ht, int_print, int_print);
	ht_freem(&ht);
}

int				main(void)
{
	srand(time(NULL));
	test_basic();
//	ft_printf("Test hash_tables.a\n"
//			"(mind that worst case has two less test)\n\n");
//	insertion_routine("random", my_rand);
//	insertion_routine("worst case", worst);
//	insertion_routine("best case", best);
	return (0);
}
