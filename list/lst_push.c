/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:04:10 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/25 20:16:35 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>

void	lst_push_back(t_list *head, t_list *new)
{
	new->next = head;
	new->prev = head->prev;
	head->prev->next = new;
	head->prev = new;
}

void	lst_push_front(t_list *head, t_list *new)
{
	new->next = head->next;
	new->prev = head;
	head->next->prev = new;
	head->next = new;
}

struct test
{
	int n;
	t_list	lst;
};

int main(void)
{
	t_list	head;
	t_list	*it;
	struct test node0;
	struct test node1;
	struct test node2;

	LIST_HEAD(head);
	printf("&head: %p\nhead->prev: %p\nhead->next: %p\n", &head, head.prev, head.next);
	node0.n = 0;
	printf("\nlst_push_front()\n");
	lst_push_front(&head, &(node0.lst));

	node1.n = 1;
	lst_push_front(&head, &(node1.lst));

	node2.n = 2;
	lst_push_front(&head, &(node2.lst));

	printf("LIST_FOR_EACH(it, &head):\n");
	LIST_FOR_EACH(it, &head)
		printf("\n%p: LIST_ENTRY(it, struct test, lst)\nn: %d\n%p: it->prev\n%p: it->next\n"
				, LIST_ENTRY(it, struct test, lst), *(int*)LIST_ENTRY(it, struct test, lst), it->prev, it->next);

//		printf("%d\n", LIST_MEMBER(t, struct test, lst, n));

	return (0);
}
