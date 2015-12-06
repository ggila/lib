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


#include <stdarg.h>
#include <stdlib.h>

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
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
		my_write(1, begin, end - begin);
		if (*end == '\0')
			break;
		*end++ == '\\' ? my_write(1, end, 1)
						: write_arg(1, &end, args, &color);
		begin = ++end;
	}
	va_end(args);
	if (color)
		my_write(1, WHITE, 5);
	return (OK);
}
