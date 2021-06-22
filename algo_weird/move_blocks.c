/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_blocks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:43:30 by ccommiss          #+#    #+#             */
/*   Updated: 2021/06/22 13:43:31 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_big_nb(t_stacks *s)
{
	int	max;
	int	tmp;
	int	i;

	tmp = s->n_elem_a + 1;
	i = -1;
	take_biggest(s->b, s->n_elem_b, &max);
	while (s->b[s->n_elem_b] != max && s->high_chunk - tmp != 0)
	{
		if (find_index(max, s->b, s->n_elem_b) >= s->n_elem_b / 2)
			rotate_b(s);
		else
			reverse_rotate_b(s);
	}
	while (++i < s->high_chunk - tmp)
		push_a(s);
}

void	push_small_nb(t_stacks *s)
{
	int	i;
	int	min;

	i = -1;
	take_smallest(s->a, s->n_elem_a, &min);
	while (s->a[s->n_elem_a] != min)
	{
		if (find_index(min, s->a, s->n_elem_a) >= s->n_elem_a)
			rotate_a(s);
		else
			reverse_rotate_a(s);
	}
	i = -1;
	while (++i < s->low_chunk)
		push_a(s);
}

void	insert_blocks_on_a(t_stacks *s)
{
	if (s->n_elem_b == -1)
		return ;
	push_big_nb(s);
	push_small_nb(s);
}

void	insert_blocks_on_b(t_stacks *s)
{
	int	i;
	int	tmp;
	int	block;

	i = -1;
	if (s->n_elem_a == -1)
		return ;
	tmp = s->n_elem_b + 1;
	block = s->high_chunk + s->low_chunk - tmp;
	if (block > s->n_elem_a / 2)
		while (++i <= s->n_elem_a - block)
			rotate_a(s);
	else
		while (++i < s->high_chunk + s->low_chunk - tmp)
			reverse_rotate_a(s);
	i = -1;
	while (++i < s->low_chunk - tmp)
		push_b(s);
	i = -1;
	while (++i < tmp && s->low_chunk - tmp != 0)
		reverse_rotate_b(s);
	i = -1;
	while (++i < s->high_chunk)
		push_b(s);
}
