/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:53:48 by ggilaber          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/02/05 10:23:32 by ggilaber         ###   ########.fr       */
||||||| merged common ancestors
<<<<<<< Temporary merge branch 1
/*   Updated: 2016/02/05 09:22:14 by ggilaber         ###   ########.fr       */
||||||| merged common ancestors
/*   Updated: 2016/01/29 00:04:22 by ggilaber         ###   ########.fr       */
=======
/*   Updated: 2016/02/05 10:23:32 by ggilaber         ###   ########.fr       */
>>>>>>> Temporary merge branch 2
=======
<<<<<<< HEAD
/*   Updated: 2016/02/05 10:23:32 by ggilaber         ###   ########.fr       */
||||||| merged common ancestors
/*   Updated: 2016/01/29 00:04:22 by ggilaber         ###   ########.fr       */
=======
/*   Updated: 2016/02/05 09:22:14 by ggilaber         ###   ########.fr       */
>>>>>>> origin
>>>>>>> 415d971bf9b76099d0caf80bc064b33dd132923d
/*                                                                            */
/* ************************************************************************** */

#include "hash_tables.h"
#include <stdlib.h>

void	ht_free(t_hash_tbl *ht)
{
	int	i;

	i = 0;
	while (i < ht->size)
		free(ht->nodes[i++]);
}
