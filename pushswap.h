/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:58:33 by ccommiss          #+#    #+#             */
/*   Updated: 2021/06/22 13:38:17 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"
# include "color.h"
# include <strings.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
**	Main struct 
*/
typedef struct s_struct
{
	int		verbose;
	int		*a;
	int		n_elem_a;
	int		*b;
	int		n_elem_b;
	int		high_chunk;
	int		low_chunk;
	int		chunk_size;
	int		op_count;
	int		pa;
	int		pb;
	int		sa;
	int		sb;
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
	int		index_min;
}		t_stacks;

enum e_bool {
	FALSE = 0,
	TRUE = 1
} t_enum;

enum e_type {
	SMALLEST_VALUES = 2,
	BIGGEST_VALUES = 3
};

/*
**	[INIT AND FREE FUNCTIONS]
*/

int		create_stacks(t_stacks *s, int elems);
void	free_stacks(t_stacks *s);
void	fill_stack(t_stacks *s, int ac, char **argv);
int		check_errors(t_stacks *s);
int		finish(t_stacks *s);

/*
**	[DEBUG AND VERBOSE OPTION DISPLAYS]
*/

void	print_array(char which_stack, int *stack, int top);
void	print_arrays(t_stacks *s);
void	print_stats(t_stacks *s, int args);

/*
** 	[MOVES]
*/

void	push_a(t_stacks *s);
void	push_b(t_stacks *s);
void	rotate_a(t_stacks *s);
void	rotate_b(t_stacks *s);
void	reverse_rotate_a(t_stacks *s);
void	reverse_rotate_b(t_stacks *s);
void	swap_a(t_stacks *s);
void	swap_b(t_stacks *s);
void	push_all(t_stacks *s);

/**
*	? Computing functions
**/

int		calculate_median(int *stack, int n_elems, int size);
void	take_smallest(int *s, int top, int *pivot);
void	take_biggest(int *s, int top, int *pivot);
int		find_next(int *stack, int pivot, int top, char id);
int		find_index(int nb, int *array, int top);
int		check_lower_than_pivot(int *s, int n_elem, int pivot);
int		check_higher_than_pivot(int *s, int n_elem, int pivot);
void	find_biggest(t_stacks *s, int **array, int *stack);
void	find_smallest(t_stacks *s, int **array, int *stack);
int		*find_extreme_numbers(int size, int *stack, int type, t_stacks *s);

/*
**  Sorting : generic functions
*/

int		reverse_sorted_array(int *array, int n);
int		sorted_array(int *array, int n);
void	sort_three(t_stacks *s);
void	sort_five(t_stacks *s);
void	sort_ten(t_stacks *s);
void	reverse_sort_three(t_stacks *s);
void	reverse_sort_five(t_stacks *s);
void	reverse_sort_ten(t_stacks *s);

/*
**  Sorting : algo_weird
*/

void	insert_blocks_on_a(t_stacks *s);
void	insert_blocks_on_b(t_stacks *s);
void	divide_a(t_stacks *s);
void	divide_b(t_stacks *s);

/*
**  Sorting : algo sort and back
*/

void	divide_stack_a(t_stacks *s);
void	clear_a(t_stacks *s);
void	sort_b_on_a(t_stacks *s);
void	pushback_on_a(t_stacks *s);

/*
**  Sorting : algo two_stacks
*/

void	divide_once(t_stacks *s);

#endif
