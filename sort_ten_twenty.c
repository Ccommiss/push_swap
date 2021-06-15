#include "pushswap.h"



int		reverse_sorted_array(int *array, int n)
{
	while (n > 0)
	{
		if (array[n] > array[n - 1])
			n--;
		else
			return FALSE;
	}
	return TRUE;
}

int		sorted_array(int *array, int n)
{
	while (n > 0)
	{
		if (array[n] < array[n - 1])
			n--;
		else
			return FALSE;
	}
	return TRUE;
}


void	reverse_sort_hundred(t_stacks *s)
{
	int pivot;
	int max;

	pivot = calculate_median(STACK_B, s->n_elem_b, 0);
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
	int next;
	while (s->n_elem_b >= 60) // on met les 20 plus gros sur A dans l;ordre
	{
		take_biggest(STACK_B, s->n_elem_b, &max);
		next = find_index(max, STACK_B, s->n_elem_b);
		if (STACK_B[s->n_elem_b] == max)
		{
			push_a(s);
			pushed_for_later++;
		}
		else if (next >= s->n_elem_b / 2)
			rotate_b(s);
		else if (next < s->n_elem_b / 2)
			reverse_rotate_b(s);
	}
	reverse_sort_sixty(s);

	// if (reverse_sorted_array(STACK_B, s->n_elem_b) && sorted_array(STACK_A, s->n_elem_a)) // TEST
	// 	return ;

	while (pushed_for_later-- > 0)
		push_b(s);
	if (s->chunk_size == 100)
	s->low_chunk += s->n_elem_b + 1;
}










void	reverse_sort_sixty(t_stacks *s)
{
	int pivot;
	int max;

	pivot = calculate_median(STACK_B, s->n_elem_b, 0);
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
	int next;
	while (s->n_elem_b >= 40) // on met les 20 plus gros sur A dans l;ordre
	{
		take_biggest(STACK_B, s->n_elem_b, &max);
		next = find_index(max, STACK_B, s->n_elem_b);
		if (STACK_B[s->n_elem_b] == max)
		{
			push_a(s);
			pushed_for_later++;
		}
		else if (next >= s->n_elem_b / 2)
			rotate_b(s);
		else if (next < s->n_elem_b / 2)
			reverse_rotate_b(s);
	}
	reverse_sort_forty(s);

	// if (reverse_sorted_array(STACK_B, s->n_elem_b) && sorted_array(STACK_A, s->n_elem_a)) // TEST
	// 	return ;

	while (pushed_for_later-- > 0)
		push_b(s);
	if (s->chunk_size == 60)
	s->low_chunk += s->n_elem_b + 1;
}




void	reverse_sort_forty(t_stacks *s)
{
	int pivot;
	int max;

	pivot = calculate_median(STACK_B, s->n_elem_b, 0);
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
	int next;
	while (s->n_elem_b >= 20 && !reverse_sorted_array(STACK_B, s->n_elem_b)) // on met les 20 plus gros sur A dans l;ordre
	{
		take_biggest(STACK_B, s->n_elem_b, &max);
		next = find_index(max, STACK_B, s->n_elem_b);
		if (STACK_B[s->n_elem_b] == max)
		{
			push_a(s);
			pushed_for_later++;
		}
		else if (next >= s->n_elem_b / 2)
			rotate_b(s);
		else if (next < s->n_elem_b / 2)
			reverse_rotate_b(s);
	}
	reverse_sort_twenty(s);

	// if (reverse_sorted_array(STACK_B, s->n_elem_b) && sorted_array(STACK_A, s->n_elem_a)) // TEST
	// 	return ;

	while (pushed_for_later-- > 0)
		push_b(s);
	if (s->chunk_size == 40 || s->chunk_size == 50 ) // TEST
	s->low_chunk += s->n_elem_b + 1;
}


void	reverse_sort_twenty(t_stacks *s)
{
	int pivot;
	int max;
	int next;

	pivot = calculate_median(STACK_B, s->n_elem_b, 0);
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
	while (s->n_elem_b >= 10) // on met les 10 plus gros sur A dans l;ordre
	{
		take_biggest(STACK_B, s->n_elem_b, &max);
		next = find_index(max, STACK_B, s->n_elem_b);
		if (STACK_B[s->n_elem_b] == max)
		{
			push_a(s);
			pushed_for_later++;
		}
		else if (next >= s->n_elem_b / 2)
			rotate_b(s);
		else if (next < s->n_elem_b / 2)
			reverse_rotate_b(s);
	}
	reverse_sort_ten(s);

	// if (reverse_sorted_array(STACK_B, s->n_elem_b) && sorted_array(STACK_A, s->n_elem_a)) // TEST
	// 	return ;
	while (pushed_for_later-- > 0)
		push_b(s);
	if (s->chunk_size == 20)
	s->low_chunk += s->n_elem_b + 1;
}

void	reverse_sort_ten(t_stacks *s)
{
	int pivot;
	int max;
	int next;

	pivot = calculate_median(STACK_B, s->n_elem_b, 0);
	if (s->n_elem_b < 1 || reverse_sorted_array(STACK_B, s->n_elem_b))
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
	while (s->n_elem_b >= 5 && !reverse_sorted_array(STACK_B, s->n_elem_b)) // on met les cinq plus gros sur A dans l;ordre
	{
		printf ("coucou la mif ten\n");
		take_biggest(STACK_B, s->n_elem_b, &max);
		next = find_index(max, STACK_B, s->n_elem_b);

		if (STACK_B[s->n_elem_b] == max)
		{
			push_a(s);
			pushed_for_later++;
		}
		else if (next >= s->n_elem_b / 2)
			rotate_b(s);
		else if (next < s->n_elem_b / 2)
			reverse_rotate_b(s);
	}
	reverse_sort_five(s);

	// if (reverse_sorted_array(STACK_B, s->n_elem_b) && sorted_array(STACK_A, s->n_elem_a)) // TEST POUR TRYDIVIDE
	// 	return ;

	while (pushed_for_later-- > 0)
		push_b(s);

	if (s->chunk_size == 10)
	s->low_chunk += s->n_elem_b + 1;
}



void	sort_hundred(t_stacks *s)
{
	int pivot;
	int pushed_for_later;
	int min;
	int next;

	pivot = calculate_median(STACK_A, s->n_elem_a, 0);
	pushed_for_later = 0;
	while (s->n_elem_a >= 60)
	{
		take_smallest(STACK_A, s->n_elem_a, &min);
		next = find_index(min, STACK_A, s->n_elem_a);
		if (STACK_A[s->n_elem_a] == min)
		{
			pushed_for_later++;
			push_b(s);
		}
		else if (next >= s->n_elem_a / 2)
			rotate_a(s);
		else
			reverse_rotate_a(s);
	}
	sort_sixty(s);
	while (pushed_for_later-- > 0)
	{
		push_a(s);
	}
	printf ("HIGH CHUNK BEFORE  = %d\n", s->high_chunk);
	if (s->chunk_size == 100)
		s->high_chunk += s->n_elem_a + 1;
	printf ("HIGH CHUNK AFTER  = %d\n", s->high_chunk);
}




void	sort_sixty(t_stacks *s)
{
	int pivot;
	int pushed_for_later;
	int min;
	int next;

	pivot = calculate_median(STACK_A, s->n_elem_a, 0);
	pushed_for_later = 0;
	while (s->n_elem_a >= 40)
	{
		take_smallest(STACK_A, s->n_elem_a, &min);
		next = find_index(min, STACK_A, s->n_elem_a);
		if (STACK_A[s->n_elem_a] == min)
		{
			pushed_for_later++;
			push_b(s);
		}
		else if (next >= s->n_elem_a / 2)
			rotate_a(s);
		else
			reverse_rotate_a(s);
	}
	sort_forty(s);
	while (pushed_for_later-- > 0)
	{
		push_a(s);
	}
	printf ("HIGH CHUNK BEFORE  = %d\n", s->high_chunk);
	if (s->chunk_size == 60)
		s->high_chunk += s->n_elem_a + 1;
	printf ("HIGH CHUNK AFTER  = %d\n", s->high_chunk);
}




void	sort_forty(t_stacks *s)
{
	int pivot;
	int pushed_for_later;
	int min;
	int next;

	pivot = calculate_median(STACK_A, s->n_elem_a, 0);
	pushed_for_later = 0;
	while (s->n_elem_a >= 20)
	{
		take_smallest(STACK_A, s->n_elem_a, &min);
		next = find_index(min, STACK_A, s->n_elem_a);
		if (STACK_A[s->n_elem_a] == min)
		{
			pushed_for_later++;
			push_b(s);
		}
		else if (next >= s->n_elem_a / 2)
			rotate_a(s);
		else
			reverse_rotate_a(s);
	}
	sort_twenty(s);
	while (pushed_for_later-- > 0)
	{
		push_a(s);
	}
	printf ("HIGH CHUNK BEFORE  = %d\n", s->high_chunk);
	if (s->chunk_size == 40 || s->chunk_size == 50 ) // TEST
		s->high_chunk += s->n_elem_a + 1;
	printf ("HIGH CHUNK AFTER  = %d\n", s->high_chunk);
}



void	sort_twenty(t_stacks *s)
{
	int pivot;
	int pushed_for_later;
	int min;
	int next;

	pivot = calculate_median(STACK_A, s->n_elem_a, 0);
	pushed_for_later = 0;
	while (s->n_elem_a >= 10)
	{
		take_smallest(STACK_A, s->n_elem_a, &min);
		next = find_index(min, STACK_A, s->n_elem_a);
		if (STACK_A[s->n_elem_a] == min)
		{
			pushed_for_later++;
			push_b(s);
		}
		else if (next >= s->n_elem_a / 2)
			rotate_a(s);
		else
			reverse_rotate_a(s);
	}
	sort_ten(s);
	while (pushed_for_later-- > 0)
	{
		push_a(s);
	}
	printf ("HIGH CHUNK BEFORE  = %d\n", s->high_chunk);
	if (s->chunk_size == 20)
		s->high_chunk += s->n_elem_a + 1;
	printf ("HIGH CHUNK AFTER  = %d\n", s->high_chunk);
}


void	sort_ten(t_stacks *s)
{
	int pivot;
	int pushed_for_later;
	int min;
	int next;

	if (sorted_array(STACK_A, s->n_elem_a))
	{
		if (s->chunk_size == 10)
			s->high_chunk += s->n_elem_a + 1;
		return ;
	}

	pivot = calculate_median(STACK_A, s->n_elem_a, 0);
	pushed_for_later = 0;
	while (s->n_elem_a >= 5 && !sorted_array(STACK_A, s->n_elem_a))
	{
		take_smallest(STACK_A, s->n_elem_a, &min);
		next = find_index(min, STACK_A, s->n_elem_a);
		if (STACK_A[s->n_elem_a] == min)
		{
			pushed_for_later++;
			push_b(s);
		}
		else if (next >= s->n_elem_a / 2)
			rotate_a(s);
		else
			reverse_rotate_a(s);
	}
	sort_five(s);
	while (pushed_for_later-- > 0)
	{
		push_a(s);
	}
	printf ("HIGH CHUNK BEFORE  = %d\n", s->high_chunk);
	if (s->chunk_size == 10)
		s->high_chunk += s->n_elem_a + 1;
	printf ("HIGH CHUNK AFTER  = %d\n", s->high_chunk);
}
