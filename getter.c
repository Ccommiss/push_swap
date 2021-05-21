#include <stdio.h>
#include "pushswap.h"





void push_a(t_stacks *s)
{
	if (s->n_elem_b == -1)
	{
		printf ("Cannot push_a (push top B on top of A) \n: stack B has no elem at this point.\n");
		return;
	}
	// push haut de la pile A sur haut de la pile B

	s->n_elem_a++; //on prepare le top de la pile B a recevoir en ajoutant +1 dindex
	s->stack_b[s->n_elem_a] = s->stack_a[s->n_elem_b];
	s->n_elem_b--;
	//la pile a peut etre decrementee
	print_array('A', s->stack_a, s->n_elem_a);
	print_array('B', s->stack_b, s->n_elem_b);
}


void push_b(t_stacks *s)
{
	if (s->n_elem_a == -1)
	{
		printf ("Cannot push_b (push top A on top of B) \n: stack A has no elem at this point.\n");
		return;
	}
	// push haut de la pile A sur haut de la pile B

	s->n_elem_b++; //on prepare le top de la pile B a recevoir en ajoutant +1 dindex
	s->stack_b[s->n_elem_b] = s->stack_a[s->n_elem_a];
	s->n_elem_a--;
	//la pile a peut etre decrementee
	print_array('A', s->stack_a, s->n_elem_a);
	print_array('B', s->stack_b, s->n_elem_b);
}

void print_array(char which_stack, int *stack, int top)
{


	if (which_stack == 'A')
		printf(BRED);
	else
		printf(BCYN);

	int n;
	printf("\n__________________\n");

	printf("|| STACK %c :    ||", which_stack);
	n = -1;
	while (++n <= top)
	{
		printf("\n||______________||\n|| [%3d] => %3d || ", n, stack[n]);
		if (n == top)
			printf(" <-- top of stack \n||______________||");
	}
	printf("\n" reset);
}

int main(int ac, char **argv)
{
	t_stacks s;

	//create stacks
	s.stack_a = (int *)malloc(sizeof(int) * ac);
	s.n_elem_a = -1; // top de la list
	s.stack_b = (int *)malloc(sizeof(int) * ac);
	s.n_elem_b = -1; //idem

	argv = argv + 1; //pour avoid le a.out

	while (argv[s.n_elem_a + 1] != NULL)
	{
		s.n_elem_a++;
		s.stack_a[s.n_elem_a] = atoi(argv[s.n_elem_a]);
		printf("%d : %s\n", s.n_elem_a, argv[s.n_elem_a]);
	}

	push_b(&s);
	push_b(&s);
//	push_b(&s);
	//push_b(&s);
//	push_b(&s);
//	printf ("push a\n");
	rotate_a(&s);
	reverse_rotate_a(&s);
	//printf(" %s  %s\n", argv[1], argv[2]);
}
