#include <stdio.h>
#include <ctype.h>
#include "pushswap.h"

void push_all(t_stacks *s)
{
	int i;

	i = 0;
	while (i <= s->n_elem_b)
		push_a(s);
}

void boucle_test(t_stacks *s)
{
	VERBOSE = TRUE;
	int i = 1;

	s->chunk_size = 10;
	while (!finish(s))
	{

		printf(BWHT "\n\nTOUR %d \n\n" reset, i);
		printf(BRED "DIVIDE A \n" reset);
		divide_a(s);
		if(i>=4) sleep(4);
		printf(BRED "SORT A\n" reset);
		sort_ten(s);
		if(i>=4) sleep(4);
		printf(BRED "INSERT ON A\n" reset);
		insert_blocks_on_a(s);
		if(i>=4) sleep(4);
		if (finish(s))
			break ;
		printf(BRED "DIVIDE B\n" reset);
		divide_b(s);
		if(i>=4) sleep(4);
		printf(BRED "SORT B\n" reset);
		reverse_sort_ten(s);
		if(i>=4) sleep(4);
		printf(BRED "B -- INSERT\n" reset);
		insert_blocks_on_b(s);
		if(i>=4) sleep(4);
		i++;
	}
}

/*
**	Algo "sort and back"
**	Takes the chunk_size lowest unsorted numbers, push and sort them on stack B.
**	Once sorted, numbers are pushed back at the bottom of A.
*/
void algo_sort_and_back(t_stacks *s)
{
	int i = 0;
	s->chunk_size = 10;
	VERBOSE = TRUE;
	while (!finish(s))
	{
		printf(BWHT "TOUR %d\n\n" reset, i);
		printf(BRED "DIVIDE S A \n" reset);
		divide_stack_a(s);
		clear_a(s);
		sort_b_on_a(s);
		printf(BRED "PUSH BACK \n" reset);
		if (s->n_elem_a >= s->chunk_size)
			pushback_on_a(s);
		else
			sort_ten(s);
		if (sorted_array(STACK_A, s->n_elem_a) 
			&& reverse_sorted_array(STACK_B, s->n_elem_b))
			push_all(s);
		print_stats(s);
		print_arrays(s);
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
void algo_two_stacks(t_stacks *s)
{
	VERBOSE = TRUE;
	s->chunk_size = 3;
	divide_once(s);
	sort_ten(s);
	reverse_sort_ten(s);
	if (sorted_array(STACK_A, s->n_elem_a) 
		&& reverse_sorted_array(STACK_B, s->n_elem_b))
		push_all(s);
	print_arrays(s);
}


int		ft_str_is_digit(char *str) //  ametrre dans libft
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if ((!isdigit(str[i]) && str[i] != '-') 
			|| (i != 0 && str[i] == '-'))
			return (0);
		i++;
	}
	return (1);
}

int main(int ac, char **argv)
{
	t_stacks s;

	create_stacks(&s, ac);
	s.verbose = FALSE;
	argv = argv + 1; //pour avoid le a.out
	ac = ac - 2;	 //pour eviter le null + on enleve un car on a enleve un a argv
	int tmp = ac;
	while (ac >= 0)
	{
		s.n_elem_a++;
		if (!ft_str_is_digit(argv[ac]))
		{
			printf ("Args must be numerics.\n");
			exit(0);
		}
		s.stack_a[s.n_elem_a] = atoi(argv[ac]);
		printf("%d : %s\n", s.n_elem_a, argv[ac]);
		ac--;
	}
	check_errors(&s);
	print_arrays(&s);

	char buf[10];
	gets(buf);
	while (1)
	{
		if (strcmp(buf, "show") == 0)
			print_arrays(&s);
		else if (strcmp(buf, "show -a") == 0)
			print_array('A', s.stack_a, s.n_elem_a);
		else if (strcmp(buf, "show -b") == 0)
			print_array('B', s.stack_b, s.n_elem_b);
		else if (strcmp(buf, "-v") == 0)
			s.verbose = TRUE;
		else if (strcmp(buf, "while") == 0)
		{
			boucle_test(&s);
			print_arrays(&s);
			printf("ARG = %d // NB OPERATIONS = %d \n", tmp + 1, s.op_count);
			return (0);
		}
		else if (strcmp(buf, "algo2") == 0)
		{
			algo_two_stacks(&s);
			print_arrays(&s);
			printf("ARG = %d // NB OPERATIONS = %d \n", tmp + 1, s.op_count);
			return 0;
		}
		else if (strcmp(buf, "algo1") == 0)
		{
			printf("yo\n");
			algo_sort_and_back(&s);
			print_arrays(&s);
			printf("ARG = %d // NB OPERATIONS = %d \n", tmp + 1, s.op_count);
			return (0);
		}
	}
}
