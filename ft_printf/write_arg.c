/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:22:01 by ggilaber          #+#    #+#             */
/*   Updated: 2016/03/15 16:35:33 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_string(int fd, char *str)
{
	my_write(fd, str, ft_strlen(str));
}

static void	write_char(int fd, char c)
{
	my_write(fd, &c, 1);
}

void		write_arg(int fd, const char **str, va_list args)
{
	int	dec;

	if (**str == 'd')
		ft_putnbr_fd(fd, va_arg(args, int));
	else if (**str == 's')
		write_string(fd, va_arg(args, char*));
	else if (**str == 'p')
		write_ptr(fd, va_arg(args, void*));
	else if (**str == 'c')
		write_char(fd, va_arg(args, int));
	else if (**str == '%')
		my_write(1, "%", 1);
	else if (**str == 'x')
		write_hex(fd, va_arg(args, unsigned int));
	else if (**str == 'f')
		write_float(fd, (float)va_arg(args, double), DEFAULT_FLOAT_PRECISION);
	else
	{
		*str += 1;
		dec = read_number(str);
		write_float(fd, (float)va_arg(args, double), dec);
	}
}
