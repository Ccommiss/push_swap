#include "pushswap.h"

void	push_or_rotate_a(t_stacks *s, int pivot)
{
	int	next;

	next = 0;
	if (s->n_elem_a == s->chunk_size)
	{
		take_smallest(STACK_A, s->n_elem_a, &pivot);
		next = find_index(pivot, STACK_A, s->n_elem_a);
	}
	if (STACK_A[s->n_elem_a] < pivot
		|| (STACK_A[s->n_elem_a] == pivot && s->n_elem_a == s->chunk_size))
	{
		push_b(s);
		next = find_next(STACK_A, pivot, s->n_elem_a, 'A');
	}
	else if (next >= s->n_elem_a / 2)
		rotate_a(s);
	else
		reverse_rotate_a(s);
}

/*
**  Recursively divides A and keeps the lower part from median, until
**	the number of elems equals to chunk size
**  @params {t_stacks*}s
*/
void	divide_a(t_stacks *s)
{
	int	pivot;
	int	next;
	int	to_push;

	if (s->n_elem_a < 2 * s->chunk_size)
		to_push = s->n_elem_a - s->chunk_size;
	else
		to_push = 0;
	pivot = calculate_median(STACK_A, s->n_elem_a, to_push);
	next = find_next(STACK_A, pivot, s->n_elem_a, 'A');
	while (check_lower_than_pivot(STACK_A, s->n_elem_a, pivot) == TRUE
		|| s->n_elem_a == s->chunk_size)
	{
		push_or_rotate_a(s, pivot);
	}
	while (s->n_elem_a >= s->chunk_size)
		divide_a(s);
}

void	push_or_rotate_b(t_stacks *s, int pivot)
{
	int	next;

	next = 0;
	if (s->n_elem_b == s->chunk_size)
	{
		take_biggest(STACK_B, s->n_elem_b, &pivot);
		next = find_index(pivot, STACK_B, s->n_elem_b);
	}
	if (STACK_B[s->n_elem_b] > pivot || (STACK_B[s->n_elem_b] == pivot
			&& s->n_elem_b == s->chunk_size))
	{
		push_a(s);
		next = find_next(STACK_B, pivot, s->n_elem_b, 'B');
	}
	else if (next >= s->n_elem_b / 2)
		rotate_b(s);
	else if (next < s->n_elem_b / 2)
		reverse_rotate_b(s);
}

/**
 *		_Recursively divides B and keeps the lower part from median, until
 *		_the number of elems equals to chunk size
 *		@params {t_stacks*}s
 **/
void	divide_b(t_stacks *s)
{
	int	pivot;
	int	next;
	int	to_push;

	if (s->n_elem_b < s->chunk_size)
		return ;
	if (s->n_elem_b < 2 * s->chunk_size)
		to_push = s->chunk_size;
	else
		to_push = 0;
	pivot = calculate_median(STACK_B, s->n_elem_b, to_push);
	next = find_next(STACK_B, pivot, s->n_elem_b, 'B');
	while (check_higher_than_pivot(STACK_B, s->n_elem_b, pivot) == TRUE
		|| s->n_elem_b == s->chunk_size)
	{
		push_or_rotate_b(s, pivot);
	}
	while (s->n_elem_b >= s->chunk_size)
		divide_b(s);
}
