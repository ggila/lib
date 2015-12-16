/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 09:49:35 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 17:59:41 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

struct termios			g_term;
struct termios			g_term_init;
extern int				g_prompt_size;

void		ft_init_term(void)
{
	char	buf[2048];
	char	buf2[40];
	char	*res;
	char	*area;

	tgetent(buf, getenv("TERM"));
	tcgetattr(0, &g_term);
	g_term_init = g_term;
	g_term.c_lflag &= ~(ICANON);
	g_term.c_lflag &= ~(ECHO);
	g_term.c_cc[VMIN] = 1;
	g_term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &g_term);
	area = buf2;
	res = tgetstr("im", &area);
	tputs(res, 1, ft_putchar_tputs);
}

void	ft_edit_init(int *cur)
{
	*cur = 0;
	g_disp.pos = g_prompt_size;
	g_disp.cur_line = 1;
	g_disp.nb_line = 1;
}

void	ft_init_hist(void)
{
	if (!(g_hist = (t_hll*)malloc(sizeof(t_hll))))
		exit (0);
	g_hist->line = NULL;
	g_hist->p = NULL;
	g_hist->n = NULL;
}

void	ft_init_screen(void)
{
	g_disp.size = tgetnum("co");
	g_disp.cur_line = 1;
	g_disp.nb_line = 1;
	g_disp.pos = 0;
}

void		ft_init(void)
{
	struct sigaction	sig;

	ft_init_term();
	ft_init_hist();
	ft_init_screen();
	sig.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sig, NULL);
}
