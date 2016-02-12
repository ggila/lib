/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 21:40:57 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/12 09:21:13 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** doc in options.h
*/

#include <stdint.h>
#include <stdlib.h>

#include "libbft.h"
#include "options.h"
#include "ft_printf.h"

extern uint64_t	g_flag;

static void	char_opt(char *arg)
{
	int i = 0;
	int j = 0;

	while (arg[i])
	{
		while (str_op[j] && (str_op[j] != arg[i]))
			j++;
		if (str_op[j])
			g_flag &= (MASK<<j);
		else
			return (KO);
		i++;
	}
	return (OK);
}

static void	str_opt(char *arg)
{
	int i = 0;

	while (str_op[i] && ft_strcmp(str_op[i], arg))
		i++;
	if (str_op[i])
		g_flag &= (MASK<<(63 - i));
	else
		return (KO);
	return (OK);
}

static char	is_option(char *arg)
{
	if ((arg[0] != '-') || (ft_strcmp(arg, "--") == 0))
		return (KO);
	return (OK);
}

int		check_opt(int ac, const char **av)
{
	i = 1;
	while (i < ac)
	{
		if (is_option(av[i]) == KO)
			break;
		if ((av[i][1] == '-' ? str_opt(av[i] + 2) :
								char_opt(av[i] + 1)) == KO)
		{
			ft_printf("%s: illegal option: %s\n", av[0], av[i]);
			usage(av[0]);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (i);
}
