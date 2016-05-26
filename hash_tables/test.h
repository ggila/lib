/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:00:08 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/26 16:15:00 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# define INT_KEY_VAL(a, b) (t_kv){a, 4, b, 4}
# define DEF(a, b) int c = a; int d = b;
# define ADD_INT(h, a, b) {DEF(a,b);t_kv k=INT_KEY_VAL(&c,&d); ht_putm(h,&k);}

# define TAB (int[]){10, 100, 1000, 10000, 100000, 1000000}
# define WORST_TAB (int[]){10, 100, 1000, 10000}

unsigned long	worst(void);
unsigned long	best(int *i);
unsigned long	my_rand(void);

#endif
