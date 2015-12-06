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

void	my_write(int fd, const char *str, size_t len);
void	write_arg(int fd, const char **str, va_list args);
void	write_float(int fd, float x, int dec);
void	write_arg(int fd, char **str, va_list args, char color);
int		read_number(char **str);
void	ft_putnbr_fd(int fd, int n);

#endif
