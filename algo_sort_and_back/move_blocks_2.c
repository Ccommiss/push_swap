#include "pushswap.h"


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
	int i = 0;
	int min = 0;

	if (s->n_elem_b == -1)
		return;

	take_smallest(STACK_A, s->n_elem_a, &min);
	if (s->index_min != -1) //test parce que la premiere fois faut pas faire les rras qui suivent
		s->index_min = find_index(min, STACK_A, s->n_elem_a);


	printf("CALCUL BAS  = %d \n", (s->index_min + 1) - (s->low_chunk));
	printf("INDEX MIN = %d \n", s->index_min);

	// while (s->index_min != -1 && (s->index_min + 1) - (s->low_chunk - new_chunks) != 0)
	// {
	// 	if (((s->index_min + 1) - (s->low_chunk - new_chunks) >= (s->n_elem_a + 1) / 2) || ((s->index_min + 1) - (s->low_chunk - new_chunks) < 0))
	// 	{
	// 		rotate_a(s);
	// 		s->index_min++;
	// 		if (s->index_min == s->n_elem_a + 1)
	// 			s->index_min = 0;
	// 	}
	// 	else
	// 	{
	// 		reverse_rotate_a(s);
	// 		s->index_min--;
	// 	}
	// } TEST AVEC CLEAR A AVANT


	while (i < new_chunks)
	{
		push_a(s);
		i++;
	}
	i = -1;
	// while (++i < new_chunks)
	// 	rotate_a(s);
	while (++i < s->low_chunk - s->index_min - 1) //TESTTEST
		rotate_a(s);

	take_smallest(STACK_A, s->n_elem_a, &min);
	s->index_min = find_index(min, STACK_A, s->n_elem_a);
	sleep(2);
	//printf("INDEX MIN HERE = %d \n\n", s->index_min);
}
