#include "pushswap.h"

int check_lower_than_pivot(int *s, int n_elem, int pivot)
{
	int i;

	i = 0;
	while (i <= n_elem)
	{
		if (s[i] < pivot)
			return TRUE;
		i++;
	}
	return FALSE;
}

int check_higher_than_pivot(int *s, int n_elem, int pivot)
{
	int i; //peeut etre a remplacer par folded index

	i = 0;
	while (i <= n_elem)
	{
		if (s[i] > pivot)
			return TRUE;
		i++;
	}
	return FALSE;
}

void divide_a(t_stacks *s)
{
	int pivot;
	int next;

	printf("s->n_elem_a = %d \n", s->n_elem_a);
	pivot = calculate_median(STACK_A, s->n_elem_a);
	next = find_next(STACK_A, pivot, s->n_elem_a, 'A');

	printf (BGRN"Pivot = %d \n"reset, pivot);
	while (check_lower_than_pivot(STACK_A, s->n_elem_a, pivot) == TRUE && s->n_elem_a >= 3)
	{

		if (s->n_elem_a == 3) // test
		{
			take_smallest(STACK_A, s->n_elem_a, &pivot); //test
			next = find_index(pivot, STACK_A, s->n_elem_a); //test !!
			printf (BRED"NEW NEXT = %d \n"reset, next);
		}
		if(STACK_A[s->n_elem_a] < pivot || (STACK_A[s->n_elem_a] == pivot && s->n_elem_a == 3))
		{
			push_b(s);
			next = find_next(STACK_A, pivot, s->n_elem_a, 'A');
				printf (BRED"NEW NEXT = %d \n"reset, next);
			print_arrays(s);
		}
		else if (next >= s->n_elem_a / 2) // next est en haut de la pile
			rotate_a(s);
		else // next est en bas de la pile
			reverse_rotate_a(s);
	}
	while (s->n_elem_a >= 3)
		divide_a(s);
}



void divide_b(t_stacks *s)
{
	int pivot;
	int next;

	pivot = calculate_median(STACK_B, s->n_elem_b);
	next = find_next(STACK_B, pivot, s->n_elem_b, 'B');

	printf (BGRN"Pivot = %d \n"reset, pivot);
	//print_arrays(s);

	while (check_higher_than_pivot(STACK_B, s->n_elem_b, pivot) == TRUE && s->n_elem_b >= 3)
	{
		if (s->n_elem_b == 3)
		{
			take_biggest(STACK_B, s->n_elem_b, &pivot);
			next = find_index(pivot, STACK_B, s->n_elem_b);
		}
		if(STACK_B[s->n_elem_b] > pivot || (STACK_B[s->n_elem_b] == pivot && s->n_elem_b == 3))
		{
			push_a(s);
			next = find_next(STACK_B, pivot, s->n_elem_b, 'B');
		}
		else if (next >= s->n_elem_b / 2) // next est en haut de la pile
			rotate_b(s);
		else if (next < s->n_elem_b / 2) // next est en bas de la pile
			reverse_rotate_b(s);
	}
	while (s->n_elem_b >= 3)
		divide_b(s);
}
