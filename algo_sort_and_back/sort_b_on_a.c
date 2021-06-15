#include "pushswap.h"

void	sort_b_on_a(t_stacks *s)
{
	int pivot;
	int max;
	int next;

	pivot = calculate_median(STACK_B, s->n_elem_b, 0);
	if (s->n_elem_b < 1 || reverse_sorted_array(STACK_B, s->n_elem_b))
	{
		NOTENOUGH("B")
		s->low_chunk += s->n_elem_b + 1;
		return ;
	}
	if (s->n_elem_b == 1)
	{
		if (STACK_B[s->n_elem_b] < STACK_B[s->n_elem_b - 1])
			swap_b(s);
		s->low_chunk += s->n_elem_b + 1;
		return ;
	}
	int pushed_for_later = 0;
	while (s->n_elem_b >= 5 && !reverse_sorted_array(STACK_B, s->n_elem_b)) // on met les cinq plus gros sur A dans l;ordre
	{
		take_biggest(STACK_B, s->n_elem_b, &max);
		next = find_index(max, STACK_B, s->n_elem_b);

		if (STACK_B[s->n_elem_b] == max)
		{
			push_a(s);
			pushed_for_later++;
		}
		else if (next >= s->n_elem_b / 2)
			rotate_b(s);
		else if (next < s->n_elem_b / 2)
			reverse_rotate_b(s);
	}
	reverse_sort_five(s);

	if (reverse_sorted_array(STACK_B, s->n_elem_b) && sorted_array(STACK_A, s->n_elem_a)) // TEST POUR TRYDIVIDE
		return ;
	s->low_chunk +=  pushed_for_later + s->n_elem_b + 1;
}
