/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 12:10:44 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/13 12:12:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>

struct test
{
	int n;
	t_list	lst;
	t_list	lst2;
};

int main(void)
{
	t_list	head;
	t_list	head2;
	t_list	*it;
	struct test node0;
	struct test node1;
	struct test node2;

	LIST_HEAD(head);
	LIST_HEAD(head2);
	printf("&head: %p\nhead->prev: %p\nhead->next: %p\n", &head, head.prev, head.next);
	node0.n = 0;
	printf("\nlst_push_front()\n");
	lst_push_front(&head, &(node0.lst));
	lst_push_back(&head2, &(node0.lst2));

	node1.n = 1;
	lst_push_front(&head, &(node1.lst));
	lst_push_back(&head2, &(node1.lst2));

	node2.n = 2;
	lst_push_front(&head, &(node2.lst));
	lst_push_back(&head2, &(node2.lst2));

	printf("LIST_FOR_EACH(it, &head):\n");
	LIST_FOR_EACH(it, &head)
		printf("\n%p: LIST_ENTRY(it, struct test, lst)\nn: %d\n%p: it->prev\n%p: it->next\n"
				, LIST_ENTRY(it, struct test, lst), *(int*)LIST_ENTRY(it, struct test, lst), it->prev, it->next);
	printf("\n");

	printf("LIST_FOR_EACH(it, &head2):\n");
	LIST_FOR_EACH(it, &head2)
		printf("\n%p: LIST_ENTRY(it, struct test, lst)\nn: %d\n%p: it->prev\n%p: it->next\n"
				, LIST_ENTRY(it, struct test, lst2), *(int*)LIST_ENTRY(it, struct test, lst2), it->prev, it->next);
	printf("\n");


		printf("%d\n", LIST_MEMBER(head.next, struct test, lst, n));
//		printf("%p\n%p\n", ((char*)head.next -offsetof(struct test, lst) + offsetof(struct test, n)), &(node2.n));

	return (0);
}
