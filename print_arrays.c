#include "pushswap.h"

void print_array(char which_stack, int *stack, int top)
{
	if (which_stack == 'A')
		printf(BRED);
	else
		printf(BCYN);

	int n;
	printf("\n__________________\n");

	printf("|| STACK %c :    ||", which_stack);
	n = -1;
	while (++n <= top)
	{
		printf("\n||______________||\n|| [%3d] => %3d || ", n, stack[n]);
		if (n == top)
			printf(" <-- top of stack \n||______________||");
	}
	printf("\n" reset);
}

void print_arrays(t_stacks *s)
{
	int n;
	int ref;

	if (s->n_elem_a >= s->n_elem_b)
		ref = s->n_elem_a;
	else
		ref = s->n_elem_b;

	printf("%-25s	%-25s", BRED"||       TOP A      ||", BCYN"||      TOP B       ||");
	printf("%20s	%20s", BRED "\n||__________________||", BCYN "||__________________||\n");

	while (ref >= 0 )
	{
		n = ref;

		if (s->n_elem_a > n)
			printf(BRED "||[%5d] => %5d  ||	", n, s->stack_a[n]);
		else if (s->n_elem_a == n)
			printf(BRED "||[> %3d] => %5d  ||	", n, s->stack_a[n]);
		else
			printf("%20s	", " ");

		if (s->n_elem_b > n)
			printf(BCYN "||[%5d] => %5d  ||", n, s->stack_b[n]);
		else if (s->n_elem_b == n)
			printf(BCYN "||[> %3d] => %5d  ||", n, s->stack_b[n]);

		if (s->n_elem_a >= n)
			printf("%20s", BRED "\n||__________________||");
		else if (s->n_elem_a == -1 && n == 0)
			printf("%20s", BRED "\n______________________");
		else
			printf("\n %20s", " ");

		if (s->n_elem_b >= n)
			printf("	%20s", BCYN "||__________________||\n");
		else if (s->n_elem_b == -1 && n == 0)
			printf("	%20s", BCYN "______________________\n");
		else
			printf("	%20s", "\n");
		ref--;
	}
	printf("%-25s	%-25s", BRED"||      STACK A     ||", BCYN"||      STACK B     ||");
	printf("%20s	%20s", BRED "\n||__________________||", BCYN "||__________________||\n");
	printf("\n" reset);
}
