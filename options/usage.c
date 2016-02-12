/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 11:33:46 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/12 11:49:12 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options.h"
#include "printf.h"

void	print_char_opt()
{
	ft_printf("-");
	i = 0;
	while (char_opt[i].opt)
		ft_printf("%c", char_opt[i++].opt);
}

void	usage(const char *prog_name)
{
	int i;

	ft_printf("usage: %s", prog_name);
	if (char_opt[0].opt || str_opt[0].opt)
	{
		ft_printf(": [");
		if (char_opt[0].opt || str_opt[0].opt)
		i = 0;
		while (str_opt[i].opt)
			ft_printf(" --%s", char_opt[i++].opt);
		ft_printf("]");
	}
}
