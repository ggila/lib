/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:52:19 by ggilaber          #+#    #+#             */
/*   Updated: 2015/12/04 17:56:35 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	myatoi(const char **str, int n)
{
	if (**str >= '0' && **str <= '9')
	{
		n = 10 * n + **str - '0';
		(*str)++;
		return (myatoi(*str, n));
	}
	else
		return (n);
}

int			read_number(char **str)
{
	if (**str == '-')
	{
		(*str)++;
		return (-myatoi(str, 0));
	}
	if (**str == '+')
		(*str)++;
	return (myatoi(str, 0));
}
