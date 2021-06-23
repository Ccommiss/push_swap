/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_once.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:31:32 by ccommiss          #+#    #+#             */
/*   Updated: 2021/06/22 13:37:58 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
**  At very first call, divide the stack A into A and B,
** 	in two equal parts from median.
**  @params {t_stacks*}s
*/
void	divide_once(t_stacks *s)
{
	int	pivot;
	int	next;

	pivot = calculate_median(s->a, s->n_elem_a, s->n_elem_a / 2 + 1);
	next = find_next(s->a, pivot, s->n_elem_a, 'A');
	while (check_lower_than_pivot(s->a, s->n_elem_a, pivot) == TRUE)
	{
		if (s->a[s->n_elem_a] < pivot)
		{
			push_b(s);
			next = find_next(s->a, pivot, s->n_elem_a, 'A');
		}
		else if (next >= s->n_elem_a / 2)
			rotate_a(s);
		else
			reverse_rotate_a(s);
	}
}
