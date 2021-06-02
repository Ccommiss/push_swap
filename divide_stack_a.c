#include "pushswap.h"


//Fichier pour l'option une pile



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
	//printf ("HELLO N ELEM = %d\n", n_elems);
	while (min <= max)
	{	//	printf ("min = %d\n", min);
		j = 0;
		while (j <= s->n_elem_a)
		{
			if (min == STACK_A[j])
				sum++; 	//printf ("sum = %d\n", sum);
			j++;
		}
		if (sum >= (s->n_elem_a + 1) / 2 && sum > 2) //on rajoute + 1 car ca part de 0, ou + 2 si impair
			return (min);
		min++;
	}
//	printf ("sum = %d\n", sum);
	return (0);
}

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

void		find_3_smallest(t_stacks *s, int **array)
{
	int i;
	i = -1;

	array[0][0] = INT32_MAX;
	array[0][1] = INT32_MAX;
	array[0][2] = INT32_MAX;
	//printf ("INDEX MIN = %d \n\n", s->index_min);
	while (++i <= s->n_elem_a)
	{
		printf ("testing %d \n", STACK_A[i]);
		if (STACK_A[i] < array[0][0] && STACK_A[i] != array[0][1]
		&& STACK_A[i] != array[0][2] &&
		(i > s->index_min || i < s->index_min - s->low_chunk - s->high_chunk))
			array[0][0] = STACK_A[i];
	}
	i = -1;
	while (++i <= s->n_elem_a)
	{
		printf ("testing %d \n", STACK_A[i]);
		if (STACK_A[i] < array[0][1] && STACK_A[i] != array[0][0] &&
		(i > s->index_min || i < s->index_min - s->low_chunk - s->high_chunk))
			array[0][1] = STACK_A[i];
	}
	i = -1;
	while (++i <= s->n_elem_a)
	{
		printf ("testing %d \n", STACK_A[i]);
		if (STACK_A[i] < array[0][2] && STACK_A[i] != array[0][0] &&
		STACK_A[i] != array[0][1] &&
		(i > s->index_min || i < s->index_min - s->low_chunk - s->high_chunk))
			array[0][2] = STACK_A[i];
	}
}


int 	choose_move(t_stacks *s, int *array)
{
	int index1;
	int index2;
	int index3;

	int lowest_index;
	int highest_index;

	index1 = find_index(array[0], STACK_A, s->n_elem_a);
	index2 = find_index(array[1], STACK_A, s->n_elem_a);
	index3 = find_index(array[2], STACK_A, s->n_elem_a);

	if (index1 < index2 && index1 < index2)
		lowest_index = index1;
	if (index2 < index1 && index2 < index3)
		lowest_index = index2;
	if (index3 < index2 && index3 < index1)
		lowest_index = index3;

	if (index1 > index2 && index1 > index2)
		highest_index = index1;
	if (index2 > index1 && index2 > index3)
		highest_index = index1;
	if (index3 > index2 && index3 > index1)
		highest_index = index1;

	if (s->n_elem_a - lowest_index > highest_index)
		return 2; //reverse rotate
	else
		return 1; //rotate
}

void divide_stack_a(t_stacks *s)
{
	int unsorted;
	unsorted = s->n_elem_a - s->low_chunk + 1;
	if (unsorted == 1)
	{
		rotate_a(s);
		exit(0);
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
	int to_push = 3; //est variable mais on se base la dessus
	min_array = malloc(sizeof(int) * 3);
	print_arrays(s);

	find_3_smallest(s, &min_array);
	int good_move;
	good_move = choose_move(s, min_array);


	printf ("Lowest values are : %d, %d, %d \n", min_array[0], min_array[1], min_array[2]);

	while (to_push > 0)
	{

		if (STACK_A[s->n_elem_a] != min_array[0]
		&& STACK_A[s->n_elem_a] != min_array[1]
		&& STACK_A[s->n_elem_a] != min_array[2])
		{
			if (good_move == 1)
				rotate_a(s);
			else
				reverse_rotate_a(s);
		}
		else
		{
			push_b(s);
			to_push--;
		}
	}
}


