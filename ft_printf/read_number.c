/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:52:19 by ggilaber          #+#    #+#             */
/*   Updated: 2015/12/06 16:20:59 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	my_atoi(const char **str, int n)
{
	if (**str >= '0' && **str <= '9')
	{
		n = 10 * n + **str - '0';
		(*str)++;
		return (my_atoi(str, n));
	}
	else
		return (n);
}

int			read_number(const char **str)
{
	if (**str == '-')
	{
		(*str)++;
		return (-my_atoi(str, 0));
	}
	if (**str == '+')
		(*str)++;
	return (my_atoi(str, 0));
}
