/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_once.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:31:32 by ccommiss          #+#    #+#             */
/*   Updated: 2021/06/15 12:31:34 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
**  At very first call, divide the stack A into A and B,
** 	in two equal parts from median.
**  @params {t_stacks*}s
*/
void 	divide_once(t_stacks *s)
{
	int pivot;
	int next;

	pivot = calculate_median(STACK_A, s->n_elem_a, s->n_elem_a / 2 + 1);
	next = find_next(STACK_A, pivot, s->n_elem_a, 'A');
	while (check_lower_than_pivot(STACK_A, s->n_elem_a, pivot) == TRUE)
	{
		//printf ( "pivot = %d \n", pivot);
		if(STACK_A[s->n_elem_a] < pivot)
		{
			push_b(s);
			next = find_next(STACK_A, pivot, s->n_elem_a, 'A');
		//	printf (BRED"NEW NEXT = %d \n"reset, next);
			//print_arrays(s);
		}
		else if (next >= s->n_elem_a / 2) // next est en haut de la pile
			rotate_a(s);
		else // next est en bas de la pile
			reverse_rotate_a(s);
	}

}
