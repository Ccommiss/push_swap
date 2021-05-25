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
	while (i < top)
	{
		printf("checking %d \n",s[i] );
		if (s[i] > *pivot)
			*pivot = s[i];
		i++;
	}
	printf ("new pivot = %d \n", *pivot);
}



void	sort_a();





void test(t_stacks *s)
{
	int pivot;
	int top;

	pivot = 0;
	top = 0;

	while (top < s->n_elem_a )
	{
		pivot += s->stack_a[top];
		top ++;
	}
	//pivot = pivot / s->n_elem_a; // mediane des elems
	if (s->n_elem_a >= 0)
		pivot = s->stack_a[s->n_elem_a/2];
	printf (BGRN"Pivot = %d \n"reset, pivot); // on a trouve le pivot 

	int sorted = FALSE;
	while (sorted == FALSE)
	{

		if (s->n_elem_a >= 0 && s->stack_a[s->n_elem_a] < pivot)
		{
			push_b(s);
			top = s->n_elem_a;
		}
		else 
		{	int i = s->n_elem_a;
			while (i >= 0 && s->stack_a[i] >= pivot)
			{
				printf ("checking %d : %d", i, s->stack_a[i]);
				i--;
			}
			printf (" i = %d \n", i);
			if (i >= 0 && s->stack_a[i] < pivot)
			{
				print_arrays(s);
				if (i > s->n_elem_a/2)
					rotate_a(s);
				else if (i < s->n_elem_a/2)
					reverse_rotate_a(s);
			}
			else if (i == -1)
				sorted = TRUE;
		}			
	}
	//while (s->n_elem_a < 2)
	//	push_a(s);
	//print_arrays(s);
	while (s->n_elem_a >= 3)
		test(s);

	//sort_a(s);	
	

	//take_biggest(s->stack_a, s->n_elem_a, &pivot);
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

test(&s);

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
	}
}
