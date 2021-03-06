/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ten_twenty.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:03:41 by ccommiss          #+#    #+#             */
/*   Updated: 2021/06/22 13:37:58 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	reverse_sort_ten(t_stacks *s)
{
	int	max;
	int	pushed_for_later;

	pushed_for_later = 0;
	while (s->n_elem_b >= 5 && !reverse_sorted_array(s->b, s->n_elem_b))
	{
		take_biggest(s->b, s->n_elem_b, &max);
		if (s->b[s->n_elem_b] == max)
		{
			push_a(s);
			pushed_for_later++;
		}
		else if (find_index(max, s->b, s->n_elem_b) >= s->n_elem_b / 2)
			rotate_b(s);
		else
			reverse_rotate_b(s);
	}
	reverse_sort_five(s);
	if (sorted_array(s->a, s->n_elem_a)
		&& reverse_sorted_array(s->b, s->n_elem_b)
		&& (s->b[s->n_elem_b] < s->a[s->n_elem_a]))
		return ;
	while (pushed_for_later-- > 0)
		push_b(s);
	s->low_chunk += s->n_elem_b + 1;
}

void	sort_ten(t_stacks *s)
{
	int	pushed_for_later;
	int	min;

	pushed_for_later = 0;
	while (s->n_elem_a >= 5 && !sorted_array(s->a, s->n_elem_a))
	{
		take_smallest(s->a, s->n_elem_a, &min);
		if (s->a[s->n_elem_a] == min)
		{
			pushed_for_later++;
			push_b(s);
		}
		else if (find_index(min, s->a, s->n_elem_a) >= s->n_elem_a / 2)
			rotate_a(s);
		else
			reverse_rotate_a(s);
	}
	sort_five(s);
	while (pushed_for_later-- > 0)
		push_a(s);
	s->high_chunk += s->n_elem_a + 1;
}
