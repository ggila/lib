#include "hash_tables.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

void print_int(int *b)
{
	printf("%d", *b);
}

void print_str(char *str)
{
	printf("%s", str);
}

int main(void)
{
	t_hash_tbl	ht;
	char		*str[] = {"aa", "sdf", "sefs", "serfrs", "sasssa"};

	ht_init(&ht, 10, &ft_strcmp, &hash_djb2);
	int i = -1;
	int r;
	while (++i < 30)
	{
		r = random();
		ht_putm(&ht, (t_kv[]){str[i%5], strlen(str[i%5]) + 1, &i, 4});
	}
	ht_print(&ht, print_str, print_int);
	printf("%d\n", *(int*)ht_get(&ht, "aa"));
	printf("%d\n", *(int*)ht_get(&ht, "sdf"));
	printf("%d\n", *(int*)ht_get(&ht, "sefs"));
	ht_freem(&ht);
	return(0);
}
