/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:38:49 by ccommiss          #+#    #+#             */
/*   Updated: 2021/06/15 11:39:08 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
**	- Rotate A -
**
**	First becomes last, all items are pushed towards the top.
**	@param {t_stacks *} stack
**	@returns none
*/
void rotate_a(t_stacks *s)
{
	DEBUG("RA");
	int tmp;
	int i;

	i = s->n_elem_a;
	if (i < 1)
	{
		NOTENOUGH("A");
		return;
	}
	tmp = s->stack_a[s->n_elem_a];
	while (i > 0)
	{
		s->stack_a[i] = s->stack_a[i - 1];
		i--;
	}
	s->stack_a[0] = tmp;
	print_arrays(s);
	s->op_count++;
	s->ra++;
}

/*
**	- Rotate B -
**
** 	First becomes last, all items are pushed towards the top.
**	@param {t_stacks *} stack
**	@returns none
*/
void rotate_b(t_stacks *s)
{
	DEBUG("RB");
	int tmp;
	int i;

	if (s->n_elem_b < 1)
	{
		NOTENOUGH("B");
		return;
	}
	i = s->n_elem_b;
	tmp = s->stack_b[s->n_elem_b];
	while (i > 0)
	{
		s->stack_b[i] = s->stack_b[i - 1];
		i--;
	}
	s->stack_b[0] = tmp;
	print_arrays(s);
	s->op_count++;
	s->rb++;
}

/*
**	RRA : last item become first, all elems are pushed toward the bottom.
** 	@param {t_stacks *} stack
** 	@returns none
*/
void reverse_rotate_a(t_stacks *s)
{
	DEBUG("RRA");
	int tmp;
	int i;

	i = 0;
	if (s->n_elem_a < 1)
	{
		NOTENOUGH("A");
		return;
	}
	tmp = s->stack_a[0];
	while (i < s->n_elem_a)
	{
		s->stack_a[i] = s->stack_a[i + 1];
		i++;
	}
	s->stack_a[s->n_elem_a] = tmp;
	print_arrays(s);
	s->op_count++;
	s->rra++;
}

/*
**	RRB : last item become first, all elems are pushed toward the bottom.
** 	@param {t_stacks *} stack
** 	@returns none
*/
void reverse_rotate_b(t_stacks *s)
{
	DEBUG("RRB");
	int tmp;
	int i;

	i = 0;
	if (s->n_elem_b < 1)
	{
		NOTENOUGH("B");
		return;
	}
	tmp = s->stack_b[0]; //on save l'element du top de la stack
	while (i < s->n_elem_b)
	{
		s->stack_b[i] = s->stack_b[i + 1];
		i++;
	}
	s->stack_b[s->n_elem_b] = tmp;
	print_arrays(s);
	s->op_count++;
	s->rrb++;
}