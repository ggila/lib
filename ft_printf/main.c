#include "ft_printf.h"

int main(void)
{
	ft_printf("abc\n\\\\\\\n%s\n%c%c%c%c\n", "abc",'a','a','a','a');
	ft_printf("\n");
	ft_printf("%d\n%s: %d\nf: %f\n%.5f\n",2,"line",4,1.2f, 1.23456f);
	return (0);
}
