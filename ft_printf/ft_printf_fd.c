/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 18:13:24 by ggilaber          #+#    #+#             */
/*   Updated: 2015/12/06 16:10:44 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

#include "ft_printf.h"

int	ft_print_fd(int fd, const char *format, ...)
{
	va_list		args;
	char		color;

	color = 0;
	va_start(args, format);
	my_printf(fd, format, args, &color);
	va_end(args);
	if (color)
		my_write(fd, WHITE, 5);
	return (OK);
}
