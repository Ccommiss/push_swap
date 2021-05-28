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
		printf("checking %d \n",s[i] );
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
		printf("checking %d \n",s[i] );
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
	s->low_chunk += 3;
}





void	sort_three(t_stacks *s)
{
	int min;
	int max;

	if (s->n_elem_a < 2)
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
	s->high_chunk += 3;
}


void 	insert_blocks_on_a(t_stacks *s)
{
	int max;
	int i;

	i = 0;
	take_biggest(STACK_B, s->n_elem_b, &max);
	while (STACK_B[s->n_elem_b] != max)
	{
		rotate_b(s); //on remonte la pile
	}
	while (i < s->high_chunk - 3) // on retranche les tous mneufs
	{
		push_a(s); // on bouge sur A tous les gros elements d'abord
		i++;
	}
	i = 0;
	while (i < s->high_chunk - 3) // on retranche les tout neufs
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
	//take_smallest(STACK_A, s->n_elem_a, &min);
//	int tmp = STACK_A[2]; // le dernier trie
	while (i < s->high_chunk + s->low_chunk - 3) //on remonte toute la pile
	{
		reverse_rotate_a(s); //on remonte la pile
		i++;
	}
	i = 0;
	while (i < s->low_chunk - 3) //on push les petits ...
	{
		push_b(s);
	 	i++;
	}
	i = 0;
	while (i < s->low_chunk - 3)// et on les mets en dessous de la pile B
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
	// i = 0;
	// while (i < s->high_chunk)
	// {
	// 	push_b(s);
	// 	i++;
	// }
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

int main(int ac, char **argv)
{
	t_stacks s;

	create_stacks(&s, ac);
	s.verbose = FALSE;
	argv = argv + 1; //pour avoid le a.out
	ac = ac - 2; //pour eviter le null + on enleve un car on a enleve un a argv
	while (ac >= 0)
	{
		s.n_elem_a++;
		s.stack_a[s.n_elem_a] = atoi(argv[ac]);
		printf("%d : %s\n", s.n_elem_a, argv[ac]);
		ac--;
	}




	s.verbose =TRUE;
	print_arrays(&s);
	//s.verbose =FALSE;

printf("coucou\n");
	char buf[10];
	while (1)
	{
		gets(buf);
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
		else if (strcmp(buf, "test") == 0)
		{
			test(&s);
			printf("BEGINNING SORT 3\n");
			sort_three(&s);

			test_b(&s);
			reverse_sort_three(&s);
			insert_blocks_on_b(&s);

			test(&s);
			sort_three(&s);
			// // // printf("coucou\n");
			insert_blocks_on_a(&s);

			test_b(&s);
			reverse_sort_three(&s);
			insert_blocks_on_b(&s);

			test(&s);
			sort_three(&s);
			// // // printf("coucou\n");
			insert_blocks_on_a(&s);

			test_b(&s);
			reverse_sort_three(&s);
			insert_blocks_on_b(&s);

			test(&s);
			sort_three(&s);
			// // // printf("coucou\n");
			insert_blocks_on_a(&s);





		}
		else if (strcmp(buf, "test b") == 0)
		{
			test_b(&s);
			reverse_sort_three(&s);

		}



	}
}
