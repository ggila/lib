/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 11:52:46 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/18 12:16:46 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <stdio.h>

int main(void)
{
	t_queue q;
	int a = 1;
	int b = 2;
	int c = 3;

	queue_init(&q);
	push(&q, &a);
	push(&q, &b);
	push(&q, &c);
	int i = 0;
	int *d;
	while (i++ < 6)
	{
		d = pop(&q);
		if (d)
			printf("%d\n", *d);
		else
			printf("NULL\n");
	}
	push(&q, &a);
	push(&q, &a);
	push(&q, &a);
	i = 0;
	while (i++ < 6)
	{
		d = pop(&q);
		if (d)
			printf("%d\n", *d);
		else
			printf("NULL\n");
	}
}
