#include <stdio.h>
#include "pushswap.h"

void print_stats(t_stacks *s)
{
	printf("\n\nSTATS :\n");
	printf("SwapA = %d\n", s->sa);
	printf("SwapB = %d\n", s->sb);
	printf("PushA = %d\n", s->pa);
	printf("PushB = %d\n", s->pb);
	printf("RA = %d\n", s->ra);
	printf("RB = %d\n", s->rb);
	printf("RRA = %d\n", s->rra);
	printf("RRB = %d\n", s->rrb);

	printf(BWHT "\n\nTOTAL OPCOUNT => %d\n" reset, s->op_count);
	printf("\n\n_____\n");
	// s->sa = 0;
	// s->sb = 0;
	// s->pa = 0;
	// s->pb = 0;
	// s->ra = 0;
	// s->rb = 0;
	// s->rra = 0;
	// s->rrb = 0;
}

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

	s->chunk_size = 40;
	while (!finish(s))
	{

		printf(BWHT "\n\nTOUR %d \n\n" reset, i);

		printf(BRED "TEST\n" reset);
		divide_a(s);
		print_stats(s);
		//sleep(1);

		printf(BRED "SORT\n" reset);
		if (s->chunk_size == 3)
			sort_three(s);
		if (s->chunk_size == 5)
			sort_five(s);
		if (s->chunk_size == 10)
			sort_ten(s);
		if (s->chunk_size == 20)
			sort_twenty(s);
		if (s->chunk_size == 40)
			sort_forty(s);

		print_stats(s);
		//	sleep(1);

		printf(BRED "INSERT A\n" reset);
		insert_blocks_on_a(s);
		print_stats(s);
		//sleep(5);

		if (!finish(s))
		{
			printf(BRED "B --- TEST\n" reset);
			divide_b(s);
			print_stats(s);
			//exit(0);
			//sleep(5);

			printf(BRED "B -- REVERSE SORT\n" reset);
			if (s->chunk_size == 3)
				reverse_sort_three(s);
			if (s->chunk_size == 5)
				reverse_sort_five(s);
			if (s->chunk_size == 10)
				reverse_sort_ten(s);
			if (s->chunk_size == 20)
				reverse_sort_twenty(s);
			if (s->chunk_size == 40)
				reverse_sort_forty(s);

			print_stats(s);
			//	sleep(5);

			printf(BRED "B -- INSERT\n" reset);
			if (!is_reverse_sorted(s))
			{
				insert_blocks_on_b(s);
				print_stats(s);
				//	sleep(5);
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

			// if (i == 100)
			// {
			// VERBOSE = TRUE;
			// sleep(10);
			// print_arrays(s);
			// exit(0);
			// }
			//	VERBOSE = FALSE;
			i++;
		}
	}
}

void boucle_unepile(t_stacks *s)
{

	int i = 0;
	s->chunk_size = 40;
	//VERBOSE = TRUE;
	while (!finish(s))
	{
		printf(BWHT "TOUR %d\n\n" reset, i);
		//VERBOSE = TRUE;
		//  if (s->op_count >= 20)
		//VERBOSE = FALSE;
		// else
		//VERBOSE = FALSE;
		printf(BRED "DIVIDE S A \n" reset);
		divide_stack_a(s);
		print_stats(s);
		//sleep(5);
		printf(BRED "REVERSE \n" reset);
		if (s->chunk_size == 3)
			reverse_sort_three(s);
		if (s->chunk_size == 5)
			reverse_sort_five(s);
		if (s->chunk_size == 10)
			reverse_sort_ten(s);
		if (s->chunk_size == 20)
			reverse_sort_twenty(s);
		if (s->chunk_size == 40)
			reverse_sort_forty(s);

		print_stats(s);
		//sleep(5);
		printf(BRED "PUSH BACK \n" reset);
		pushback_on_a(s);
		print_stats(s);
		//sleep(5);
		i++;
		print_arrays(s);
	}
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
	//s.verbose =FALSE;
	//boucle_unepile(&s);

	char buf[10];
	while (1)
	{
		gets(buf);
		printf("%s\n", buf);
		if (strcmp(buf, "rra") == 0)
			reverse_rotate_a(&s);
		if (strcmp(buf, "rrb") == 0)
			reverse_rotate_b(&s);
		else if (strcmp(buf, "ra") == 0)
			rotate_a(&s);
		else if (strcmp(buf, "rb") == 0)
			rotate_b(&s);
		else if (strcmp(buf, "pa") == 0)
			push_a(&s);
		else if (strcmp(buf, "pb") == 0)
			push_b(&s);
		else if (strcmp(buf, "sa") == 0)
			swap_a(&s);
		else if (strcmp(buf, "sb") == 0)
			swap_b(&s);
		else if (strcmp(buf, "ss") == 0)
		{
			swap_a(&s);
			swap_b(&s);
		}
		else if (strcmp(buf, "rr") == 0)
		{
			rotate_a(&s);
			rotate_b(&s);
		}
		else if (strcmp(buf, "rrr") == 0)
		{
			reverse_rotate_a(&s);
			reverse_rotate_b(&s);
		}
		else if (strcmp(buf, "show") == 0)
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
		else if (strcmp(buf, "solu2") == 0)
		{
			boucle_unepile(&s);
			print_arrays(&s);
			printf("ARG = %d // NB OPERATIONS = %d \n", tmp + 1, s.op_count);
		}
	}
}
