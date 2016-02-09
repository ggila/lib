/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 08:31:43 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/09 09:48:33 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include "ft_printf.h"

void	ft_fill_buf(int n, char **str)
{
	if (n > 9)
	{
		ft_fill_buf(n / 10, str);
		*str += 1;
		printf("%p\n", *str);
		ft_fill_buf(n % 10, str);
	}
	else
		**str = '0' + n;
}

void	ft_putnbr_fd(int fd, int n)
{
	char	buf[11];
	char	*str;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return;
	}
	str = buf;
	ft_bzero(str, 11);
	if (n < 0)
	{
		*str++ = '-';
		n *= -1;
	}
	ft_fill_buf(n, &str);
	my_write(fd, buf, ++str - buf);
	printf("\n%lu\n", str - buf);
}
