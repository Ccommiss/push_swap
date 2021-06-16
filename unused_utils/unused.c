#include "pushswap.h"

/*
** Functions unused but could be useful – originally used in push and back algo
*/

/*
**	Checks if lower
**
**	@param {int*} stack
**	@return median
**
*/
int check_lower_than_pivot_range(t_stacks *s, int pivot)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (i <= s->n_elem_a)
	{
		if (STACK_A[i] < pivot &&
			(i > s->index_min || i < s->index_min - s->low_chunk - s->high_chunk))
			nb++;
		i++;
	}
	return nb;
}

/*
**	Find the median of stack A
**
**	@param {int*} stack
** 	@return median
*/
int calculate_median_stackA(t_stacks *s)
{
	int min = INT32_MAX;
	int max = INT32_MIN;
	int sum = 0;

	int i = 0;
	while (i < s->n_elem_a)
	{
		if (STACK_A[i] > max &&
			(i > s->index_min || i < s->index_min - s->low_chunk - s->high_chunk))
			max = STACK_A[i];
		if (STACK_A[i] < min &&
			(i > s->index_min || i < s->index_min - s->low_chunk - s->high_chunk))
			min = STACK_A[i];
		i++;
	}
	int j = 0;
	while (min <= max)
	{
		j = 0;
		while (j <= s->n_elem_a)
		{
			if (min == STACK_A[j])
				sum++;
			j++;
		}
		if (sum >= (s->n_elem_a + 1) / 2 && sum > 2) //on rajoute + 1 car ca part de 0, ou + 2 si impair
			return (min);
		min++;
	}
	return (0);
}


