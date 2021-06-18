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
int	*find_extreme_numbers(int size, int *stack, int type, t_stacks *s)
{
	int	*array;

	if (!ft_malloc_int_pointer(size, &array))
	{
		free_stacks(s);
		exit (0);
	}
	if (type == BIGGEST_VALUES)
		find_biggest(s, &array, stack);
	else if (type == SMALLEST_VALUES)
		find_smallest(s, &array, stack);
	return (array);
}

/*
** 	Choose move in function of the closest nb
**
**		> 1 : "lowest_index" array : finds all indexes e.g. 
**			distance from the bottom
**		> 2 : "highest index" array : finds "reverse indexes" 
**			e.g. distance from the top
**		> 3 : takes the 2 smallest index from both array, 
**			the smallest index says which one is better
**		>> if lowest < biggest, RRA is more optimised ; vice-versa
**
**	@param {int*} array containing biggest/lowest nb
**	@param {int*} stack
*/
int	choose_move(t_stacks *s, int *array, int to_push)
{
	int	biggest;
	int	lowest;
	int	i;
	int	cur_index;

	i = -1;
	lowest = INT32_MAX;
	biggest = INT32_MAX;
	while (++i < to_push)
	{
		cur_index = find_index(array[i], STACK_A, s->n_elem_a);
		if (cur_index < lowest && cur_index != -1)
			lowest = cur_index;
		if (s->n_elem_a - cur_index < biggest && cur_index != -1)
			biggest = s->n_elem_a - cur_index;
	}
	if (lowest < biggest && lowest > -1)
		return (2);
	else
		return (3);
}

int	handle_exceptions(t_stacks *s, int to_push)
{
	if (to_push == 1)
	{
		rotate_a(s);
		s->low_chunk += 1;
		sleep(3);
		return (1);
	}
	return (0);
}

/*
**	Checks if the top of stack is equal to a number from minimal_numbers
**	array, and pushes it on B if it is.
**
**	@return 1 if it is, 0 if it is not 
*/
int	is_in_array(t_stacks *s, int nb_in_array, int *to_push)
{
	if (STACK_A[s->n_elem_a] == nb_in_array)
	{
		push_b(s);
		*to_push -= 1;
		return (1);
	}
	return (0);
}

/*
**  Creates an array with the n biggest or smallest elements of a stack
**
**	@param {int} size
**	@param {int*} stack
**  @param {int} type : or BIGGEST_VALUES or SMALLEST_VALUES (enum)
**  @return malloced array with extreme values
*/
void	divide_stack_a(t_stacks *s)
{
	int	*min_array;
	int	to_push;
	int	i;
	int	next;

	to_push = s->n_elem_a - s->low_chunk + 1;
	if (handle_exceptions(s, to_push))
		return ;
	if (to_push > s->chunk_size)
		to_push = s->chunk_size;
	min_array = find_extreme_numbers (s->chunk_size, STACK_A,
			SMALLEST_VALUES, s);
	while (to_push > 0)
	{
		i = -1;
		while (++i < s->chunk_size)
			if (is_in_array(s, min_array[i], &to_push) == 1)
				break ;
		next = choose_move(s, min_array, s->chunk_size);
		if (i == s->chunk_size && next == 2)
			reverse_rotate_a(s);
		else if (i == s->chunk_size && next == 3)
			rotate_a(s);
	}
	free(min_array);
}
