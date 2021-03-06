/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 21:40:57 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/20 17:22:47 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** doc in options.h
*/

#include "ft_printf.h"
#include "libft.h"
#include "nm.h"
#include "options.h"

#include <stdint.h>
#include <stdlib.h>

static char	check_char_opt(const char *arg, t_nm_flag *flag)
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
			flag->flag &= MASK << g_opt[j].bit;
		else
			return (false);
		i++;
	}
	return (true);
}

static char	check_str_opt(const char *arg, t_nm_flag *flag)
{
	int	i;

	i = 0;
	while (!IS_OPT_NULL(i) && g_opt[i].str_opt &&
			ft_strcmp(g_opt[i].str_opt, arg))
		i++;
	if (g_opt[i].str_opt)
		flag->flag &= MASK << g_opt[i].bit;
	else
		return (false);
	return (true);
}

static char	is_option(const char *arg)
{
	if ((arg[0] != '-') || (ft_strcmp(arg, "-") == 0))
		return (false);
	return (true);
}

int			check_opt(int ac, const char **av, t_nm_flag *flag)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "--") == 0)
			return (i + 1);
		if (is_option(av[i]) == false)
			break ;
		if ((av[i][1] == '-' ? check_str_opt(av[i] + 2, flag) :
								check_char_opt(av[i] + 1, flag)) == false)
		{
			ft_printf("%s: illegal option: %s\n", av[0], av[i]);
			usage(av[0]);
			return (false);
		}
		i++;
	}
	return (i);
}
