/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 16:06:55 by ggilaber          #+#    #+#             */
/*   Updated: 2015/12/06 16:15:02 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define OK 0
# define KO 1

# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"
# define WHITE "\033[37m"

#include <stdarg.h>

void	my_write(int fd, const char *str, size_t len);
void	write_float(int fd, float x, int dec);
void	write_arg(int fd, const char **str, va_list args, char *color);
int		read_number(const char **str);
void	ft_putnbr_fd(int fd, int n);
void	write_col(int fd, char c);

#endif
