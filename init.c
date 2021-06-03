#include "pushswap.h"



void check_errors(t_stacks *s)
{
	int *copy;
	int i;
	int j;
	copy = (int *)malloc(sizeof(int) * (s->n_elem_a + 1));

	i = 0;
	j = 0;
	while (i <= s->n_elem_a)
	{
		copy[i] = STACK_A[i];
		j = 0;
		while (j <= i)
		{
			//printf ("index j = copy[%d] = %d -- copy[%d] = %d", j, copy[j], i, copy[i]);
			if (j != i && copy[j] == copy[i])
			{
				printf("Index [%d] and [%d] : value are the same (%d)", j, i, copy[j]);
				exit (0);
			}
			j++;
		}
		i++;

	}


}






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
	s->chunk_size = 0;

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
