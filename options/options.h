/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 21:50:28 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/11 22:37:05 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_OPTIONS_H
# define CHECK_OPTIONS_H

/*
** - check_options read av and set the global flag define in project header.
** - av is read until "--" or the first argument which begin with anything
** else '-'.
** - options should be listed in check_options.c
** - the project header should instanciate a global flag, exactly:
**     uint64_t   g_flag;
*/


# include "hash_tables.h"

# define MASK 0x1
# define MASK_HELP MASK<<0

typedef struct	s_char_opt
{
	char			c;
	unsigned int	mask;
}				t_char_opt;

# define NULL_CHAR_OPT (t_char_opt){0, 0}
# define HT_CHAR_SIZE 5

typedef struct	s_str_opt
{
	char			*str;
	unsigned int	mask;
}				t_str_opt;

# define NULL_STR_OPT (t_str_opt){NULL, 0}
# define HT_STR_SIZE 5

/*
** check options return the number of char* of av read as options or -1
** if it fails
*/

int		check_opt(int ac, const char **av);

#endif
