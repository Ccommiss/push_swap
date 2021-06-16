#include "pushswap.h"
#include <time.h>



void print_stats(t_stacks *s)
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

	printf(BWHT "\n\nTOTAL OPCOUNT => %d\n" reset, s->op_count);
	printf("\n\n_____\n");
	s->sa = 0;
	s->sb = 0;
	s->pa = 0;
	s->pb = 0;
	s->ra = 0;
	s->rb = 0;
	s->rra = 0;
	s->rrb = 0;
}



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

	//printf("\033[2J\033[1;1H");
	if (s->verbose == FALSE)
		return ;
	if (s->n_elem_a >= s->n_elem_b)
		ref = s->n_elem_a;
	else
		ref = s->n_elem_b;

	printf ("%40c", 32);
	printf("%-25s	%-25s", BRED"||       TOP A      ||", BCYN"||      TOP B       ||\n");
	printf ("%40c", 32);
	printf("%20s	%20s", BRED "||__________________||", BCYN "||__________________||\n");

	while (ref >= 0 )
	{
		n = ref;

		printf ("%40c", 32);
		if (s->n_elem_a > n)
			printf(BRED "||[%5d] => %5d  ||	", n, s->stack_a[n]);
		else if (s->n_elem_a == n)
			printf(BRED "||[> %3d] => %5d  ||	", n, s->stack_a[n]);
		else
			printf("%20s	", " ");

		printf ("%40c", 32);
		if (s->n_elem_b > n)
			printf(BCYN "||[%5d] => %5d  ||", n, s->stack_b[n]);
		else if (s->n_elem_b == n)
			printf(BCYN "||[> %3d] => %5d  ||", n, s->stack_b[n]);

		// if (s->n_elem_a >= n)
		// 	printf("%20s", BRED "\n||__________________||");
		// else if (s->n_elem_a == -1 && n == 0)
		// 	printf("%20s", BRED "\n______________________");
		// else
		//	printf("\n %20s", " ");
		printf ("\n");

		// if (s->n_elem_b >= n)
		// 	printf("	%20s", BCYN "||__________________||\n");
		// else if (s->n_elem_b == -1 && n == 0)
		// 	printf("	%20s", BCYN "______________________\n");
		// else
		// 	printf("	%20s", "\n");
		ref--;
	}
		printf ("%40c", 32);
	printf("%-25s	%-25s", BRED"||      STACK A     ||", BCYN"||      STACK B     ||\n");
	printf ("%40c", 32);
	printf("%20s	%20s", BRED "||__________________||", BCYN "||__________________||\n"reset);
	printf ("%40c", 32);
	printf("\n" reset);
	usleep(80000);
	//sleep(1);
}
