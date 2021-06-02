#include "pushswap.h"

void push_a(t_stacks *s)
{
	DEBUG("PUSH A");
	//printf("prend le premier élément au sommet de B et le met sur A.\nNe fait rien si B est vide.\n\n");
	if (s->n_elem_b == -1)
	{
		//NOTENOUGH("B");
		return;
	}
	// -> push haut de la pile A sur haut de la pile B

	s->n_elem_a++; //on prepare le top de la pile B a recevoir en ajoutant +1 dindex
	s->stack_a[s->n_elem_a] = s->stack_b[s->n_elem_b];
	s->n_elem_b--;
	//if (s->n_elem_a >= 1 && STACK_A[s->n_elem_a] > STACK_A[s->n_elem_a - 1])
	//	swap_a(s); est opti seulement si le reste de la pile est trié !!
	//la pile b peut etre decrementee
	print_arrays(s);
	s->op_count++;
	s->pa++;
}

/**
 *
 * Prend le premier élément au sommet de A et le met sur B
 * @params stack *s
 * @return none
 *
 */
void push_b(t_stacks *s)
{
	DEBUG("PUSH B");
	//printf("prend le premier élément au sommet de A et le met sur B.\nNe fait rien si A est vide.\n\n");

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
	//if (s->n_elem_b >= 1 && STACK_B[s->n_elem_b] < STACK_B[s->n_elem_b - 1])
	//	swap_b(s); //pas tjrs opti
	print_arrays(s);

	s->op_count++;
	s->pb++;
}

void swap_b(t_stacks *s)
{
	DEBUG("SWAP B");
	//printf("intervertit les 2 premiers éléments au sommet de la pile B. \nNe fait rien s’il n’y en a qu’un ou aucun.\n");
	int tmp;
	if (s->n_elem_b < 1)
	{
		//NOTENOUGH("B");
		return;
	}
	tmp = s->stack_b[s->n_elem_b];
	s->stack_b[s->n_elem_b] = s->stack_b[s->n_elem_b - 1];
	s->stack_b[s->n_elem_b - 1] = tmp;
	print_arrays(s);
	s->op_count++;
	s->sb++;
}

void swap_a(t_stacks *s)
{
	DEBUG("SWAP A");
	//printf("intervertit les 2 premiers éléments au sommet de la pile A. \nNe fait rien s’il n’y en a qu’un ou aucun.\n");
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
	s->op_count++;
	s->sa++;
}
