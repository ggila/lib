#include "hash_tables.h"

int main(void)
{
	t_hash_tbl	*ht;

	ht = NULL;
	ht_init(ht, 15, &int_cmp, &int_hash);
	ht_freem(ht);
	return(0);
}
