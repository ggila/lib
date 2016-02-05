<<<<<<< HEAD
||||||| merged common ancestors
<<<<<<< Temporary merge branch 1
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
||||||| merged common ancestors
=======
=======
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
>>>>>>> 415d971bf9b76099d0caf80bc064b33dd132923d
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
<<<<<<< HEAD
	while (i < ht->size)
	{
		if (ht->nodes[i]->kv.value != NULL)
		{
			free(ht->nodes[i]->kv.key);
			free(ht->nodes[i]->kv.value);
			free(ht->nodes[i]);
		}
		i++;
	}
||||||| merged common ancestors
	while (i < ht->size)
		free(ht->nodes[i++]);
=======
	while (i < ht[i]->size)
		free(ht[i++]);
>>>>>>> 415d971bf9b76099d0caf80bc064b33dd132923d
}
<<<<<<< HEAD
||||||| merged common ancestors
>>>>>>> Temporary merge branch 2
=======
>>>>>>> origin
>>>>>>> 415d971bf9b76099d0caf80bc064b33dd132923d
