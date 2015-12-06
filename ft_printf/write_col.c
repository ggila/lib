#include <unistd.h>

#include "ft_printf.h"

void	write_col(int fd, char c)
{
	if (c == 'r')
		write(fd, RED, 5);
	if (c == 'g')
		write(fd, GREEN, 5);
	if (c == 'b')
		write(fd, BLUE, 5);
	if (c == 'y')
		write(fd, YELLOW, 5);
	if (c == 'w')
		write(fd, WHITE, 5);
}
