#include "pushswap.h"

/*
** Checks if already here
*/
int	checks_if_exists(t_stacks *s, int **array, int nb_to_check)
{
	int	exists;
	int	o;

	exists = FALSE;
	o = -1;
	while (++o < s->chunk_size)
	{
		if (array[0][o] == nb_to_check)
			exists = TRUE;
	}
	return (exists);
}

/*
**  Finds the n biggest numbers in the stack A and stores them in array.
**		> First step : all nb are set to intmin
**		> Second step : if a nb from stack[i] is found to be > to the one in array,
**			- /!\ stack[i] mustnt be already sorted, so checking that too
**				(index_min = index of the minimal value eg the first value sorted)
**			- checks all previous array[0][k] to check if it has not been already set;
**			- if not, array[0][k] stores this value
**			- if yes, iterating until the next < value found in stack A.
**	 	=> Iterating through this process until all k items of array are set
**		=> All biggest nb, from (k = 0) -> biggest to (k = chunksize) = "lowest
**			of biggest" are set
**
**  @param {t_stacks} s
**  @param {int**} array of size chunk_size
**  @param {int*} stack
*/
void	find_biggest(t_stacks *s, int **array, int *stack)
{
	int	i;
	int	k;

	k = -1;
	while (++k < s->chunk_size)
		array[0][k] = INT32_MIN;
	k = -1;
	while (++k < s->chunk_size)
	{
		i = -1;
		while (++i <= s->n_elem_a)
		{
			if (stack[i] > array[0][k]
				&& (i > s->index_min
					|| i < s->index_min - s->low_chunk - s->high_chunk)
				&& (checks_if_exists(s, array, stack[i]) == FALSE))
				array[0][k] = stack[i];
		}
	}
}

/*
** 	Find the n smallest numbers in the stack A and store them in array
**
** 	@param {t_stacks} s
**	@param {int**} array
**	@param {int*} stack
**
*/
void	find_smallest(t_stacks *s, int **array, int *stack)
{
	int	i;
	int	k;

	k = -1;
	while (++k < s->chunk_size)
		array[0][k] = INT32_MAX;
	k = -1;
	while (++k < s->chunk_size)
	{
		i = -1;
		while (++i <= s->n_elem_a)
		{
			if (stack[i] < array[0][k]
				&& (i > s->index_min
					|| i < s->index_min - s->low_chunk - s->high_chunk)
				&& (checks_if_exists(s, array, stack[i]) == FALSE))
				array[0][k] = stack[i];
		}
	}
}
