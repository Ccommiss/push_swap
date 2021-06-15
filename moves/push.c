/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:16:04 by ccommiss          #+#    #+#             */
/*   Updated: 2021/06/15 15:25:58 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
**  Push top of A on top of B, or nothing if B is empty
**  @param stack *s
**  @return none
*/
void push_a(t_stacks *s)
{
	DEBUG("PUSH A");
	if (s->n_elem_b == -1)
	{
		NOTENOUGH("B");
		return ;
	}
	s->n_elem_a++; //on prepare le top de la pile B a recevoir en ajoutant +1 dindex
	s->stack_a[s->n_elem_a] = s->stack_b[s->n_elem_b];
	s->n_elem_b--;
	print_arrays(s);
	s->op_count++;
	s->pa++;
	printf("pa\n");
}

/*
**  Prend le premier élément au sommet de A et le met sur B
**  @param stack *s
**  @return none
*/
void push_b(t_stacks *s)
{
	DEBUG("PUSH B");
	if (s->n_elem_a == -1)
	{
		NOTENOUGH("A");
		return ;
	}

	s->n_elem_b++;
	s->stack_b[s->n_elem_b] = s->stack_a[s->n_elem_a];
	s->n_elem_a--;
	print_arrays(s);
	s->op_count++;
	s->pb++;
	printf("pb\n");
}

/*
**  Swap first two elems of stack B
**  @param stack *s
**  @return none
*/
void swap_b(t_stacks *s)
{
	DEBUG("SWAP B");
	int tmp;
	if (s->n_elem_b < 1)
	{
		NOTENOUGH("B");
		return ;
	}
	tmp = s->stack_b[s->n_elem_b];
	s->stack_b[s->n_elem_b] = s->stack_b[s->n_elem_b - 1];
	s->stack_b[s->n_elem_b - 1] = tmp;
	print_arrays(s);
	s->op_count++;
	s->sb++;
	printf("sb\n");
}

/*
**  Swap first two elems of stack A
**  @param stack *s
**  @return none
*/
void swap_a(t_stacks *s)
{
	DEBUG("SWAP A");
	int tmp;

	if (s->n_elem_a < 1)
	{
		NOTENOUGH("A");
		return ;
	}
	tmp = s->stack_a[s->n_elem_a];
	s->stack_a[s->n_elem_a] = s->stack_a[s->n_elem_a - 1];
	s->stack_a[s->n_elem_a - 1] = tmp;
	print_arrays(s);
	s->op_count++;
	s->sa++;
	printf("sa\n");
}
