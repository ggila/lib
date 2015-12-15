/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 09:49:35 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 17:59:41 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int g_prompt_size;

static void	get_usr(char usr[4])
{
	ft_memcpy(usr, "user", 4);
}

static void	get_home(char home[5])
{
	ft_memcpy(home, "tesst", 4);
}

static void	sub_home(char *buf, int home_size)
{
}

void	ft_prompt(void)
{
	char	buf[1000];
	char	usr[4];
	char	home[5];

	get_usr(usr);
	get_home(home);
	SET_BLUE;
	my_write(1, usr, ft_strlen(usr));
	SET_WHITE;
	my_write(1, " in ", 4);
	SET_BLUE;
	getcwd(buf, 1000);
	if (ft_strncmp(home, buf, ft_strlen(home)))
		sub_home(buf, ft_strlen(home));
	my_write(1, buf, ft_strlen(buf));
	my_write(1, " ", 1);
	SET_BLACK;
	g_prompt_size = ft_strlen(usr) + ft_strlen(buf) + 5;
}
