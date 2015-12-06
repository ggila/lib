/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:22:01 by ggilaber          #+#    #+#             */
/*   Updated: 2015/12/06 16:12:12 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

#include "ft_printf.h"

static void	write_string(int fd, char *str)
{
	my_write(fd, str, ft_strlen(str));
}

static void	write_char(int fd, char c)
{
	my_write(fd, &c, 1);
}

void	write_arg(int fd, const char **str, va_list args, char *color)
{
	if (**str > 'A' && **str < 'Z')
	{
		*color = 1;
		write_col(fd, **str);
	}
	else if (**str == 's')
		write_string(fd, va_arg(args, char*));
	else if (**str == 'c')
		write_char(fd, va_arg(args, int));
	else if (**str == 'p')
		write_ptr(fd, va_arg(args, void*));
	else if (**str == 'd')
		ft_putnbr_fd(fd, va_arg(args, int));
	else
		write_float(fd, (float)va_arg(args, double),
				**str == 'f' ? 5 : read_number(str));
}
