/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 16:06:55 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/09 09:28:58 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define OK 0
# define KO 1
# define DEFAULT_FLOAT_PRECISION 6

#include <stdarg.h>
#include <stdlib.h>

int		ft_print_fd(int fd, const char *format, ...);
int		ft_printf(const char *format, ...);
void	my_printf(int fd, const char *format, va_list args);
void	my_write(int fd, const char *str, size_t len);
void	write_float(int fd, float x, int dec);
void	write_arg(int fd, const char **str, va_list args);
void	write_ptr(int fd, void *ptr);
int		read_number(const char **str);
size_t	ft_strlen(const char *str);
void	ft_putnbr_fd(int fd, int n);
void	ft_memcpy(void *dst, void *src, size_t n);
void	ft_bzero(void *dst, size_t n);

#endif
