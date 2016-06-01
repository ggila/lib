/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 11:52:46 by ggilaber          #+#    #+#             */
/*   Updated: 2016/06/01 11:58:35 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <stdio.h>

void	my_print(void *d)
{
	printf("%d ", *(int*)d);
}

int main(void)
{
	t_queue q;
	t_queue q2;
	int a = 1;
	int b = 2;
	int c = 3;
	int z = 4;
	int u = 8;
	int v = 9;
	int w = 10;
	int x = 11;

	queue_init(&q);
	queue_init(&q2);
	queue_push(&q, &a);
	queue_push(&q2, &u);
	queue_push(&q, &b);
	queue_push(&q2, &v);
	queue_push(&q, &c);
	queue_push(&q2, &w);
	queue_push(&q, &z);
	queue_push(&q2, &x);

	queue_push_queue(&q, &q2);
	printf("print queue:\n");
	queue_print(&q, my_print);
	printf("\nqueue_pop() then print queue:\n");
	queue_pop(&q);
	queue_print(&q, my_print);
	printf("\n");
	int i = 0;
	int *d;
	while (i++ < 6)
	{
		d = queue_pop(&q);
		if (d)
			printf("%d\n", *d);
		else
			printf("NULL\n");
	}
	queue_push(&q, &a);
	queue_push(&q, &a);
	queue_push(&q, &a);
	i = 0;
	while (i++ < 6)
	{
		d = queue_pop(&q);
		if (d)
			printf("%d\n", *d);
		else
			printf("NULL\n");
	}
}
