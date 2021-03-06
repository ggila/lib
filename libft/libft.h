/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:07:07 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/20 17:42:22 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
char	ft_islowercase(char c);
char	ft_isuppercase(char c);
char	ft_isdigit(char c);
char	ft_isletter(char c);
char	ft_isalnum(char c);

/*
**		ft_mem
*/

void	ft_bzero(void *dst, size_t n);
void	ft_memcpy(void *dst, const void *src, size_t n);
void	ft_memset(void *dst, int c, size_t len);

/*
**		ft_str
*/

char	ft_strequ(const char *s1, const char *s2);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strrchr(const char *s, int c);
int		ft_strcount(char *str, char c);
char	*ft_strcat(char *s1, const char *s2);
char	**ft_strsplit(char const *s, char c);

#endif
