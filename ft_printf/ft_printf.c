/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 18:13:24 by ggilaber          #+#    #+#             */
/*   Updated: 2015/12/06 16:10:44 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include <stdarg.h>

void	my_write(int fd, const char *str, size_t len);
{
	if (write(fd, str, len) == -1)
		exit(KO)
}

int	ft_printfd(int fd, const char *restrict format, ...)
{
	const char	*begin;
	const char	*end;
	va_list		args;

	va_start(args, format);
	begin = format;
	while (*begin)
	{
		end = begin;
		while (*end && *end != '%' && *end != '\\')
			end++;
		my_write(fd, begin, end - begin);
		if (*end == '\0')
			break;
		*end == '\\' ? my_write(fd, ++end, 1) : write_arg(fd, &end, args);
		begin = ++end;
	}
	va_end(args);
	if (g_flag & MASK_COLOR)
		my_write(fd, WHITE, COLOR_LEN)
	return (OK);
}

int	ft_print(const char *restrict format, ...)
{
	const char	*begin;
	const char	*end;
	va_list		args;
	char		color;

	color = 0;
	va_start(args, format);
	begin = format;
	while (*begin)
	{
		end = begin;
		while (*end && *end != '%' && *end != '\\')
			end++;
		my_write(0, begin, end - begin);
		if (*end == '\0')
			break;
		*end++ == '\\' ? my_write(0, end, 1) : write_arg(0, &end, args, color);
		begin = ++end;
	}
	va_end(args);
	if (color)
		my_write(fd, WHITE, COLOR_LEN)
	return (OK);
}
