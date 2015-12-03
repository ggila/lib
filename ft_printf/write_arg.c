/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:22:01 by ggilaber          #+#    #+#             */
/*   Updated: 2015/12/03 20:32:24 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//color = RGB W Y
//82  71  66  87  89
//format = scdfp

void	write_arg(int fd, char **str, va_list args)
{
	g_flag = 0;
	if (**str > 'A' && **str < 'Z')
	{
		g_flag = MASK_COLOR;
		print_col[(int)((**str - 2) % 17)]();
	}
}
