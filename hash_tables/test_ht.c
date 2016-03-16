#include <time.h>
#include <stdio.h>
#include "ft_printf.h"
#include "hash_tables.h"

#define INT_KEY_VAL(a, b) (t_kv){a, 4, b, 4}
#define DEF(a, b) int c = a; int d = b;
#define ADD_INT(h, a, b) {DEF(a,b);t_kv k=INT_KEY_VAL(&c,&d); ht_putm(h,&k);}

void	test_insertion(t_hash_tbl *ht, int nb_insert, int (*key_func)())
{
	int			i;
	clock_t		begin, end;
	double		time_spent;
	
	int k = 0, v = 0;
	t_kv kv = {&k, sizeof(int), &v, sizeof(int)};
	begin = clock();
	i = 0;
	(void)key_func;
	while (i < nb_insert)
	{
		ht_putm(ht, &kv);
//		ADD_INT(ht, key_func(), rand());
		i++;
	}
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	ft_printf("\t%d -> %.7f\n", nb_insert, time_spent);
}

void	p(int i) {ft_printf("%d", i);};

void	insertion_routine(char *mess, int (*key_func)())
{
	t_hash_tbl	ht;
//	int			nb_ins[] = {10, 100, 1000, 10000, 100000, 1000000};
	int			nb_ins[] = {100, 100, 1000, 10000, 100000, 1000000};
	int			i = 0;

	ft_printf("%s:\n", mess);
	while (i < 1)
	{
		ht_init(&ht, 2 * nb_ins[i], int_cmp, int_hash);
		test_insertion(&ht, nb_ins[i], key_func);
		ht_print(&ht, p, p);
		ht_freem(&ht);
		i++;
	}
	ft_printf("--------------\n", mess);
}

int worst(void) {return 0;}
int best(void)
{
	static int i = -1;

	i++;
	return i;
}

int		main(void)
{

	srand(time(NULL));
//	insertion_routine("random", rand);
	insertion_routine("worst case", worst);
//	insertion_routine("best case", best);
}
