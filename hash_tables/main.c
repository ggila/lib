#include "hash_tables.h"
#include <stdio.h>

void a(int *b)
{
	printf("%d", *b);
}

int main(void)
{
	t_hash_tbl	ht;

	ht_init(&ht, 15, &int_cmp, &int_hash);
	int i = -1;
	while (++i < 15)
		ht_putm(&ht, (t_kv[]){&i, 4, &i, 4});
	ht_print(&ht, a, a);
	ht_freem(&ht);
	return(0);
}
