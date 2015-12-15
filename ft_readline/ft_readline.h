/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 09:49:41 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 14:50:03 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READLINE_H
# define FT_READLINE_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <termios.h>
# include <term.h>
# include <fcntl.h>

# define SET_BLACK write(1, "\033[1;30m", 7)
# define SET_BLUE write(1, "\033[1;34m", 7)
# define SET_WHITE write(1, "\033[1;37m", 7)

# define OK 0
# define KO 1

# define UP 65
# define DOWN 66
# define RIGHT 67
# define LEFT 68

# define PATH 0
# define DI 1
# define FIL 2

# define MASK 1U
# define MASK_ENV_I MASK<<0

typedef struct	s_screen
{
	int				size;
	int				cur_line;
	int				nb_line;
	int				cur_lines;
	int				nb_lines;
	int				pos;
}				t_screen;

typedef struct	s_hll
{
	struct s_hll	*p;
	struct s_hll	*n;
	char			*line;
}				t_hll;


char			g_readline_flag;
t_hll			*g_hist;
t_screen		g_disp;


//main
int		ft_putchar_tputs(int c);
void	ft_tabcpy(char *line, char temp[], int cur);
void	ft_prompt(void);
void	ft_edit_init(int *cur);
void	ft_lineclr(char *line);
//init.c
void	ft_init_term(void);
void	ft_init_hist(void);
void	ft_init_screen(void);
void	ft_init(void);
//ft_get_cmd.c
void			ft_get_cmd(char line[]);
//key_map.c
int		ft_is_map(char c);
void	ft_map(char *buf, int *cur, char *line);
//hist.c
void	ft_save_hist(char *line);
void	ft_free_hist(void);
//flech.c
void	ft_fleche(char c, int *cur, char *line);
void	ft_hist(char c, int *cur, char *line);
//line_del
void	ft_del(int cur, char *line);
void	ft_del_pre(int *cur, char *line);
//line_insert
void	ft_insert(char *line, char c, int *cur);
//screen_insert
void	ft_screen_insert(char c, char *line);
//update_pos.c
void	ft_update_screen_insert_pos(int len);
//move_cur.c
void	ft_go_upright(void);
void	ft_go_downleft(void);
//quit.c
void	ft_error(char *str);
void	ft_quit_ok(void);
void	ft_restore_term(void);
//lib.c
char	*ft_strdup(const char *str);
int		ft_strlen(const char *str);

#endif
