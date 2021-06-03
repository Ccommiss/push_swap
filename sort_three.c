#include "pushswap.h"

/**
 *	Reverse sort the second stack (biggest nb = on top of stack)
 *
 *	@param {t_stacks*} our main structure's pointer
 **/
void	reverse_sort_three(t_stacks *s)
{
	int min;
	int max;

	if (s->chunk_size == 3)
		s->low_chunk += s->n_elem_b + 1; // A REMETTRE SI 3 
	if (s->n_elem_b < 1)
	{
		//NOTENOUGH("B")
		return ;
	}
	if (s->n_elem_b == 1)
	{
		if (STACK_B[s->n_elem_b] < STACK_B[s->n_elem_b - 1])
			swap_b(s);
		return ;
	}
	take_biggest(s->stack_b, s->n_elem_b, &max);
	take_smallest(s->stack_b, s->n_elem_b, &min);
	printf ("B = %d %d \n", min, max);

	// ex : 1 3 2 OU 1 2 3
	if (STACK_B[s->n_elem_b] == min && STACK_B[s->n_elem_b - 2] != max)
	{
		rotate_b(s);
	}
	else if (STACK_B[s->n_elem_b] == min && STACK_B[s->n_elem_b - 2] == max)
	{
		swap_b(s);
		reverse_rotate_b(s);
	}
	//si max en haut
	// ex. 3 1 2
	else if (STACK_B[s->n_elem_b] == max && STACK_B[s->n_elem_b - 2] != min)
	{
		swap_b(s);
		rotate_b(s);
	}
	// ex . 3 2 1
	else if (STACK_B[s->n_elem_b] == max && STACK_B[s->n_elem_b - 2] == min)
	{
		//ok
	}
	//si med n haut
	// ex 2 1 3
	else if (STACK_B[s->n_elem_b] != min && STACK_B[s->n_elem_b - 2] == max)
	{
		reverse_rotate_b(s);
	}
	// ex 2 3 1
	else if (STACK_B[s->n_elem_b] != max && STACK_B[s->n_elem_b - 2] == min)
	{
		swap_b(s);
	}
	//s->low_chunk += 3;

}




/**
 *	Sort the first stack (smallest nb = on top of stack)
 *
 *	@param {t_stacks*} our main structure's pointer
 **/
void	sort_three(t_stacks *s)
{
	int min;
	int max;

	if (s->chunk_size == 3)
		s->high_chunk += s->n_elem_a + 1; //plus un car part de 0

	if (s->n_elem_a == 1)
	{
		if (s->stack_a[s->n_elem_a] > s->stack_a[0])
			swap_a(s);
		return ;
	}
	if (s->n_elem_a < 1)
	{
		NOTENOUGH("A")
		return ;
	}
	take_biggest(s->stack_a, s->n_elem_a, &max);
	take_smallest(s->stack_a, s->n_elem_a, &min);
	printf ("%d %d \n", min, max);

	//si min deja en haut : soit trie, soit
	// ex : 1 3 2
	if (s->stack_a[s->n_elem_a] == min && s->stack_a[s->n_elem_a - 2] != max)
	{
		reverse_rotate_a(s);
		swap_a(s);
	}

	//si max en haut
	// ex. 3 1 2
	else if (s->stack_a[s->n_elem_a] == max && s->stack_a[s->n_elem_a - 2] != min)
	{
		rotate_a(s);
	}
	// ex . 3 2 1
	else if (s->stack_a[s->n_elem_a] == max && s->stack_a[s->n_elem_a - 2] == min)
	{
		swap_a(s);
		reverse_rotate_a(s);
	}

	//si med n haut
	// ex 2 1 3
	else if (s->stack_a[s->n_elem_a] != min && s->stack_a[s->n_elem_a - 2] == max)
	{
		swap_a(s);
	}
	// ex 2 3 1
	else if (s->stack_a[s->n_elem_a] != max && s->stack_a[s->n_elem_a - 2] == min)
	{
		reverse_rotate_a(s);
	}
	//s->high_chunk += 3;

}



void	reverse_sort_five(t_stacks *s)
{
	int pivot;

	pivot = calculate_median(STACK_B, s->n_elem_b);
	if (s->n_elem_b < 1)
	{
		NOTENOUGH("B")
		s->low_chunk += s->n_elem_b + 1; 
		return ;
	}
	if (s->n_elem_b == 1)
	{
		if (STACK_B[s->n_elem_b] < STACK_B[s->n_elem_b - 1])
			swap_b(s);
		s->low_chunk += s->n_elem_b + 1; 
		return ;
	}
	int pushed_for_later = 0;
	while (check_higher_than_pivot(STACK_B, s->n_elem_b, pivot) == TRUE)
	{
		if (STACK_B[s->n_elem_b] > pivot)
		{
			push_a(s);
			pushed_for_later++;
		}
		else 
			rotate_b(s);
	}
	if (pushed_for_later >= 2 && s->n_elem_a >= 1 && STACK_A[s->n_elem_a] > STACK_A[s->n_elem_a - 1])
		swap_a(s); // on inserera tjrs le plus gros en derneir 

	reverse_sort_three(s);
	while (pushed_for_later-- > 0)
		push_b(s);


	s->low_chunk += s->n_elem_b + 1; 
}



void	sort_five(t_stacks *s)
{
	int pivot;

	pivot = calculate_median(STACK_A, s->n_elem_a);
	
	while (check_lower_than_pivot(STACK_A, s->n_elem_a, pivot) == TRUE)
	{
		//if (s->n_elem_a == 3)
		//	take_smallest(STACK_A, s->n_elem_a, &pivot); //test
		printf ("pivot = %d \n", pivot);
		if (STACK_A[s->n_elem_a] < pivot)
			push_b(s);
		else 
			rotate_a(s);
	}
	if (s->n_elem_b >= 1 && STACK_B[s->n_elem_b] < STACK_B[s->n_elem_b - 1])
		swap_b(s); // on inserera tjrs le plus leger en derneir 

	sort_three(s);
	push_a(s);
	push_a(s);
	printf ("HIGH CHUNK BEFORE  = %d\n", s->high_chunk);

	s->high_chunk += s->n_elem_a + 1;
	printf ("HIGH CHUNK AFTER  = %d\n", s->high_chunk);
}
