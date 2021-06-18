#include "pushswap.h"

void	push_big_nb(t_stacks *s)
{
	int	max;
	int	tmp;
	int	i;

	tmp = s->n_elem_a + 1;
	i = -1;
	take_biggest(STACK_B, s->n_elem_b, &max);
	while (STACK_B[s->n_elem_b] != max && s->high_chunk - tmp != 0)
	{
		if (find_index(max, STACK_B, s->n_elem_b) >= s->n_elem_b / 2)
			rotate_b(s);
		else
			reverse_rotate_b(s);
	}
	while (++i < s->high_chunk - tmp)
		push_a(s);
}

void	push_small_nb(t_stacks *s)
{
	int	i;
	int	min;

	i = -1;
	take_smallest(STACK_A, s->n_elem_a, &min);
	while (STACK_A[s->n_elem_a] != min)
	{
		if (find_index(min, STACK_A, s->n_elem_a) >= s->n_elem_a)
			rotate_a(s);
		else
			reverse_rotate_a(s);
	}
	i = -1;
	while (++i < s->low_chunk)
		push_a(s);
}

void	insert_blocks_on_a(t_stacks *s)
{
	if (s->n_elem_b == -1)
		return ;
	push_big_nb(s);
	push_small_nb(s);
}

void	insert_blocks_on_b(t_stacks *s)
{
	int	i;
	int	tmp;
	int	block;

	i = -1;
	if (s->n_elem_a == -1)
		return ;
	tmp = s->n_elem_b + 1;
	block = s->high_chunk + s->low_chunk - tmp;
	if (block > s->n_elem_a / 2)
		while (++i <= s->n_elem_a - block)
			rotate_a(s);
	else
		while (++i < s->high_chunk + s->low_chunk - tmp)
			reverse_rotate_a(s);
	i = -1;
	while (++i < s->low_chunk - tmp)
		push_b(s);
	i = -1;
	while (++i < tmp && s->low_chunk - tmp != 0)
		reverse_rotate_b(s);
	i = -1;
	while (++i < s->high_chunk)
		push_b(s);
}
