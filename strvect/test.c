/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 16:46:14 by ggilaber          #+#    #+#             */
/*   Updated: 2016/05/20 18:13:52 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strvect.h"
#include "ft_printf.h"

void	test_push_char(t_strvect *vect)
{
	int  i = 0;

	ft_printf("TEST PUSH_CHAR\n");

	ft_printf("str: %s\nsize: %d\ncapacity: %d\n\n",
			vect->str, vect->size, vect->capacity);

	strvect_push_char(vect, '0');
	ft_printf("str: %s\nsize: %d\ncapacity: %d\n\n",
			vect->str, vect->size, vect->capacity);

	strvect_push_char(vect, '1');
	strvect_push_char(vect, '2');
	strvect_push_char(vect, '3');
	strvect_push_char(vect, '4');
	strvect_push_char(vect, '5');
	strvect_push_char(vect, '6');
	strvect_push_char(vect, '7');
	ft_printf("str: %s\nsize: %d\ncapacity: %d\n\n",
			vect->str, vect->size, vect->capacity);

	strvect_push_char(vect, '0');
	strvect_push_char(vect, '1');
	strvect_push_char(vect, '2');
	strvect_push_char(vect, '3');
	strvect_push_char(vect, '4');
	strvect_push_char(vect, '5');
	strvect_push_char(vect, '6');
	ft_printf("str: %s\nsize: %d\ncapacity: %d\n\n",
			vect->str, vect->size, vect->capacity);

	strvect_push_char(vect, '7');
	ft_printf("str: %s\nsize: %d\ncapacity: %d\n\n",
			vect->str, vect->size, vect->capacity);

	while (i++ < 40)
	{
		strvect_push_char(vect, '0');
		strvect_push_char(vect, '1');
		strvect_push_char(vect, '2');
		strvect_push_char(vect, '3');
		strvect_push_char(vect, '4');
		strvect_push_char(vect, '5');
		strvect_push_char(vect, '6');
		strvect_push_char(vect, '7');
		ft_printf("str: %s\nsize: %d\ncapacity: %d\n\n",
				vect->str, vect->size, vect->capacity);
	}
}

void	test_push_str1(t_strvect *vect)
{
	ft_printf("TEST PUSH_STR1\n");
	ft_printf("str: %s\nsize: %d\ncapacity: %d\n\n",
			vect->str, vect->size, vect->capacity);

	strvect_push_str(vect, "01234567");
	ft_printf("str: %s\nsize: %d\ncapacity: %d\n\n",
			vect->str, vect->size, vect->capacity);

	strvect_push_str(vect, "01234567");
	ft_printf("str: %s\nsize: %d\ncapacity: %d\n\n",
			vect->str, vect->size, vect->capacity);
}

void	test_push_str2(t_strvect *vect)
{
	ft_printf("TEST PUSH_STR2\n");
	ft_printf("str: %s\nsize: %d\ncapacity: %d\n\n",
			vect->str, vect->size, vect->capacity);

	strvect_push_str(vect, "01234567");
	ft_printf("str: %s\nsize: %d\ncapacity: %d\n\n",
			vect->str, vect->size, vect->capacity);

	strvect_push_str(vect, "0123456701234567012345670123456701234567");
	ft_printf("str: %s\nsize: %d\ncapacity: %d\n\n",
			vect->str, vect->size, vect->capacity);
}

void	test_func(void)
{
	t_strvect vect;

	strvect_init(&vect);
	test_push_char(&vect);
	free(vect.str);

	strvect_init(&vect);
	test_push_str1(&vect);
	free(vect.str);

	strvect_init(&vect);
	test_push_str2(&vect);
	free(vect.str);

	return;
}

int main(void)
{
	t_strvect vect;

	strvect_init(&vect);
	test_push_char(&vect);
	free(vect.str);

	strvect_init(&vect);
	test_push_str1(&vect);
	free(vect.str);

	strvect_init(&vect);
	test_push_str2(&vect);
	free(vect.str);

	test_func();

	while (42);

	return (0);
}
