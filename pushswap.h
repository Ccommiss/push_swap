/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:58:33 by ccommiss          #+#    #+#             */
/*   Updated: 2021/06/01 13:49:09 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

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

#define DEBUG(string) printf(BWHT"*** OPERATION == %s \n"reset, string);
#define NOTENOUGH(string) printf(YEL"⚠ Not enough elems in %s \n\n"reset, string);
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

	int		op_count;

	int index_min;

}		t_stacks;

enum bool {
	FALSE = 0,
	TRUE = 1
};


void 	print_array(char which_stack, int *stack, int top);
void	print_arrays(t_stacks *s);

/**
*	? MOVES
**/

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

int		calculate_median(int *stack, int n_elems);
void 	take_smallest(int *s, int top, int *pivot);
void 	take_biggest(int *s, int top, int *pivot);
int		find_next(int *stack, int pivot, int top, char id);
int		find_index(int nb, int *array, int top);

/**
 * ? Sorting
 **/

void	sort_three(t_stacks *s);
void	reverse_sort_three(t_stacks *s);
void 	insert_blocks_on_a(t_stacks *s);
void 	insert_blocks_on_b(t_stacks *s);
void	divide_a(t_stacks *s);
void	divide_b(t_stacks *s);


int		is_sorted(t_stacks *s);
int		is_reverse_sorted(t_stacks *s);
int		finish(t_stacks *s);
int		create_stacks(t_stacks *s, int elems);
#endif

