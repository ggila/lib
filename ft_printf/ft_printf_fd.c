/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 18:13:24 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/11 20:07:41 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list		args;

	va_start(args, format);
	my_printf(fd, format, args);
	va_end(args);
	return (OK);
}
