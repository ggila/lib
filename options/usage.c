/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 11:33:46 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/13 12:20:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options.h"
#include "ft_printf.h"

#define ARGS ""

void	print_opt(void)
{
	int		i;
	t_opt	o;

	i = 0;
	ft_printf("\n");
	i = 0;
	while (!IS_OPT_NULL(i))
	{
		o = g_opt[i];
		if (o.c_opt)
		{
			ft_printf("-%c", o.c_opt);
			if (o.str_opt)
				ft_printf(", ");
		}
		if (o.str_opt)
			ft_printf("--%s", o.str_opt);
		ft_printf(": %s", o.comment);
	}
	ft_printf("\n");
}

void	usage(const char *prog_name)
{
	ft_printf("usage: %s", prog_name);
	if (!IS_OPT_NULL(0))
		ft_printf(" [<options>] [--]");
	ft_printf(" %s\n", ARGS);
	if (!IS_OPT_NULL(0))
		print_opt();
}
