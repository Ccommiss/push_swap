/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:44:12 by ccommiss          #+#    #+#             */
/*   Updated: 2021/06/22 13:44:14 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sort_under_three(t_stacks *s, char stack)
{
	if (stack == 'A')
	{
		if (s->n_elem_a < 1)
			return (1);
		if (s->n_elem_a == 1)
		{
			if (s->a[s->n_elem_a] > s->a[0])
				swap_a(s);
			return (1);
		}
	}
	else
	{
		if (reverse_sorted_array(s->b, s->n_elem_b) || s->n_elem_b < 1)
			return (1);
		if (s->n_elem_b == 1)
		{
			if (s->b[s->n_elem_b] < s->b[s->n_elem_b - 1])
				swap_b(s);
			return (1);
		}
	}
	return (0);
}

/**
 *	Reverse sort the second stack (biggest nb = on top of stack)
 *
 *	@param {t_stacks*} our main structure's pointer
 **/
void	reverse_sort_three(t_stacks *s)
{
	int	min;
	int	max;

	if (sort_under_three(s, 'B'))
		return ;
	take_biggest(s->b, s->n_elem_b, &max);
	take_smallest(s->b, s->n_elem_b, &min);
	if (s->b[s->n_elem_b] == min && s->b[s->n_elem_b - 2] != max)
		rotate_b(s);
	else if (s->b[s->n_elem_b] == min && s->b[s->n_elem_b - 2] == max)
	{
		swap_b(s);
		reverse_rotate_b(s);
	}
	else if (s->b[s->n_elem_b] == max && s->b[s->n_elem_b - 2] != min)
	{
		swap_b(s);
		rotate_b(s);
	}
	else if (s->b[s->n_elem_b] != min && s->b[s->n_elem_b - 2] == max)
		reverse_rotate_b(s);
	else if (s->b[s->n_elem_b] != max && s->b[s->n_elem_b - 2] == min)
		swap_b(s);
}

/**
 *	Sort the first stack (smallest nb = on top of stack)
 *
 *	@param {t_stacks*} our main structure's pointer
 **/
void	sort_three(t_stacks *s)
{
	int	min;
	int	max;

	if (sort_under_three(s, 'A'))
		return ;
	take_biggest(s->a, s->n_elem_a, &max);
	take_smallest(s->a, s->n_elem_a, &min);
	if (s->a[s->n_elem_a] == min && s->a[s->n_elem_a - 2] != max)
	{
		reverse_rotate_a(s);
		swap_a(s);
	}
	else if (s->a[s->n_elem_a] == max && s->a[s->n_elem_a - 2] != min)
		rotate_a(s);
	else if (s->a[s->n_elem_a] == max && s->a[s->n_elem_a - 2] == min)
	{
		swap_a(s);
		reverse_rotate_a(s);
	}
	else if (s->a[s->n_elem_a] != min && s->a[s->n_elem_a - 2] == max)
		swap_a(s);
	else if (s->a[s->n_elem_a] != max && s->a[s->n_elem_a - 2] == min)
		reverse_rotate_a(s);
}

void	reverse_sort_five(t_stacks *s)
{
	int	pushed_for_later;
	int	pivot;

	pushed_for_later = 0;
	if (s->n_elem_b < 1 || reverse_sorted_array(s->b, s->n_elem_b))
		return ;
	while (s->n_elem_b > 2 && !reverse_sorted_array(s->b, s->n_elem_b))
	{
		take_biggest(s->b, s->n_elem_b, &pivot);
		if (s->b[s->n_elem_b] == pivot)
		{
			push_a(s);
			pushed_for_later++;
		}
		else if (find_index(pivot, s->b, s->n_elem_b) >= s->n_elem_b / 2)
			rotate_b(s);
		else
			reverse_rotate_b(s);
	}
	reverse_sort_three(s);
	while (pushed_for_later-- > 0
		&& (!reverse_sorted_array(s->b, s->n_elem_b)
			&& !sorted_array(s->a, s->n_elem_a)))
		push_b(s);
}

void	sort_five(t_stacks *s)
{
	int	pushed_for_later;
	int	pivot;

	pushed_for_later = 0;
	if (s->n_elem_a < 1 || sorted_array(s->a, s->n_elem_a))
		return ;
	while (s->n_elem_a > 2)
	{
		take_smallest(s->a, s->n_elem_a, &pivot);
		if (s->a[s->n_elem_a] == pivot)
		{
			push_b(s);
			pushed_for_later++;
		}
		else if (find_index(pivot, s->a, s->n_elem_a) >= s->n_elem_a / 2)
			rotate_a(s);
		else
			reverse_rotate_a(s);
	}
	if (pushed_for_later >= 2 && s->n_elem_b >= 1
		&& s->b[s->n_elem_b] < s->b[s->n_elem_b - 1])
		swap_b(s);
	sort_three(s);
	while (pushed_for_later-- > 0)
		push_a(s);
}
