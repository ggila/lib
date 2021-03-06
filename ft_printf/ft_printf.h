/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 16:06:55 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/29 21:06:31 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define DEFAULT_FLOAT_PRECISION 6

# include "libft.h"

# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>

int		ft_printf_fd(int fd, const char *format, ...);
int		ft_printf(const char *format, ...);
void	my_printf(int fd, const char *format, va_list args);
void	my_write(int fd, const char *str, size_t len);
void	write_float(int fd, float x, int dec);
void	write_arg(int fd, const char **str, va_list args);
void	write_ptr(int fd, void *ptr);
void	write_hex(int fd, unsigned int nb);
int		read_number(const char **str);
size_t	ft_strlen(const char *str);
void	ft_putnbr_fd(int fd, int n);
void	str_print(const char *str);
void	int_print(const int *i);

#endif
