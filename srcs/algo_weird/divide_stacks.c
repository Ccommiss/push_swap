/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:43:25 by ccommiss          #+#    #+#             */
/*   Updated: 2021/06/22 13:43:26 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_or_rotate_a(t_stacks *s, int pivot)
{
	int	next;

	next = 0;
	if (s->n_elem_a == s->chunk_size)
	{
		take_smallest(s->a, s->n_elem_a, &pivot);
		next = find_index(pivot, s->a, s->n_elem_a);
	}
	if (s->a[s->n_elem_a] < pivot
		|| (s->a[s->n_elem_a] == pivot && s->n_elem_a == s->chunk_size))
	{
		push_b(s);
		next = find_next(s->a, pivot, s->n_elem_a, 'A');
	}
	else if (next >= s->n_elem_a / 2)
		rotate_a(s);
	else
		reverse_rotate_a(s);
}

/*
**  Recursively divides A and keeps the lower part from median, until
**	the number of elems equals to chunk size
**  @params {t_stacks*}s
*/
void	divide_a(t_stacks *s)
{
	int	pivot;
	int	next;
	int	to_push;

	if (s->n_elem_a < 2 * s->chunk_size)
		to_push = s->n_elem_a - s->chunk_size;
	else
		to_push = 0;
	pivot = calculate_median(s->a, s->n_elem_a, to_push);
	next = find_next(s->a, pivot, s->n_elem_a, 'A');
	while (check_lower_than_pivot(s->a, s->n_elem_a, pivot) == TRUE
		|| s->n_elem_a == s->chunk_size)
	{
		push_or_rotate_a(s, pivot);
	}
	while (s->n_elem_a >= s->chunk_size)
		divide_a(s);
}

void	push_or_rotate_b(t_stacks *s, int pivot)
{
	int	next;

	next = 0;
	if (s->n_elem_b == s->chunk_size)
	{
		take_biggest(s->b, s->n_elem_b, &pivot);
		next = find_index(pivot, s->b, s->n_elem_b);
	}
	if (s->b[s->n_elem_b] > pivot || (s->b[s->n_elem_b] == pivot
			&& s->n_elem_b == s->chunk_size))
	{
		push_a(s);
		next = find_next(s->b, pivot, s->n_elem_b, 'B');
	}
	else if (next >= s->n_elem_b / 2)
		rotate_b(s);
	else if (next < s->n_elem_b / 2)
		reverse_rotate_b(s);
}

/**
 *		_Recursively divides B and keeps the lower part from median, until
 *		_the number of elems equals to chunk size
 *		@params {t_stacks*}s
 **/
void	divide_b(t_stacks *s)
{
	int	pivot;
	int	next;
	int	to_push;

	if (s->n_elem_b < s->chunk_size)
		return ;
	if (s->n_elem_b < 2 * s->chunk_size)
		to_push = s->chunk_size;
	else
		to_push = 0;
	pivot = calculate_median(s->b, s->n_elem_b, to_push);
	next = find_next(s->b, pivot, s->n_elem_b, 'B');
	while (check_higher_than_pivot(s->b, s->n_elem_b, pivot) == TRUE
		|| s->n_elem_b == s->chunk_size)
	{
		push_or_rotate_b(s, pivot);
	}
	while (s->n_elem_b >= s->chunk_size)
		divide_b(s);
}
