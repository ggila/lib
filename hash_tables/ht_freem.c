<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:53:48 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/05 09:55:26 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"
#include <stdlib.h>

void	ht_freem(t_hash_tbl *ht)
{
	int	i;

	i = 0;
	while (i < ht->size)
		free(ht->nodes[i++]);
}
||||||| merged common ancestors
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:53:48 by ggilaber          #+#    #+#             */
/*   Updated: 2016/02/05 09:22:04 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"
#include <stdlib.h>

void	ht_freem(t_hash_tbl *ht)
{
	int	i;

	i = 0;
	while (i < ht[i]->size)
		free(ht[i++]);
}
>>>>>>> origin
