#include <stdio.h>
#include <ctype.h>
#include "pushswap.h"

void	boucle_test(t_stacks *s)
{
	int	i;

	i = 1;
	s->chunk_size = 10;
	while (!finish(s))
	{
		divide_a(s);
		sort_ten(s);
		if (finish(s))
			break ;
		insert_blocks_on_a(s);
		if (finish(s))
			break ;
		divide_b(s);
		reverse_sort_ten(s);
		insert_blocks_on_b(s);
		i++;
	}
}

/*
**	Algo "sort and back"
**	Takes the chunk_size lowest unsorted numbers, push and sort them on stack B.
**	Once sorted, numbers are pushed back at the bottom of A.
*/
void	algo_sort_and_back(t_stacks *s)
{
	int	i;

	i = 0;
	while (!finish(s))
	{
		divide_stack_a(s);
		clear_a(s);
		sort_b_on_a(s);
		if (s->n_elem_a >= s->chunk_size)
			pushback_on_a(s);
		else
			sort_ten(s);
		if (sorted_array(s->a, s->n_elem_a)
			&& reverse_sorted_array(s->b, s->n_elem_b))
			push_all(s);
		i++;
	}
}

/*
**	Divides the stack A in two equal parts, stores the other half on stack B
**		> Biggest numbers are stored on A
**		> Lowest numbers are stored on B
**	"Insertion sort" like algorithm to sort stack A, then stack B
**	Pushes back lowest reversed sort numbers from stack B on stack A
*/
void	algo_two_stacks(t_stacks *s)
{
	divide_once(s);
	sort_ten(s);
	reverse_sort_ten(s);
	if (sorted_array(s->a, s->n_elem_a)
		&& reverse_sorted_array(s->b, s->n_elem_b))
		push_all(s);
	print_arrays(s);
}

/*
**	Choose the most efficient algorithm in function of 
**	numbers of numbers
*/
void	choose_algo(t_stacks *s, int nb)
{
	int	i;

	i = 0;
	if (nb <= 5)
		boucle_test(s);
	else if (nb < 80)
		algo_two_stacks(s);
	else if (nb >= 80)
	{
		if (nb <= 150)
			s->chunk_size = 25;
		else if (nb > 150 && nb < 350)
			s->chunk_size = 50;
		else
			s->chunk_size = 60;
		algo_sort_and_back(s);
	}
}

int	main(int ac, char **argv)
{
	t_stacks	s;

	create_stacks(&s, ac);
	s.verbose = FALSE;
	argv = argv + 1;
	ac = ac - 2;
	fill_stack(&s, ac, argv);
	check_errors(&s);
	choose_algo(&s, ac + 1);
	free_stacks(&s);
}
