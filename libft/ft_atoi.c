/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:53:00 by ggilaber          #+#    #+#             */
/*   Updated: 2016/03/23 11:59:10 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	myatoi(const char *str, int n)
{
	if (*str >= '0' && *str <= '9')
	{
		n = 10 * n + *str - '0';
		str++;
		return (myatoi(str, n));
	}
	else
		return (n);
}

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r'
			|| c == '\n' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		str++;
		return (-myatoi(str, 0));
	}
	if (*str == '+')
		str++;
	return (myatoi(str, 0));
}
