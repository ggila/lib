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
**     char c1;
**     int n1;
**     char c2;
**     t_list list;
** }
** ----
** LIST_ENTRY(ptr, type, member)  --------->  +----------------------+
**                                            |                      |
**                                            |     struct object    |
**                           type ------------+----|_____________|   |
**                                            |                      |
**                                            | +------------------+ |
**                                            | |      char c1     | |
**                                            | +------------------+ |
**  LIST_MEMBER(ptr, type, member, wanted) -> | +------------------+ |
**                                            | |      int n1      | |
**                         wanted ------------+-+-------->|__|     | |
**                                            | +------------------+ |
**                                            | +------------------+ |
**                                            | |      char c2     | |
**                                            | +------------------+ |
**                            ptr ----------> | +------------------+ |
**                                            | |    t_list list   | |
**                         member ------------+-+--------->|____|  | |
**                                            | +------------------+ |
**                                            |                      |
**                                            +----------------------+
** ----
*/

# define LIST_ENTRY(ptr, type, member) \
				(type*)((char*)ptr - offsetof(type, member))

# define LIST_MEMBER(ptr, type, member, wanted) \
	*(typeof(((type*)0->wanted))*)(LIST_ENTRY(ptr, type, member) + offsetof(type, wanted))

void			lst_add(t_list *head, t_list *new);

#endif
