/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 21:50:28 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/12 09:19:20 by ggilaber         ###   ########.fr       */
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

typdef struct	s_char_opt
{
	char	opt;
	char	*comment;
}				t_char_opt;

typdef struct	s_str_opt
{
	char	*opt;
	char	*comment;
}				t_str_opt;

static const t_char_opt char_opt[] = {{'h', "display this help"},
										{0, NULL}};

static const t_str_opt str_opt[] = {{"help", "display this help"},
										{NULL, NULL}};

# define MASK 0x1
# define MASK_HELP MASK<<0
# define MASK_HELP MASK<<63

/*
** check options return the number of char* of av read as options or -1
** if it fails
*/

int		check_opt(int ac, const char **av);
void	usage(const char *prog_name);
void	print_help(const char *prog_name);

#endif
