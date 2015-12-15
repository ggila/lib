#include "ft_readline.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*s;

	len = ft_strlen(str);
	if ((s = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	ft_memcpy(s, str, len + 1);
	return (s);
}
