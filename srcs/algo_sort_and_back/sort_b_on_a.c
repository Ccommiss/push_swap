/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_on_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:42:50 by ccommiss          #+#    #+#             */
/*   Updated: 2021/06/22 13:42:51 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
** Push highest
*/
int	push_highest(t_stacks *s)
{
	int	next;
	int	sorted_items;
	int	max;

	sorted_items = 0;
	while (s->n_elem_b >= 5 && !reverse_sorted_array(s->b, s->n_elem_b))
	{
		take_biggest(s->b, s->n_elem_b, &max);
		next = find_index(max, s->b, s->n_elem_b);
		if (s->b[s->n_elem_b] == max)
		{
			push_a(s);
			sorted_items++;
		}
		else if (next >= s->n_elem_b / 2)
			rotate_b(s);
		else if (next < s->n_elem_b / 2)
			reverse_rotate_b(s);
	}
	return (sorted_items);
}

/*
** Sort B on A
*/
void	sort_b_on_a(t_stacks *s)
{
	int	sorted_items;

	if (s->n_elem_b < 1 || reverse_sorted_array(s->b, s->n_elem_b))
	{
		s->low_chunk += s->n_elem_b + 1;
		return ;
	}
	if (s->n_elem_b == 1)
	{
		if (s->b[s->n_elem_b] < s->b[s->n_elem_b - 1])
			swap_b(s);
		s->low_chunk += s->n_elem_b + 1;
		return ;
	}
	sorted_items = push_highest(s);
	reverse_sort_five(s);
	if (reverse_sorted_array(s->b, s->n_elem_b)
		&& sorted_array(s->a, s->n_elem_a))
		return ;
	s->low_chunk += sorted_items + s->n_elem_b + 1;
}
