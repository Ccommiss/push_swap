#include "pushswap.h"
#include <time.h>

void	print_stats(t_stacks *s, int arg)
{
	(void)s;
	printf("\n\nSTATS :\n");
	printf("SwapA = %d\n", s->sa);
	printf("SwapB = %d\n", s->sb);
	printf("PushA = %d\n", s->pa);
	printf("PushB = %d\n", s->pb);
	printf("RA = %d\n", s->ra);
	printf("RB = %d\n", s->rb);
	printf("RRA = %d\n", s->rra);
	printf("RRB = %d\n", s->rrb);
	printf(BWHT"\n\nTOTAL OPCOUNT => %d\n" RESET, s->op_count);
	printf ("*** for %d args, chunk of %d\n", arg, s->chunk_size);
	printf("\n\n_____\n");
}

void	print_array(char which_stack, int *stack, int top)
{
	int	n;

	n = -1;
	if (which_stack == 'A')
		printf(BRED);
	else
		printf(BCYN);
	printf("\n__________________\n");
	printf("|| STACK %c :    ||", which_stack);
	while (++n <= top)
	{
		printf("\n||______________||\n|| [%3d] => %3d || ", n, stack[n]);
		if (n == top)
			printf(" <-- top of stack \n||______________||");
	}
	printf("\n" RESET);
}

void	print_stacks(int n, t_stacks *s)
{
	while (n-- > 0)
	{
		printf ("%40c", 32);
		if (s->n_elem_a > n)
			printf(BRED "||[%5d] => %5d  ||	", n, s->a[n]);
		else if (s->n_elem_a == n)
			printf(BRED "||[> %3d] => %5d  ||	", n, s->a[n]);
		else
			printf("%20s	", " ");
		if (s->n_elem_b > n)
			printf(BCYN "||[%5d] => %5d  ||", n, s->b[n]);
		else if (s->n_elem_b == n)
			printf(BCYN "||[> %3d] => %5d  ||", n, s->b[n]);
		printf ("\n");
	}
}

void	print_arrays(t_stacks *s)
{
	int	n;

	if (s->verbose == FALSE)
		return ;
	if (s->n_elem_a >= s->n_elem_b)
		n = s->n_elem_a + 1;
	else
		n = s->n_elem_b + 1;
	printf ("%40c", 32);
	printf("%-25s	%-25s", BRED"||       TOP A      ||",
		BCYN"||      TOP B       ||\n");
	printf ("%40c", 32);
	printf("%20s	%20s", BRED "||__________________||",
		BCYN "||__________________||\n");
	print_stacks(n, s);
	printf ("%40c", 32);
	printf("%-25s	%-25s", BRED"||      STACK A     ||",
		BCYN"||      STACK B     ||\n");
	printf ("%40c", 32);
	printf("%20s	%20s", BRED "||__________________||",
		BCYN "||__________________||\n"RESET);
	printf ("%40c"RESET, 32);
	printf ("\n");
}
