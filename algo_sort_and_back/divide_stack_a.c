#include "pushswap.h"




/*
**
**  Creates an array with the n biggest or smallest elements of a stack
**
**	@param {int} size
**	@param {int*} stack
**  @param {int} type : or BIGGEST_VALUES or SMALLEST_VALUES (enum)
**  @return malloced array with extreme values
**
*/
int *find_extreme_numbers(int size, int *stack, int type, t_stacks *s)
{
	int *array;

	array = (int *)malloc(sizeof(int) * size);
	if (type == BIGGEST_VALUES)
		find_biggest(s, &array, stack);
	else if (type == SMALLEST_VALUES)
		find_smallest(s, &array, stack);
	return (array);
}

/*
** 	Choose move in function of the closest nb
**
**		> 1 : "lowest_index" array : finds all indexes e.g. distance from the bottom
**		> 2 : "highest index" array : finds "reverse indexes" e.g. distance from the top
**		> 3 : takes the 2 smallest index from both array, the smallest index says
**			which one is better
**	@param {int*} array containing biggest/lowest nb
**	@param {int*} stack
*/
int choose_move(t_stacks *s, int *array, int to_push)
{
	int biggest;
	int lowest;
	int i;
	int cur_index;

	i = -1;
	lowest = INT32_MAX;
	biggest = INT32_MAX;
	while (++i < to_push) //on cherche l'index brut, le plus petit sera le lowest
	{
		cur_index = find_index(array[i], STACK_A, s->n_elem_a);
		if (cur_index < lowest && cur_index != -1)
			lowest = cur_index;
		if (s->n_elem_a - cur_index < biggest && cur_index != -1)
			biggest = s->n_elem_a - cur_index;
	}
	if (lowest < biggest && lowest > -1) //c  mieux daller vers le bas
		return (2);						 //RRA
	else
		return (3); // RA
}

void divide_stack_a(t_stacks *s)
{
	int *min_array;
	int to_push;
	int i;
	int next;

	to_push = s->n_elem_a - s->low_chunk + 1;
	if (to_push == 1)
	{
		rotate_a(s);
		s->low_chunk += 1;
		return;
	}
	if (to_push > s->chunk_size)
		to_push = s->chunk_size;
	min_array = find_extreme_numbers(s->chunk_size, STACK_A, SMALLEST_VALUES, s);
	while (to_push > 0)
	{
		i = 0;
		next = choose_move(s, min_array, s->chunk_size);
		while (i < s->chunk_size)
		{
			if (STACK_A[s->n_elem_a] == min_array[i])
			{
				push_b(s);
				to_push--;
				break;
			}
			i++;
		}
		if (i == s->chunk_size)
		{
			if (next == 2)
				reverse_rotate_a(s);
			else if (next == 3)
				rotate_a(s);
		}
	}
}
