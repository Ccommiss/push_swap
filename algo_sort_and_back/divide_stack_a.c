#include "pushswap.h"

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
				sum++; //printf ("sum = %d\n", sum);
			j++;
		}
		if (sum >= (s->n_elem_a + 1) / 2 && sum > 2) //on rajoute + 1 car ca part de 0, ou + 2 si impair
			return (min);
		min++;
	}
	return (0);
}

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
**  Finds the n biggest numbers in the stack A and stores them in array.
**		> First step : all nb are set to intmin
**		> Second step : if a nb from stack[i] is found to be > to the one in array,
**			- /!\ stack[i] mustnt be already sorted, so checking that too
**				(index_min = index of the minimal value eg the first value sorted)
**			- checks all previous array[0][k] to check if it has not been already set;
**			- if not, array[0][k] stores this value
**			- if yes, iterating until the next < value found in stack A.
**	 	=> Iterating through this process until all k items of array are set
**		=> All biggest nb, from (k = 0) -> biggest to (k = chunksize) = "lowest of biggest" are set
**
**  @param {t_stacks} s
**  @param {int**} array of size chunk_size
**  @param {int*} stack
*/
void find_biggest(t_stacks *s, int **array, int *stack)
{
	//array = array de taille size_chunk
	int i;
	int k;
	int o;
	int already_here;
	already_here = 0;
	i = 0;
	k = 0;
	o = 0;

	while (k < s->chunk_size)
	{
		array[0][k] = INT32_MIN;
		k++;
	}
	k = 0;
	i = -1;

	while (k < s->chunk_size)
	{
		i = -1;
		while (++i <= s->n_elem_a)
		{
			if (stack[i] > array[0][k] && (i > s->index_min || i < s->index_min - s->low_chunk - s->high_chunk))
			{
				o = 0;
				while (o < s->chunk_size) // a essayer : en fait ici on cherche while o < k car les autres sont pas set
				{
					if (array[0][o] == stack[i])
						already_here = 1;
					o++;
				}
				if (already_here == 0)
					array[0][k] = stack[i];
				already_here = 0;
			}
		}
		k++;
	}
}

/**
 *	_Find the n smallest numbers in the stack A and store them in array
 *
 * 	@param {t_stacks} s
 *	@param {int**} array
 *	@param {int*} stack
**/
void find_smallest(t_stacks *s, int **array, int *stack)
{
	//array = array de taille size_chunk
	int i;
	int k;
	int o;
	int already_here;
	already_here = 0;
	i = 0;
	k = 0;
	o = 0;

	while (k < s->chunk_size)
	{
		array[0][k] = INT32_MAX;
		k++;
	}
	k = 0;
	i = -1;
	while (k < s->chunk_size)
	{
		i = -1;
		while (++i <= s->n_elem_a)
		{
			if (stack[i] < array[0][k] && (i > s->index_min || i < s->index_min - s->low_chunk - s->high_chunk))
			{
				o = 0;
				while (o < s->chunk_size)
				{
					if (array[0][o] == stack[i])
						already_here = 1;
					o++;
				}
				if (already_here == 0)
					array[0][k] = stack[i];
				already_here = 0;
			}
		}
		k++;
	}
}

/**
 *	__Creates an array with the n biggest or smallest elements of a stack
 *
 * 	@param {int} size
 *	@param {int*} stack
 *	@param {int} type : or BIGGEST_VALUES or SMALLEST_VALUES (enum)
 *	@return malloced array with extreme values
**/
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

/**
 *	_Choose move in function of the closest nb
 *
 * 	@param {int*} array containing biggest/lowest nb
 *	@param {int*} stack
**/
int choose_move(t_stacks *s, int *array, int to_push)
{
	int *highest_index;
	int *lowest_index;
	int biggest;
	int lowest;
	int i;

	highest_index = malloc(sizeof(int) * to_push);
	lowest_index = malloc(sizeof(int) * to_push);
	i = 0;
	while (i < to_push) //on cherche l'index brut, le plus petit sera le lowest
	{
		lowest_index[i] = find_index(array[i], STACK_A, s->n_elem_a);
		if (lowest_index[i] == -1)		 // veut dire que pas trouve ici donc que a deja ete trouve dans le tab
			lowest_index[i] = INT32_MAX; //comme ca ca sera pas le plus petit
		i++;
	}
	i = 0;
	while (i < to_push)
	{
		highest_index[i] = s->n_elem_a - lowest_index[i];
		if (lowest_index[i] == INT32_MAX)
			highest_index[i] = INT32_MAX;
		i++;
	}
	take_smallest(lowest_index, to_push - 1, &lowest);	 // le + petit index en partant du bas
	take_smallest(highest_index, to_push - 1, &biggest); // le + petit index en partant du haut
	free(highest_index);
	free(lowest_index);

	printf("lowest index is : %d\n", lowest);
	printf("biggest index is : %d\n", biggest);

	if (lowest < biggest && lowest > -1) //c  mieux daller vers le bas
		return (2);						 //RRA
	else
		return (3); // RA
}

void divide_stack_a(t_stacks *s)
{
	int unsorted;
	unsorted = s->n_elem_a - s->low_chunk + 1;
	if (unsorted == 1)
	{
		rotate_a(s);
		return;
	}
	if (unsorted < 3)
	{
		while (unsorted > 0)
		{
			push_b(s);
			unsorted--;
		}
		return;
	}

	int *min_array;

	int to_push = s->n_elem_a - s->low_chunk + 1;
	if (to_push > s->chunk_size)
		to_push = s->chunk_size;
	min_array = malloc(sizeof(int) * s->chunk_size);
	print_arrays(s);

	find_smallest(s, &min_array, STACK_A);
	int i = 0;

	int next;
	next = choose_move(s, min_array, to_push); // a faire

	//printf ("# smallest are : %d %d %d %d %d ", min_array[0], min_array[1], min_array[2], min_array[3], min_array[4]);
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
			printf("ici \n");
		}
	}
}
