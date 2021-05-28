#include <stdio.h>
#include "pushswap.h"



/**
*
*	function push_a
*
*	@param t_stacks *s
*
*	@return none
*
**/
void 	take_biggest(int *s, int top, int *pivot)
{
	int i;

	i = 0;
	*pivot = INT32_MIN;
	while (i <= top)
	{
		if (s[i] > *pivot)
			*pivot = s[i];
		i++;
	}
}

void 	take_smallest(int *s, int top, int *pivot)
{
	int i;

	i = 0;
	*pivot = INT32_MAX;
	while (i <= top)
	{
		if (s[i] < *pivot)
			*pivot = s[i];
		i++;
	}
}



int calculate_median(int *stack, int n_elems)
{
	int min;
	int max;
	int sum = 0;

	take_biggest(stack, n_elems, &max);
	printf ("Biggest = %d \n", max);
	take_smallest(stack, n_elems, &min);
	printf ("smallest = %d \n", min);

	int j = 0;

	//printf ("HELLO N ELEM = %d\n", n_elems);

	while (min <= max)
	{
		j = 0;
	//	printf ("min = %d\n", min);
		while (j <= n_elems)
		{
			if (min == stack[j])
				sum++;
			//printf ("sum = %d\n", sum);
			j++;
		}
		if (sum >= (n_elems + 1) / 2 && sum > 2) //on rajoute + 1 car ca part de 0, ou + 2 si impair
			return (min);
		min++;
	}
//	printf ("sum = %d\n", sum);
	return (0);
}


int check_lower_than_pivot(int *s, int n_elem, int pivot)
{
	int i;

	i = 0;
	while (i <= n_elem)
	{
		if (s[i] < pivot)
			return TRUE;
		i++;
	}
	return FALSE;
}

int check_higher_than_pivot(int *s, int n_elem, int pivot)
{
	int i; //peeut etre a remplacer par folded index

	i = 0;
	while (i <= n_elem)
	{
		if (s[i] > pivot)
			return TRUE;
		i++;
	}
	return FALSE;
}

void test(t_stacks *s)
{
	int pivot;

	printf("s->n_elem_a = %d \n", s->n_elem_a);
	pivot = calculate_median(STACK_A, s->n_elem_a);

	printf (BGRN"Pivot = %d \n"reset, pivot);
	while (check_lower_than_pivot(STACK_A, s->n_elem_a, pivot) == TRUE && s->n_elem_a >= 3)
	{
		if (s->n_elem_a == 3) // test
			take_smallest(STACK_A, s->n_elem_a, &pivot); //test
		if(STACK_A[s->n_elem_a] < pivot || (STACK_A[s->n_elem_a] == pivot && s->n_elem_a == 3))
			push_b(s);
		else // if (s->n_elem_a > 2)
			rotate_a(s);
	}
	while (s->n_elem_a >= 3)
		test(s);
}

void test_b(t_stacks *s)
{
	int pivot;

	pivot = calculate_median(STACK_B, s->n_elem_b);

	printf (BGRN"Pivot = %d \n"reset, pivot);

	while (check_higher_than_pivot(STACK_B, s->n_elem_b, pivot) == TRUE && s->n_elem_b >= 3)
	{
		if (s->n_elem_b == 3)
			take_biggest(STACK_B, s->n_elem_b, &pivot);
		if(STACK_B[s->n_elem_b] > pivot || (STACK_B[s->n_elem_b] == pivot && s->n_elem_b == 3))
			push_a(s);
		else
			rotate_b(s);
	}
	while (s->n_elem_b >= 3)
		test_b(s);
}


// pour le B on fait linverse, les gros chiffres seront en haut de la pile
void	reverse_sort_three(t_stacks *s)
{
	int min;
	int max;

	s->low_chunk += s->n_elem_b + 1;
	if (s->n_elem_b < 2)
	{
		NOTENOUGH("B")
		return ;
	}
	take_biggest(s->stack_b, s->n_elem_b, &max);
	take_smallest(s->stack_b, s->n_elem_b, &min);
	printf ("B = %d %d \n", min, max);

	// ex : 1 3 2 OU 1 2 3
	if (STACK_B[s->n_elem_b] == min && STACK_B[s->n_elem_b - 2] != max)
	{
		rotate_b(s);
	}
	else if (STACK_B[s->n_elem_b] == min && STACK_B[s->n_elem_b - 2] == max)
	{
		swap_b(s);
		reverse_rotate_b(s);
	}
	//si max en haut
	// ex. 3 1 2
	else if (STACK_B[s->n_elem_b] == max && STACK_B[s->n_elem_b - 2] != min)
	{
		swap_b(s);
		rotate_b(s);
	}
	// ex . 3 2 1
	else if (STACK_B[s->n_elem_b] == max && STACK_B[s->n_elem_b - 2] == min)
	{
		//ok
	}
	//si med n haut
	// ex 2 1 3
	else if (STACK_B[s->n_elem_b] != min && STACK_B[s->n_elem_b - 2] == max)
	{
		reverse_rotate_b(s);
	}
	// ex 2 3 1
	else if (STACK_B[s->n_elem_b] != max && STACK_B[s->n_elem_b - 2] == min)
	{
		swap_b(s);
	}
	//s->low_chunk += 3;

}





void	sort_three(t_stacks *s)
{
	int min;
	int max;

	s->high_chunk += s->n_elem_a + 1; //plus un car part de 0

	if (s->n_elem_a == 1)
	{
		if (s->stack_a[s->n_elem_a] > s->stack_a[0])
			swap_a(s);
		return ;
	}
	if (s->n_elem_a < 1)
	{
		NOTENOUGH("A")
		return ;
	}
	take_biggest(s->stack_a, s->n_elem_a, &max);
	take_smallest(s->stack_a, s->n_elem_a, &min);
	printf ("%d %d \n", min, max);

	//si min deja en haut : soit trie, soit
	// ex : 1 3 2
	if (s->stack_a[s->n_elem_a] == min && s->stack_a[s->n_elem_a - 2] != max)
	{
		reverse_rotate_a(s);
		swap_a(s);
	}

	//si max en haut
	// ex. 3 1 2
	else if (s->stack_a[s->n_elem_a] == max && s->stack_a[s->n_elem_a - 2] != min)
	{
		rotate_a(s);
	}
	// ex . 3 2 1
	else if (s->stack_a[s->n_elem_a] == max && s->stack_a[s->n_elem_a - 2] == min)
	{
		swap_a(s);
		reverse_rotate_a(s);
	}

	//si med n haut
	// ex 2 1 3
	else if (s->stack_a[s->n_elem_a] != min && s->stack_a[s->n_elem_a - 2] == max)
	{
		swap_a(s);
	}
	// ex 2 3 1
	else if (s->stack_a[s->n_elem_a] != max && s->stack_a[s->n_elem_a - 2] == min)
	{
		reverse_rotate_a(s);
	}
	//s->high_chunk += 3;

}


void 	insert_blocks_on_a(t_stacks *s)
{
	int max;
	int i;

	i = 0;
	if (s->n_elem_b == -1)
		return ;
	//int tmp = 3;
	int tmp = s->n_elem_a + 1; // test, c le nb elements nvellement tries

	take_biggest(STACK_B, s->n_elem_b, &max);
	while (STACK_B[s->n_elem_b] != max)
	{
		rotate_b(s); //on remonte la pile
	}
	printf ("HIGH CHUNK HERE  = %d\n", s->high_chunk);
	while (i < s->high_chunk - tmp) // on retranche les tous mneufs, avant g mis 3
	{
		push_a(s); // on bouge sur A tous les gros elements d'abord
		i++;
	}
	i = 0;
	while (i < s->high_chunk - tmp) // on retranche les tout neufs ; au debut g mis trois, essayer avec n elems
	{
		rotate_a(s); // on met les + gros elements deja tries en dessous de la pile
		i++;
	}
	i = 0;
	while (i < s->low_chunk)
	{
	 	push_a(s); // on met tous les low chunks sur le dessus
	 	i++;
	}
}

void 	insert_blocks_on_b(t_stacks *s)
{
	//int min;
	int i;

	i = 0;
	if (s->n_elem_a == -1)
		return ;

	//int tmp = 3;
	int tmp = s->n_elem_b + 1;
	while (i < s->high_chunk + s->low_chunk - tmp) //on remonte toute la pile
	{
		reverse_rotate_a(s); //on remonte la pile
		i++;
	}
	i = 0;
	while (i < s->low_chunk - tmp) //on push les petits ...
	{
		push_b(s);
	 	i++;
	}
	i = 0;
	while (i < s->low_chunk - tmp)// et on les mets en dessous de la pile B
	{
		rotate_b(s);
		i++;
	}

	i = 0;

	while (i < s->high_chunk) //on retranche les trois derniers tries
	{
	 	push_b(s); // on met les gros au dessus de la pile
		i++;
	}
}

int is_sorted(t_stacks *s)
{
	int i;

	i = 1;
	while (i <= s->n_elem_a)
	{
		if (STACK_A[i] < STACK_A[i - 1])
			i++;
		else
			return FALSE;
	}
	return TRUE;
}

int finish(t_stacks *s)
{
	if (s->n_elem_b != -1)
		return FALSE;

	int i;

	i = 1;
	while (i <= s->n_elem_a)
	{
		if (STACK_A[i] < STACK_A[i - 1])
			i++;
		else
			return FALSE;
	}
	return TRUE;

}

int is_reverse_sorted(t_stacks *s)
{
	if (s->n_elem_a != -1 || !is_sorted(s))
		return FALSE;

	int i;

	i = 1;
	while (i <= s->n_elem_b)
	{
		if (STACK_B[i] > STACK_B[i - 1])
			i++;
		else
			return FALSE;
	}
	return TRUE;
}

int create_stacks(t_stacks *s, int elems)
{
	s->stack_a = (int *)malloc(sizeof(int) * elems);
	if (!s->stack_a)
	{
		//free_stacks(s);
		return (FALSE);
	}
	s->n_elem_a = -1; // top de la list
	s->stack_b = (int *)malloc(sizeof(int) * elems);
	if (!s->stack_b)
	{
		//free_stacks(s);
		return (FALSE);
	}
	s->n_elem_b = -1; //idem
	s->low_chunk = 0;
	s->high_chunk = 0;
	return (TRUE);
}

void 	push_all(t_stacks *s)
{
	int i;

	i = 0;
	while (i <= s->n_elem_b)
		push_a(s);
}

void boucle_test(t_stacks *s)
{
	s->verbose = TRUE;
	while (!finish(s))
	{
		printf (BRED"TEST\n"reset);
		test(s);
		printf (BRED"SORT\n"reset);
		sort_three(s);
		printf (BRED"INSERT A\n"reset);
		insert_blocks_on_a(s);


		if (!finish(s))
		{
			printf (BRED"B --- TEST\n"reset);
			test_b(s);
			printf (BRED"B -- REVERSE SORT\n"reset);
			reverse_sort_three(s);
			printf (BRED"B -- INSERT\n"reset);
			insert_blocks_on_b(s);
		}
		if (is_reverse_sorted(s))
		{
			VERBOSE = FALSE;
			//exit(0);
			push_all(s);
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
	copy = (int *)malloc(sizeof(int) * s->n_elem_a);

	i = 0;
	j = 0;
	while (i < s->n_elem_a)
	{
		copy[i] = STACK_A[i];
		j = 0;
		while (j <= i)
		{
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



	}
}
