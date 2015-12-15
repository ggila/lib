/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 19:04:58 by ggilaber          #+#    #+#             */
/*   Updated: 2015/08/25 10:48:54 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

extern int	g_prompt_size;

void		ft_del_line(int cur, char *line)
{
	while (line[cur + 1])
	{
		line[cur] = line[cur + 1];
		cur++;
	}
	line[cur] = '\0';
}

void		ft_del(int cur, char *line)
{
	char	*res;
	char	*area;
	char	b[40];

	ft_del_line(cur, line);
	area = b;
	res = tgetstr("dc", &area);
	tputs(res, 1, ft_putchar_tputs);
	if (ft_strlen(line) == g_disp.size - g_prompt_size - 1)
		g_disp.nb_line -= 1;
}

void		ft_del_pre(int *cur, char *line)
{
	char	buf[40];
	char	*area;
	char	*start;

	if (*cur)
	{
		area = buf;
		start = line;
		ft_fleche(LEFT, cur, line);
		ft_del(*cur, line);
		tputs(tgetstr("sc", &area), 1, ft_putchar_tputs);
		tputs(tgetstr("ei", &area), 1, ft_putchar_tputs);
		my_write(1, start + *cur, ft_strlen(start + *cur));
		my_write(1, " ", 1);
		tputs(tgetstr("im", &area), 1, ft_putchar_tputs);
		tputs(tgetstr("rc", &area), 1, ft_putchar_tputs);
	}
}
