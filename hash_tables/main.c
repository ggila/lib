#include "hash_tables.h"
#include <stdlib.h>
#include <stdio.h>

void a(int *b)
{
	printf("%d", *b);
}

int main(void)
{
	t_hash_tbl	ht;

	ht_init(&ht, 1, &int_cmp, &int_hash);
	int i = -1;
	int r;
	while (++i < 30)
	{
		r = random();
		ht_putm(&ht, (t_kv[]){&i, 4, &r, 4});
	}
	ht_print(&ht, a, a);
	ht_freem(&ht);
	return(0);
}
