/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ht.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 10:44:09 by ggilaber          #+#    #+#             */
/*   Updated: 2016/03/16 11:10:23 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdio.h>
#include "ft_printf.h"
#include "hash_tables.h"
#include "test.h"

void			test_insertion(t_hash_tbl *ht, int nb_insert)
{
	int			i;
	clock_t		begin;
	clock_t		end;
	double		time_spent;

	begin = clock();
	i = 0;
	while (i < nb_insert)
	{
		ADD_INT(ht, i, i);
		i++;
	}
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	ft_printf("\t%d -> %.7f\n", nb_insert, time_spent);
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

int				main(void)
{
	srand(time(NULL));
	insertion_routine("random", my_rand);
	insertion_routine("worst case", worst);
	insertion_routine("best case", best);
	return (0);
}
