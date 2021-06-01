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
	return (TRUE);
}
