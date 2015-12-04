/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:22:01 by ggilaber          #+#    #+#             */
/*   Updated: 2015/12/04 17:43:39 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
//color = RGB W Y
//82  71  66  87  89
//format = scdfp

void	write_string(fd, char *str, char flag)
{
	write(1, str, flag ? 1 : ft_strlen(str))
}

void	write_arg(int fd, char **str, va_list args, char color)
{
	int	dec;

	if (**str > 'A' && **str < 'Z')
	{
		*color = 1;
		write_col(fd, **str);
	}
	else if (**str == 'c' || **str == 's')
		write_string(fd, va_arg(args, char*), **str == 'c');
	else if (**str == 'p')
		write_ptr(fd, va_arg(args, void*));
	else if (**str == 'd')
		ft_putnbr(fd, va_arg(args, int));
	else
		write_float(fd, va_arg(args, float),
				**str == 'f' ? 5 : read_number(str));
}
