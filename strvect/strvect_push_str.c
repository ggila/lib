/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strvect_push_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 17:45:01 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/20 18:05:43 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "strvect.h"

char	strvect_push_str(t_strvect *vect, char *str)
{
	uint32_t	len;

	len = ft_strlen(str);
	if (vect->size + len + 1 > vect->capacity)
	{
		if (_strvect_extend(vect, len) == false)
			return (false);
	}
	ft_strcat(vect->str, str);
	vect->size += len;
	vect->str[vect->size] = '\0';
	return (true);
}
