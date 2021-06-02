#include "pushswap.h"


//Fichier pour l'option une pile


void 	pushback_on_a(t_stacks *s)
{
	int new_chunks = s->n_elem_b + 1;
	int i = 0;
	int min = 0;

	if (s->n_elem_b == -1)
		return;

	take_smallest(STACK_A, s->n_elem_a, &min);
	if (s->index_min != -1) //test parce que la premiere fois faut pas faire les rras qui suivent
		s->index_min = find_index(min, STACK_A, s->n_elem_a);

//	printf ("INDEX MIN = %d \n",	s->index_min);
	while (s->index_min != -1 && (s->index_min + 1) - (s->low_chunk - new_chunks) > 0) //|| (s->index_min + 1) - (s->low_chunk - new_chunks) < 0 )
	{
		printf ("INDEX MIN = %d \n",	s->index_min);
		// if (  ((s->index_min + 1) - (s->low_chunk - new_chunks) > (s->n_elem_a + 1) / 2) 
		// || ((s->index_min + 1) - (s->low_chunk - new_chunks) < 0) )
		// {
		// 	rotate_a(s);
		// 	s->index_min++;
		// 	if (s->index_min == s->n_elem_a + 1)
		// 		s->index_min = 0;
		// }
		// else
		// {
			reverse_rotate_a(s);
			s->index_min--;
		// }
	}

	while (i < new_chunks)
	{
		push_a(s);
		i++;
	}
	i = -1; //
	while (++i < new_chunks)// RPBLEME ICI ? 
		rotate_a(s);// 

	take_smallest(STACK_A, s->n_elem_a, &min);
	s->index_min = find_index(min, STACK_A, s->n_elem_a);
	printf ("INDEX MIN HERE = %d \n\n", s->index_min);
}








