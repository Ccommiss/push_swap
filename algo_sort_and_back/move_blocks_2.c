#include "pushswap.h"

/*
**	Clear A
**
**	Puts all sorted numbers to the bottom of stack A
**	@param {t_stacks *s} our main structure pointer
*/
void	clear_a(t_stacks *s)
{
	int	min;

	min = 0;
	take_smallest(STACK_A, s->n_elem_a, &min);
	if (s->index_min == -1 || s->n_elem_b == -1)
		return ;
	s->index_min = find_index(min, STACK_A, s->n_elem_a);
	while (s->index_min != -1 && (s->index_min + 1) - (s->low_chunk) != 0)
	{
		if (((s->index_min + 1) - (s->low_chunk) >= (s->n_elem_a + 1) / 2)
			|| ((s->index_min + 1) - (s->low_chunk) < 0))
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

void	pushback_on_a(t_stacks *s)
{
	int	i;
	int	min;
	int	new_items;

	new_items = s->n_elem_b + 1;
	i = -1;
	min = 0;
	if (s->n_elem_b == -1)
		return ;
	take_smallest(STACK_A, s->n_elem_a, &min);
	if (s->index_min != -1)
		s->index_min = find_index(min, STACK_A, s->n_elem_a);
	while (++i < new_items)
		push_a(s);
	i = -1;
	while (++i < s->low_chunk - s->index_min - 1)
		rotate_a(s);
	take_smallest(STACK_A, s->n_elem_a, &min);
	s->index_min = find_index(min, STACK_A, s->n_elem_a);
}
