/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 18:13:24 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/20 17:23:15 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdlib.h>
#include <unistd.h>

void	my_write(int fd, const char *str, size_t len)
{
	if (write(fd, str, len) == -1)
		exit(false);
}
