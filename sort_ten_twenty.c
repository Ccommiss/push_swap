/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ten_twenty.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:03:41 by ccommiss          #+#    #+#             */
/*   Updated: 2021/06/17 14:41:10 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"





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

	if (reverse_sorted_array(STACK_B, s->n_elem_b) && sorted_array(STACK_A, s->n_elem_a)) // TEST POUR TRYDIVIDE
		return ;

	while (pushed_for_later-- > 0)
		push_b(s);
	s->low_chunk += s->n_elem_b + 1;
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
		push_a(s);
	s->high_chunk += s->n_elem_a + 1;
}

