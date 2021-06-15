#include "pushswap.h"

/**
 *		_Checks if the array still contains numbers lower than provided one
 *		@param {int*}s : the stack or array we want to look in
 *		@param {int} n : the nb of elems we need to check
 *		@param {int} pivot : the pivot nb
 *		@return : false if no nb < pivot, true if yes
 **/
int		check_lower_than_pivot(int *s, int n_elem, int pivot)
{
	int i;

	i = 0;
	while (i <= n_elem)
	{
		if (s[i] < pivot)
			return TRUE;
		i++;
	}
	return FALSE;
}

/**
 *		_Checks if the array still contains numbers higher than provided one
 *		@param {int*}s : the stack or array we want to look in
 *		@param {int} n : the nb of elems we need to check
 *		@param {int} pivot : the pivot nb
 *		@return : false if no nb < pivot, true if yes
 **/
int check_higher_than_pivot(int *s, int n_elem, int pivot)
{
	int i; //peeut etre a remplacer par folded index

	i = 0;
	while (i <= n_elem)
	{
		if (s[i] > pivot)
			return TRUE;
		i++;
	}
	return FALSE;
}

/**
 *		_Recursively divides A and keeps the lower part from median, until
 *		_the number of elems equals to chunk size
 *		@params {t_stacks*}s
 **/
void divide_a(t_stacks *s)
{
	int pivot;
	int next;
	int to_push;

	//printf("s->n_elem_a = %d VS 2 * chunk = %d \n\n", s->n_elem_a, 2 * s->chunk_size);
	if (s->n_elem_a < 2 * s->chunk_size)
		to_push = s->n_elem_a - s->chunk_size;
	else
		to_push = 0;

	pivot = calculate_median(STACK_A, s->n_elem_a, to_push);

	next = find_next(STACK_A, pivot, s->n_elem_a, 'A');

	//printf (BGRN"Pivot = %d \n"reset, pivot);

//	while (check_lower_than_pivot(STACK_A, s->n_elem_a, pivot) == TRUE && s->n_elem_a >= 3)
	while (check_lower_than_pivot(STACK_A, s->n_elem_a, pivot) == TRUE || s->n_elem_a == s->chunk_size)
	{
		//printf ( "pivot = %d \n", pivot);
		if (s->n_elem_a == s->chunk_size)
		{
			take_smallest(STACK_A, s->n_elem_a, &pivot); //test
			next = find_index(pivot, STACK_A, s->n_elem_a); //test !!
		}
		if(STACK_A[s->n_elem_a] < pivot || (STACK_A[s->n_elem_a] == pivot && s->n_elem_a == s->chunk_size))
		{
			//printf ("coucou \n");
			push_b(s);
			next = find_next(STACK_A, pivot, s->n_elem_a, 'A');
				//printf (BRED"NEW NEXT = %d \n"reset, next);
			//print_arrays(s);
		}
		else if (next >= s->n_elem_a / 2) // next est en haut de la pile
			rotate_a(s);
		else // next est en bas de la pile
			reverse_rotate_a(s);
	}
	//while (s->n_elem_a >= 3)
	while (s->n_elem_a >= s->chunk_size)
		divide_a(s);
}


/**
 *		_Recursively divides B and keeps the lower part from median, until
 *		_the number of elems equals to chunk size
 *		@params {t_stacks*}s
 **/
void divide_b(t_stacks *s)
{
	int pivot;
	int next;

	int to_push;

	if (s->n_elem_b < s->chunk_size)
		return ;
	if (s->n_elem_b < 2 * s->chunk_size)
		to_push = s->chunk_size;
	else
		to_push = 0;


	//printf ("TO PUSH = %d \n", to_push);
	pivot = calculate_median(STACK_B, s->n_elem_b, to_push);
	next = find_next(STACK_B, pivot, s->n_elem_b, 'B');

	//printf (BGRN"Pivot = %d \n"reset, pivot);
	//sleep(5);
	//print_arrays(s);

	//while (check_higher_than_pivot(STACK_B, s->n_elem_b, pivot) == TRUE && s->n_elem_b >= 3)
	while (check_higher_than_pivot(STACK_B, s->n_elem_b, pivot) == TRUE || s->n_elem_b == s->chunk_size)
	{
		//printf ("pivot = %d \n\n\n", pivot);
		//(1);
		if (s->n_elem_b == s->chunk_size)
		{
			take_biggest(STACK_B, s->n_elem_b, &pivot);
			//printf (BGRN"Pivot = %d \n"reset, pivot);
			next = find_index(pivot, STACK_B, s->n_elem_b);
		}
		//if(STACK_B[s->n_elem_b] > pivot || (STACK_B[s->n_elem_b] == pivot && s->n_elem_b == 3))
		if(STACK_B[s->n_elem_b] > pivot || (STACK_B[s->n_elem_b] == pivot && s->n_elem_b == s->chunk_size))
		{
			push_a(s);
			next = find_next(STACK_B, pivot, s->n_elem_b, 'B');
		}
		else if (next >= s->n_elem_b / 2) // next est en haut de la pile
			rotate_b(s);
		else if (next < s->n_elem_b / 2) // next est en bas de la pile
			reverse_rotate_b(s);
	}
	//while (s->n_elem_b >= 3)
	while (s->n_elem_b >= s->chunk_size)
		divide_b(s);
}


