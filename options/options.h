/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 21:50:28 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/20 20:06:00 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_OPTIONS_H
# define CHECK_OPTIONS_H

# include <stdlib.h>

/*
** - check_options read av and set the global flag define in project header.
** - av is read until "--" or the first argument which begin with anything
** else '-'.
** - options should be listed here
** - the project header should instanciate a global flag, exactly:
**     uint32_t   g_flag;
*/

typedef struct		s_opt
{
	char	c_opt;
	char	*str_opt;
	int		bit;
	char	*comment;
	char	offset;
}					t_opt;

# define OPT_NULL (t_opt){0, NULL, -1, NULL}
# define IS_OPT_NULL(i) ((g_opt[i].c_opt == 0) && (g_opt[i].str_opt == NULL))

#define HELP_OPT_A "print all symbol table entries including stabs
#define HELP_OPT_G "print only global symbols
#define HELP_OPT_N "sort numericly rather than alphabetically
#define HELP_OPT_O "prepend file or archive element name to each line
#define HELP_OPT_P "don't sort; print in symbol table order
#define HELP_OPT_R "sort in reverse direction
#define HELP_OPT_U "print only undefined symbols
#define HELP_OPT_M "print symbol in Mach-O symbol format
#define HELP_OPT_X "print the symbol table entry in hex and the name
#define HELP_OPT_J "just print the symbol name (no value or type)
#define HELP_OPT_S "print only symbol in the following section
#define HELP_OPT_L "print a .section_start symbol if none exists (-s)"
#define HELP_OPT_F "print a dynamic shared library flat"
#define HELP_OPT_V "sort and print by value diffences ,used with -n -s"
#define HELP_OPT_B "print only stabs for the following include"
#define HELP_OPT_I "start searching for begin include at -iN index"
#define HELP_OPT_MAJA "pathname or library name of an object on each line"
#define HELP_OPT_MAJP "portable output format"

static const t_opt	g_opt[] = {{'a', "all", 0, HELP_OPT_A, NULL},
							{'g', "global", 1, HELP_OPT_G, NULL},
							{'n', "numsort", 2, HELP_OPT_N, NULL},
							{'o', "name", 3, HELP_OPT_O, NULL},
							{'p', "nosort", 4, HELP_OPT_P, NULL},
							{'r', "reverse", 5, HELP_OPT_R, NULL},
							{'u', "undef", 6, HELP_OPT_U, NULL},
							{'m', "symbformat", 7, HELP_OPT_M, NULL},
							{'x', "hex", 8, HELP_OPT_X, NULL},
							{'j', "nameonly", 9, HELP_OPT_J, NULL},
							{'s', "section", 10, HELP_OPT_S, &(g_env.flag.s)},
							{'l', NULL, 11, HELP_OPT_L, NULL},
							{'f', NULL, 12, HELP_OPT_F, NULL},
							{'v', NULL, 13, HELP_OPT_V, NULL},
							{'b', NULL, 14, HELP_OPT_B, &(g_env.flag.b)},
							{'i', NULL, 15, HELP_OPT_I, NULL},
							{'A', NULL, 16, HELP_OPT_MAJA, NULL},
							{'P', NULL, 17, HELP_OPT_MAJP, NULL},
							{'h', "help", 18, "display this help", NULL},
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
