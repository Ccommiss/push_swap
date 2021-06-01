#include "pushswap.h"

int is_sorted(t_stacks *s)
{
	int i;

	i = 1;
	printf ("%d :::\n", s->n_elem_a);
	while (i <= s->n_elem_a)
	{
		if (STACK_A[i] < STACK_A[i - 1])
			i++;
		else
			return FALSE;
	}
	printf ("RETURN TRUE !!!!\n");
	return TRUE;
}

int finish(t_stacks *s)
{
	if (s->n_elem_b != -1)
		return FALSE;

	int i;

	i = 1;
	while (i <= s->n_elem_a)
	{
		if (STACK_A[i] < STACK_A[i - 1])
			i++;
		else
			return FALSE;
	}
	return TRUE;

}

int is_reverse_sorted(t_stacks *s)
{
	if (s->n_elem_a != -1 && !is_sorted(s))
	{
		printf ("bye here\n");
		return FALSE;
	}

	if (s->n_elem_a > -1 && s->n_elem_b > -1
	&& STACK_B[s->n_elem_b] > STACK_A[s->n_elem_a])
	{
		printf ("bye there\n");
		//VERBOSE = TRUE;
		print_arrays(s);
	//	VERBOSE = FALSE;
		return FALSE;
	}

	int i;

	i = 1;
	while (i <= s->n_elem_b)
	{
		if (STACK_B[i] > STACK_B[i - 1])
			i++;
		else
			return FALSE;
	}
	printf("REVERSE SORTED TRUE\n");
	return TRUE;
}
