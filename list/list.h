/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 10:11:50 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/13 12:15:54 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stddef.h>

typedef struct	s_list
{
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

# define LIST_HEAD_INIT(name) (t_list){&(name), &(name)}
# define LIST_HEAD(name) (name = LIST_HEAD_INIT(name))

# define LIST_FOR_EACH(p, h) for (p = (h)->next; p != (h); p = p->next)

/*
** ----
** struct objet
** {
**     int n1;
**     t_list list;
**     char c1;
**     char c2;
** }
** ----
** LIST_ENTRY(ptr, type, member)  --------->  +----------------------+
**                                            |                      |
**                                            |     struct object    |
**                           type ------------+----|_____________|   |
**                                            |                      |
**                                            | +------------------+ |
**                                            | |      int n1      | |
**                                            | +------------------+ |
**                            ptr ----------> | +------------------+ |
**                                            | |    t_list list   | |
**                     lst_member ------------+-+--------->|____|  | |
**                                            | +------------------+ |
**                                            | +------------------+ |
**                                            | |      char c1     | |
**                                            | +------------------+ |
**  LIST_MEMBER(ptr, type, member, wanted) -> | +------------------+ |
**                                            | |      char c2     | |
**                         member ------------+-+--------->|__|    | |
**                                            | +------------------+ |
**                                            |                      |
**                                            +----------------------+
** ----
*/

# define LIST_ENTRY(ptr, type, lst_member) \
				(type*)((char*)ptr - offsetof(type, lst_member))

# define LIST_MEMBER(ptr, type, lst_member, wanted) \
				*(typeof(&(((type*)0)->wanted))) \
					((char*)ptr -offsetof(type, lst_member) + offsetof(type, wanted))

void			lst_push_back(t_list *head, t_list *new);
void			lst_push_front(t_list *head, t_list *new);

#endif
