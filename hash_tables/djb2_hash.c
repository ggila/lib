/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   djb2_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 18:37:06 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/26 18:45:41 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	hash_djb2(const char *str)
{
	unsigned long	hash;
	char			c;

	hash = 5381;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;
	return (hash);
}
