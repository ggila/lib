/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 21:40:57 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/13 12:19:59 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** doc in options.h
*/

#include <stdint.h>
#include <stdlib.h>

#include "libft.h"
#include "options.h"
#include "ft_printf.h"

extern uint64_t	g_flag;

static char	check_char_opt(const char *arg)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (arg[i])
	{
		while (!IS_OPT_NULL(i) && (g_opt[j].c_opt != arg[i]))
			j++;
		if (g_opt[j].c_opt)
			g_flag &= MASK << g_opt[j].bit;
		else
			return (KO);
		i++;
	}
	return (OK);
}

static char	check_str_opt(const char *arg)
{
	int	i;

	i = 0;
	while (!IS_OPT_NULL(i) && g_opt[i].str_opt &&
			ft_strcmp(g_opt[i].str_opt, arg))
		i++;
	if (g_opt[i].str_opt)
		g_flag &= MASK << g_opt[i].bit;
	else
		return (KO);
	return (OK);
}

static char	is_option(const char *arg)
{
	if ((arg[0] != '-') || (ft_strcmp(arg, "--") == 0))
		return (KO);
	return (OK);
}

int			check_opt(int ac, const char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (is_option(av[i]) == KO)
			break ;
		if ((av[i][1] == '-' ? check_str_opt(av[i] + 2) :
								check_char_opt(av[i] + 1)) == KO)
		{
			ft_printf("%s: illegal option: %s\n", av[0], av[i]);
			usage(av[0]);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (i);
}
