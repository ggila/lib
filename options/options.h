/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 21:50:28 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/13 12:20:37 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_OPTIONS_H
# define CHECK_OPTIONS_H

# include <stdlib.h>

/*
** - check_options read av and set the global flag define in project header.
** - av is read until "--" or the first argument which begin with anything
** else '-'.
** - options should be listed in check_options.c
** - the project header should instanciate a global flag, exactly:
**     uint64_t   g_flag;
*/

typedef struct		s_opt
{
	char	c_opt;
	char	*str_opt;
	int		bit;
	char	*comment;
}					t_opt;

# define OPT_NULL (t_opt){0, NULL, -1, NULL}
# define IS_OPT_NULL(i) ((g_opt[i].c_opt == 0) && (g_opt[i].str_opt == NULL))

static const t_opt	g_opt[] = {{'h', "help", 0, "display this help"},
	{0, NULL, -1, NULL}};

# define MASK 0x1
# define MASK_HELP MASK<<0

/*
** check options return the number of char* of av read as options or -1
** if it fails
*/

int					check_opt(int ac, const char **av);
void				usage(const char *prog_name);
void				print_help(const char *prog_name);

#endif
