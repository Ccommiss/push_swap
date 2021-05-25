#include "pushswap.h"

void push_a(t_stacks *s)
{
	DEBUG("PUSH A");
	printf("prend le premier élément au sommet de B et le met sur A.\nNe fait rien si B est vide.\n\n");
	if (s->n_elem_b == -1)
	{
		NOTENOUGH("B");
		return;
	}
	// -> push haut de la pile A sur haut de la pile B

	s->n_elem_a++; //on prepare le top de la pile B a recevoir en ajoutant +1 dindex
	s->stack_a[s->n_elem_a] = s->stack_b[s->n_elem_b];
	s->n_elem_b--;
	//la pile b peut etre decrementee
	print_arrays(s);
}

void push_b(t_stacks *s)
{
	DEBUG("PUSH B");
	printf("prend le premier élément au sommet de A et le met sur B.\nNe fait rien si A est vide.\n\n");

	if (s->n_elem_a == -1)
	{
		NOTENOUGH("A");
		return ;
	}
	// push haut de la pile A sur haut de la pile B

	s->n_elem_b++; //on prepare le top de la pile B a recevoir en ajoutant +1 dindex
	s->stack_b[s->n_elem_b] = s->stack_a[s->n_elem_a];
	s->n_elem_a--;
	//la pile a peut etre decrementee
	print_arrays(s);
}

void swap_b(t_stacks *s)
{
	DEBUG("SWAP B");
	printf("intervertit les 2 premiers éléments au sommet de la pile B. \nNe fait rien s’il n’y en a qu’un ou aucun.\n");
	int tmp;
	if (s->n_elem_b < 1)
	{
		NOTENOUGH("B");
		return;
	}
	tmp = s->stack_b[s->n_elem_b];
	s->stack_b[s->n_elem_b] = s->stack_b[s->n_elem_b - 1];
	s->stack_b[s->n_elem_b - 1] = tmp;
	print_arrays(s);
}

void swap_a(t_stacks *s)
{
	DEBUG("SWAP A");
	printf("intervertit les 2 premiers éléments au sommet de la pile A. \nNe fait rien s’il n’y en a qu’un ou aucun.\n");
	int tmp;

	if (s->n_elem_a < 1)
	{
		NOTENOUGH("A");
		return;
	}
	tmp = s->stack_a[s->n_elem_a];
	s->stack_a[s->n_elem_a] = s->stack_a[s->n_elem_a - 1];
	s->stack_a[s->n_elem_a - 1] = tmp;
	print_arrays(s);
}