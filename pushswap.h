/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:58:33 by ccommiss          #+#    #+#             */
/*   Updated: 2021/06/21 18:22:01 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include "libft/libft.h"
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Regular text
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

//Regular bold text
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

#define reset "\e[0m"
#define STACK_B s->stack_b
#define STACK_A s->stack_a
#define VERBOSE s->verbose

typedef struct s_struct
{
	int		verbose;
	int		*stack_a;
	int		n_elem_a;
	int		*stack_b;
	int		n_elem_b;
	int		high_chunk;
	int		low_chunk;

	int		chunk_size;

	int		op_count;
	int pa;
	int pb;
	int sa;
	int sb;
	int ra;
	int rra;
	int rb;
	int rrb;

	int index_min;

}		t_stacks;

enum bool {
	FALSE = 0,
	TRUE = 1
} t_enum;

enum type {
	SMALLEST_VALUES = 2,
	BIGGEST_VALUES = 3
};


/*
**
**
*/
void 	print_array(char which_stack, int *stack, int top);
void	print_arrays(t_stacks *s);
int		check_errors(t_stacks *s);
void	print_stats(t_stacks *s, int args);


/*
**
** 	[MOVES]
**
*/

void 	push_a(t_stacks *s);
void 	push_b(t_stacks *s);
void 	rotate_a(t_stacks *s);
void 	rotate_b(t_stacks *s);
void 	reverse_rotate_a(t_stacks *s);
void 	reverse_rotate_b(t_stacks *s);
void 	swap_a(t_stacks *s);
void 	swap_b(t_stacks *s);


/**
*	? Computing functions
**/

int		calculate_median(int *stack, int n_elems, int size);
void 	take_smallest(int *s, int top, int *pivot);
void 	take_biggest(int *s, int top, int *pivot);
int		find_next(int *stack, int pivot, int top, char id);
int		find_index(int nb, int *array, int top);



/*
**
**  Sorting
**
*/

int		reverse_sorted_array(int *array, int n);
int		sorted_array(int *array, int n);
void	sort_three(t_stacks *s);
void	sort_five(t_stacks *s);
void	sort_ten(t_stacks *s);
void	sort_ten(t_stacks *s);
void	sort_twenty(t_stacks *s);
void	sort_forty(t_stacks *s);
void	sort_sixty(t_stacks *s);
void	sort_hundred(t_stacks *s);

void	reverse_sort_three(t_stacks *s);
void	reverse_sort_five(t_stacks *s);
void	reverse_sort_ten(t_stacks *s);
void	reverse_sort_twenty(t_stacks *s);
void	reverse_sort_forty(t_stacks *s);
void	reverse_sort_sixty(t_stacks *s);

void	reverse_sort_hundred(t_stacks *s);

void 	insert_blocks_on_a(t_stacks *s);
void 	insert_blocks_on_b(t_stacks *s);
void	divide_a(t_stacks *s);
void	divide_b(t_stacks *s);






// OPTION 2

void clear_a(t_stacks *s);
void	sort_b_on_a(t_stacks *s);
void 	pushback_on_a(t_stacks *s);
int calculate_median_stackA(t_stacks *s);
int check_lower_than_pivot(int *s, int n_elem, int pivot);
int check_higher_than_pivot(int *s, int n_elem, int pivot);


void divide_stack_a(t_stacks *s);

//option 3 :
void 	divide_once(t_stacks *s);


void		find_biggest(t_stacks *s, int **array, int *stack);
void		find_smallest(t_stacks *s, int **array, int *stack);
int		*find_extreme_numbers(int size, int *stack, int type, t_stacks *s);



int		is_sorted(t_stacks *s);
int		is_reverse_sorted(t_stacks *s);
int		finish(t_stacks *s);
int		create_stacks(t_stacks *s, int elems);
void	free_stacks(t_stacks *s);
void	fill_stack(t_stacks *s, int ac, char **argv);

#endif

