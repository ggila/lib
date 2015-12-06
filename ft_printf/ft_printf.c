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
	va_list		args;
	char		color;

	color = 0;
	va_start(args, format);
	my_printf(1, format, args, &color);
	va_end(args);
	if (color)
		my_write(0, WHITE, 5);
	return (OK);
}
