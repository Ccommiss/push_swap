#include <stdio.h>
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
	VERBOSE = FALSE;
	int i = 1;

	s->chunk_size = 100;
	while (!finish(s))
	{

		printf(BWHT "\n\nTOUR %d \n\n" reset, i);

		printf(BRED "TEST\n" reset);
		divide_a(s);
		print_stats(s);
		VERBOSE = TRUE;
		print_arrays(s);
		VERBOSE = FALSE;

		printf(BRED "SORT\n" reset);
		// if (s->chunk_size == 3)
		// 	sort_three(s);
		// if (s->chunk_size == 5)
		// 	sort_five(s);
		// if (s->chunk_size == 10)
		// 	sort_ten(s);
		// if (s->chunk_size == 20)
		// 	sort_twenty(s);
		// if (s->chunk_size == 40)
		// 	sort_forty(s);
		// if (s->chunk_size == 60)
		// 	sort_sixty(s);
		// if (s->chunk_size == 100)
		// 	sort_hundred(s);

		print_stats(s);

		VERBOSE = TRUE;
		print_arrays(s);

		VERBOSE = FALSE;


		printf(BRED "INSERT A\n" reset);
		insert_blocks_on_a(s);
		print_stats(s);

		VERBOSE = TRUE;
		print_arrays(s);
		VERBOSE = FALSE;


		if (!finish(s))
		{
			printf(BRED "B --- TEST\n" reset);
			divide_b(s);
			print_stats(s);

			VERBOSE = TRUE;
			print_arrays(s);
			VERBOSE = FALSE;

			// printf(BRED "B -- REVERSE SORT\n" reset);
			// if (s->chunk_size == 3)
			// 	reverse_sort_three(s);
			// if (s->chunk_size == 5)
			// 	reverse_sort_five(s);
			// if (s->chunk_size == 10)
			// 	reverse_sort_ten(s);
			// if (s->chunk_size == 20)
			// 	reverse_sort_twenty(s);
			// if (s->chunk_size == 40)
			// 	reverse_sort_forty(s);
			// if (s->chunk_size == 60)
			// 	reverse_sort_sixty(s);
			// if (s->chunk_size == 100)
			// 	reverse_sort_hundred(s);

			print_stats(s);
			//sleep(10);
				VERBOSE = TRUE;
		print_arrays(s);
		sleep(10);
		VERBOSE = FALSE;


			printf(BRED "B -- INSERT\n" reset);
			if (!is_reverse_sorted(s))
			{
				insert_blocks_on_b(s);
				print_stats(s);
				//sleep(10);
			}
			else
			{
				VERBOSE = FALSE;
				push_all(s);
			}

			if (is_reverse_sorted(s)) //tous les elems de B sont tries a lenveers, ceux de A ok ou bien 0 elems dans A
			{
				VERBOSE = FALSE;
				push_all(s);
			}
			i++;
		}
	}
}




/*
**	Algo "sort and back"
**	Takes the chunk_size lowest unsorted numbers, push and sort them on stack B.
**	Once sorted, numbers are pushed back at the bottom of A.
*/
void algo_sort_and_back(t_stacks *s)
{
	printf ("Sort and back launcheed !\n");
	int i = 0;
	s->chunk_size = 50; //
	VERBOSE = FALSE;
	while (!finish(s))
	{
		printf(BWHT "TOUR %d\n\n" reset, i);
		printf(BRED "DIVIDE S A \n" reset);
		divide_stack_a(s);
		//clear stack A
		clear_a(s);
		sort_b_on_a(s);
		if (is_reverse_sorted(s))
			push_all(s);
		printf(BRED "PUSH BACK \n" reset);
		if (s->n_elem_a >= s->chunk_size)
		{
			printf("%d ->> \n", s->n_elem_a);
			pushback_on_a(s);
		}
		else {
			printf ("triggered :) \n\n");
			sort_ten(s);
		}

		if (is_reverse_sorted(s)){
			printf ("triggered \n\n");
			push_all(s);
		}
		//sleep(10);
		print_stats(s);
		print_stats(s);
		//sleep(5);
		i++;
		print_arrays(s);
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
	s->chunk_size = 60;
	divide_once(s);
	sort_ten(s);
	reverse_sort_ten(s);
	if (is_reverse_sorted(s))
		push_all(s);
	print_arrays(s);
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
			return(0);
		}
	}
}
