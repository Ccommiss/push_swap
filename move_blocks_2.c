#include "pushswap.h"

void 	pushback_on_a(t_stacks *s)
{
	int new_chunks = s->n_elem_b + 1;
	int i = 0;
	int min = 0;

	while (i < new_chunks)
	{
		push_a(s);
		rotate_a(s);
	}
	
	if (s->index_min = -1)
	{
		take_smallest(STACK_A, s->n_elem_a, &min);
		s->index_min = find_index(min, STACK_A, s->n_elem_a);
	}

}







}
