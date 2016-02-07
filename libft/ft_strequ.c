/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 10:19:24 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/07 14:38:21 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2);

char	ft_strequ(const char *s1, const char *s2)
{
	return (!!ft_strcmp(s1, s2));
}
