#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	char buf[] = { 'A', 'B', 'C' , 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J' , 'K', 'L', 'M', 'N', 'O', 'P', 'Q'};

//	ft_printf("abc\n\\\\\\\n%s\n%c%c%c%c\n", "abc",'a','a','a','a');
//	ft_printf("\n");
//	ft_printf("%d\n%s: %d\nf: %f\n%.5f\n",2,"line",4,1.2f, 1.23456f);
	ft_bzero(buf + 2, 11);
	return (0);
}
