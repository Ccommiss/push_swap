#include "pushswap.h"

/*
**
*/
void clear_a(t_stacks *s) //met le index min le plus bas possible
{
	int min = 0;
	take_smallest(STACK_A, s->n_elem_a, &min);
	s->index_min = find_index(min, STACK_A, s->n_elem_a);
	while (s->index_min != -1 && (s->index_min + 1) - (s->low_chunk) != 0)
	{
		printf ("%d === \n", (s->index_min + 1) - (s->low_chunk));
		if (((s->index_min + 1) - (s->low_chunk) >= (s->n_elem_a + 1) / 2) || ((s->index_min + 1) - (s->low_chunk) < 0))
		{
			rotate_a(s);
			s->index_min++;
			if (s->index_min == s->n_elem_a + 1)
				s->index_min = 0;
		}
		else
		{
			reverse_rotate_a(s);
			s->index_min--;
		}
	}
}

void pushback_on_a(t_stacks *s)
{
	int new_chunks = s->n_elem_b + 1;
	int i = -1;
	int min = 0;

	if (s->n_elem_b == -1)
		return;
	take_smallest(STACK_A, s->n_elem_a, &min);
	if (s->index_min != -1)
		s->index_min = find_index(min, STACK_A, s->n_elem_a);
	while (++i < new_chunks)
		push_a(s);
	i = -1;
	while (++i < s->low_chunk - s->index_min - 1)
		rotate_a(s);
	take_smallest(STACK_A, s->n_elem_a, &min);
	s->index_min = find_index(min, STACK_A, s->n_elem_a);
}
