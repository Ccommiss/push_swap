#include "pushswap.h"

/*
**	Find index of the next lower/higher number from pivot
** 
**	@param {int} top of stack
**	@param {int} pivot
**	@param {int*} stack
**	@param {char} id of stack
**	@return none
*/
int	find_next(int *stack, int pivot, int top, char id)
{
	int	i;
	int	j;

	i = 0;
	j = top;
	if (id == 'B')
	{
		while (i <= top && stack[i] <= pivot)
			i++;
		while (j >= 0 && stack[j] <= pivot)
			j--;
	}
	else if (id == 'A')
	{
		while (i <= top && stack[i] >= pivot)
			i++;
		while (j >= 0 && stack[j] >= pivot)
			j--;
	}
	if (top - j <= i)
		return (j);
	else
		return (i);
	return (-1);
}

/*
** 	Find index of the number on the provided stack
**
** 	@param {int} nb to look for
**	@param {int} top of stack
**	@param {int*} stack
**	@return none
*/
int	find_index(int nb, int *array, int top)
{
	int	i;

	i = 0;
	while (i <= top)
	{
		if (array[i] == nb)
			return (i);
		i++;
	}
	return (-1);
}

/*
** Set the pivot to the biggest nb found
**
** @param {t_stacks*} our main structure's pointer
** @param {int} top of stack
** @param {int*} pivot to be set
*/
void 	take_biggest(int *s, int top, int *pivot)
{
	int	i;

	i = 0;
	*pivot = INT_MIN;
	while (i <= top)
	{
		if (s[i] > *pivot)
			*pivot = s[i];
		i++;
	}
}

/*
** Set the pivot to the smallest nb found
**
** @param {t_stacks*} our main structure's pointer
** @param {int} top of stack
** @param {int*} pivot to be set
*/
void 	take_smallest(int *s, int top, int *pivot)
{
	int	i;

	i = 0;
	*pivot = INT_MAX;
	while (i <= top)
	{
		if (s[i] < *pivot)
			*pivot = s[i];
		i++;
	}
}

/*
**  calculate_median : computes median
**
**	@param {int*} stack array
**	@param {int} numbers of elems
**	@param {int} size : minimum size of nb lower
**	@return {number} median
*/
int	calculate_median(int *stack, int n_elems, int size)
{
	int	min;
	int	max;
	int	j;
	int	sum;

	j = 0;
	sum = 0;
	take_biggest(stack, n_elems, &max);
	take_smallest(stack, n_elems, &min);
	while (min <= max)
	{
		j = -1;
		while (++j <= n_elems)
		{
			if (min == stack[j])
				sum++;
		}
		if (size != 0 && sum > size)
			return (min);
		if (size == 0 && sum >= (n_elems + 1) / 2)
			return (min);
		min++;
	}
	return (0);
}
