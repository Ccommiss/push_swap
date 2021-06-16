#include "pushswap.h"

/*
**
*/
int	push_highest(t_stacks *s)
{
	int	next;
	int	sorted_items;
	int	max;

	sorted_items = 0;
	while (s->n_elem_b >= 5 && !reverse_sorted_array(STACK_B, s->n_elem_b))
	{
		take_biggest(STACK_B, s->n_elem_b, &max);
		next = find_index(max, STACK_B, s->n_elem_b);
		if (STACK_B[s->n_elem_b] == max)
		{
			push_a(s);
			sorted_items++;
		}
		else if (next >= s->n_elem_b / 2)
			rotate_b(s);
		else if (next < s->n_elem_b / 2)
			reverse_rotate_b(s);
	}
	return (sorted_items);
}

/*
**
*/
void	sort_b_on_a(t_stacks *s)
{
	int	sorted_items;

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
	sorted_items = push_highest(s);
	reverse_sort_five(s);
	if (reverse_sorted_array(STACK_B, s->n_elem_b)
		&& sorted_array(STACK_A, s->n_elem_a))
		return ;
	s->low_chunk += sorted_items + s->n_elem_b + 1;
}
