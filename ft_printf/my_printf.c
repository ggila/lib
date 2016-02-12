/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 18:13:24 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/12 19:27:29 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	my_printf(int fd, const char *format, va_list args)
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
			break ;
		++end;
		write_arg(fd, &end, args);
		begin = ++end;
	}
}
