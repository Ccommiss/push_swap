#include "pushswap.h"

int create_stacks(t_stacks *s, int elems)
{
	s->stack_a = (int *)malloc(sizeof(int) * elems);
	if (!s->stack_a)
	{
		//free_stacks(s);
		return (FALSE);
	}
	s->n_elem_a = -1; // top de la list
	s->stack_b = (int *)malloc(sizeof(int) * elems);
	if (!s->stack_b)
	{
		//free_stacks(s);
		return (FALSE);
	}
	s->n_elem_b = -1; //idem
	s->low_chunk = 0;
	s->high_chunk = 0;
	s->index_min = -1;

	s->pa = 0;
	s->pb = 0;
	s->sa = 0;
	s->sb = 0;
	s->ra = 0;
	s->rb = 0;
	s->rra = 0;
	s->rrb = 0;
	return (TRUE);
}
