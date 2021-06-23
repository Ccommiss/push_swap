/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:16:04 by ccommiss          #+#    #+#             */
/*   Updated: 2021/06/22 13:37:58 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
**  When both stacks are sorted, add all B items on top of A 
**  @param stack *s
*/
void	push_all(t_stacks *s)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = s->n_elem_b;
	while (i <= tmp)
	{
		push_a(s);
		i++;
	}
}

/*
**  Push top of A on top of B, or nothing if B is empty
**  @param stack *s
**  @return none
*/
void	push_a(t_stacks *s)
{
	if (s->n_elem_b == -1)
	{
		printf ("return \n");
		return ;
	}
	s->n_elem_a++;
	s->a[s->n_elem_a] = s->b[s->n_elem_b];
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
void	push_b(t_stacks *s)
{
	if (s->n_elem_a == -1)
		return ;
	s->n_elem_b++;
	s->b[s->n_elem_b] = s->a[s->n_elem_a];
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
void	swap_b(t_stacks *s)
{
	int	tmp;

	if (s->n_elem_b < 1)
		return ;
	tmp = s->b[s->n_elem_b];
	s->b[s->n_elem_b] = s->b[s->n_elem_b - 1];
	s->b[s->n_elem_b - 1] = tmp;
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
void	swap_a(t_stacks *s)
{
	int	tmp;

	if (s->n_elem_a < 1)
		return ;
	tmp = s->a[s->n_elem_a];
	s->a[s->n_elem_a] = s->a[s->n_elem_a - 1];
	s->a[s->n_elem_a - 1] = tmp;
	print_arrays(s);
	s->op_count++;
	s->sa++;
	printf("sa\n");
}
