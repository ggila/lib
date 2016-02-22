/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:07:07 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/22 18:07:42 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

# ifndef OK
#  define OK 0
# endif
# ifndef KO
#  define KO -1
# endif

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
char	*ft_strdup(const char *s);
char	*ft_strrchr(const char *s, int c);

#endif
