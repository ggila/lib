/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strvect.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 15:53:39 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/20 17:06:48 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRVECT_H
# define STRVECT_H

#include <stdint.h>

# ifndef OK
#  define OK 0
# endif
# ifndef KO
#  define KO 1
# endif

/*
** Do not forget to:
**     - call strvect_init(*vect) after declaration
**     - free vect.str
*/

typedef struct	s_strvect
{
	char		*str;
	uint32_t	size;
	uint32_t	capacity;
}				t_strvect;

/*
** API
*/

char	strvect_init(t_strvect *vect);
char	strvect_push_char(t_strvect *vect, char c);

/*
** Todo:
** char    strvect_push_str(t_strvect *vect, char *str);
*/


/*
** Internals
*/

char	_strvect_extend(t_strvect *vect);

/*
** This implementation does not manage of a decreasing string
** Todo
** char _strvect_reduce(t_strvect vect);
*/

#endif
