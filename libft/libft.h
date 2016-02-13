/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:07:07 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/13 12:09:22 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

/*
**		ft_mem
*/

void	ft_bzero(void *dst, size_t n);
void	ft_memcpy(void *dst, const void *src, size_t n);

/*
**		ft_str
*/

char	ft_strequ(const char *s1, const char *s2);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);

#endif
