#include <stdio.h>
#include "pushswap.h"





void 	push_all(t_stacks *s)
{
	int i;

	i = 0;
	while (i <= s->n_elem_b)
		push_a(s);
}

void boucle_test(t_stacks *s)
{
	VERBOSE = TRUE;
	while (!finish(s))
	{
		printf (BRED"TEST\n"reset);
		divide_a(s);
		printf (BRED"SORT\n"reset);
		sort_three(s);
		printf (BRED"INSERT A\n"reset);
		insert_blocks_on_a(s);


		if (!finish(s))
		{
			printf (BRED"B --- TEST\n"reset);
			divide_b(s);
			printf (BRED"B -- REVERSE SORT\n"reset);
			reverse_sort_three(s);
			printf (BRED"B -- INSERT\n"reset);
			if (!is_reverse_sorted(s))
				insert_blocks_on_b(s);
			else
			{
				VERBOSE = FALSE;
				push_all(s);
			}
		}

		if (is_reverse_sorted(s)) //tous les elems de B sont tries a lenveers, ceux de A ok ou bien 0 elems dans A
		{
			VERBOSE = FALSE;
			//exit(0);
			//VERBOSE = TRUE;
			//exit(0);
			push_all(s);
		//	print_arrays(s);
		//	exit(0);
		}
		//VERBOSE = FALSE;
		//VERBOSE = TRUE;
		//print_arrays(s);

	}

}

void check_errors(t_stacks *s)
{
	int *copy;
	int i;
	int j;
	copy = (int *)malloc(sizeof(int) * (s->n_elem_a + 1));

	i = 0;
	j = 0;
	while (i <= s->n_elem_a)
	{
		copy[i] = STACK_A[i];
		j = 0;
		while (j <= i)
		{
			//printf ("index j = copy[%d] = %d -- copy[%d] = %d", j, copy[j], i, copy[i]);
			if (j != i && copy[j] == copy[i])
			{
				printf("Index [%d] and [%d] : value are the same (%d)", j, i, copy[j]);
				exit (0);
			}
			j++;
		}
		i++;

	}


}

void 	boucle_unepile(t_stacks *s)
{
	while (!finish(s))
	{
		printf (BRED"TEST\n"reset);
		divide_a(s);
		printf (BRED"SORT\n"reset);
		sort_three(s);
		printf (BRED"INSERT A\n"reset);
		insert_blocks_on_b(s);
	}

}


int main(int ac, char **argv)
{
	t_stacks s;

	create_stacks(&s, ac);
	s.verbose = FALSE;
	argv = argv + 1; //pour avoid le a.out
	ac = ac - 2; //pour eviter le null + on enleve un car on a enleve un a argv
	int tmp =ac;
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

printf("coucou\n");
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
			printf("ARG = %d // NB OPERATIONS = %d \n", tmp, s.op_count);
		}
		else if (strcmp(buf, "solu2") == 0)
		{
			boucle_unepile(&s);
			print_arrays(&s);
			printf("ARG = %d // NB OPERATIONS = %d \n", tmp, s.op_count);
		}



	}
}
