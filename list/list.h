#ifndef LIST_H
# define LIST_H

# define LIST_HEAD_INIT(name) {&(name), &(name)}
# define LIST_HEAD(name) name = LIST_HEAD_INIT(name)

typedef struct	s_list_head
{
	struct s_list_head	*prev;
	struct s_list_head	*next;
}				t_list_head;

#endif
