#include "pushswap.h"


void reverse_rotate_b(t_stacks *s) //le dernier elem devient le premier
{
	DEBUG("RRB");
	int tmp;
	int i;

	i = 0;
	tmp = s->stack_b[0]; //on save l'element du top de la stack
	while (i <= s->n_elem_b)
	{
		s->stack_b[i] = s->stack_b[i + 1];
		i++;
	}
	s->stack_b[s->n_elem_b] = tmp;
	print_array('B', s->stack_b, s->n_elem_b);
}

void rotate_b(t_stacks *s)
{
	DEBUG("RB");
	int tmp;
	int i;

	if (s->n_elem_b < 1)
	{
		NOTENOUGH("B");
		return ;
	}

	i = s->n_elem_b;
	tmp = s->stack_b[s->n_elem_b]; //on save l'element du top de la stack
	while (i >= 0)
	{
		s->stack_b[i] = s->stack_b[i - 1];
		i--;
	}
	s->stack_b[0] = tmp;
	print_array('B', s->stack_b, s->n_elem_b);
}

void reverse_rotate_a(t_stacks *s) //le dernier elem devient le premier
{

	DEBUG("RRA");
	int tmp;
	int i;

	i = 0;
	tmp = s->stack_a[0]; //on save l'element du top de la stack

	while (i <= s->n_elem_a)
	{
		s->stack_a[i] = s->stack_a[i + 1];
		i++;
	}
	s->stack_a[s->n_elem_a] = tmp;
	print_array('A', s->stack_a, s->n_elem_a);
}

void rotate_a(t_stacks *s)
{
	DEBUG("RA");
	int tmp;
	int i;

	i = s->n_elem_a;
	tmp = s->stack_a[s->n_elem_a]; //on save l'element du top de la stack
	while (i >= 0)
	{
		s->stack_a[i] = s->stack_a[i - 1];
		i--;
	}
	s->stack_a[0] = tmp;
	print_array('A', s->stack_a, s->n_elem_a);
}
