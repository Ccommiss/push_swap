#include "pushswap.h"

/*
**	Checks if an array is reverse sorted : array[n] should be > to array[n - 1]
**	e.g. highest nb on top of stack
**	@param {int* array} stack to check
**	@param {int n} nb of items to check
**	@return 0 if not reverse sorted, 1 if yes
*/

int finish(t_stacks *s)
{
	if (s->n_elem_b == -1 && sorted_array(STACK_A, 
		s->n_elem_a) == 1)
		return (TRUE);
	return (FALSE);
}

int	reverse_sorted_array(int *array, int n)
{
	while (n > 0)
	{
		if (array[n] > array[n - 1])
			n--;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	sorted_array(int *array, int n)
{
	while (n > 0)
	{
		if (array[n] < array[n - 1])
			n--;
		else
			return (FALSE);
	}
	return (TRUE);
}
