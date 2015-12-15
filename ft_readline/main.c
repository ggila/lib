/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 09:49:35 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 17:59:41 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		ft_putchar_tputs(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_lineclr(char *line)
{
	int i;

	i = 0;
	while (line[i])
		line[i++] = '\0';
}

void	ft_tabcpy(char *line, char temp[], int cur)
{
	int	i;

	i = 0;
	while (line[i])
	{
		temp[i] = line[i + cur];
		i++;
	}
}
