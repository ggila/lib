
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_fd.c                                        :+:      :+:    :+:   */
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

void	my_printf(int fd, const char *format, va_list args, char *color)
{
	const char	*begin;
	const char	*end;

	begin = format;
	while (*begin)
	{
		end = begin;
		while (*end && *end != '%')
			end++;
		my_write(fd, begin, end - begin);
		if (*end == '\0')
			break;
		++end;
		write_arg(fd, &end, args, color);
		begin = ++end;
	}
}
