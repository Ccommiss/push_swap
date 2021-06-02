#include "pushswap.h"

/**
*  Rotate A
*
* [Desc] : décale d’une position vers le HAUT tous les élements de la pile A.
* Le premier devient le dernier.
* @param {t_stacks *} stack
* @returns none
**/
void rotate_a(t_stacks *s)
{
	DEBUG("RA");
	printf ("décale d’une position vers le haut tous les élements de la pile A. \nLe premier élément devient le dernier.\n\n");
	int tmp;
	int i;

	i = s->n_elem_a;
	if (i < 1)
	{
		NOTENOUGH("A");
		return ;
	}
	tmp = s->stack_a[s->n_elem_a]; //on save l'element du top de la stack
	while (i > 0)
	{
		s->stack_a[i] = s->stack_a[i - 1];
		i--;
	}
	s->stack_a[0] = tmp;
	print_arrays(s);
	s->op_count++;
}

/**
* Rotate B
*
* [Desc] : décale d’une position vers le haut tous les élements dela pile B.
* Le premier devient le dernier.
* @param stack
* @returns none
**/
void rotate_b(t_stacks *s)
{
	DEBUG("RB");
	printf ("décale d’une position vers le haut tous les élements de la pile B. \nLe premier élément devient le dernier.\n\n");

	int tmp;
	int i;

	if (s->n_elem_b < 1)
	{
		//NOTENOUGH("B");
		return ;
	}
	i = s->n_elem_b;
	tmp = s->stack_b[s->n_elem_b]; //on save l'element du top de la stack
	while (i > 0)
	{
		s->stack_b[i] = s->stack_b[i - 1];
		i--;
	}
	s->stack_b[0] = tmp;
	print_arrays(s);
	s->op_count++;
}


/**
* Reverse rotate A
*
* [Desc] : décale d’une position vers le bas tous les élements dela pile A.
* Le dernier devient le premier.
* @param stack
* @returns none
**/
void reverse_rotate_a(t_stacks *s) //le dernier elem devient le premier
{
	DEBUG("RRA");
	printf ("décale d’une position vers le bas tous les élements dela pile A. \nLe dernier élément devient le premier.\n\n");
	int tmp;
	int i;

	if (s->n_elem_a < 1)
	{
		NOTENOUGH("A");
		return ;
	}
	i = 0;
	tmp = s->stack_a[0]; //on save l'element du top de la stack
	while (i < s->n_elem_a)
	{
		s->stack_a[i] = s->stack_a[i + 1];
		i++;
	}
	s->stack_a[s->n_elem_a] = tmp;
	print_arrays(s);
	s->op_count++;
}

/**
* Reverse rotate B
*
* [Desc] : décale d’une position vers le bas tous les élements dela pile B.
* Le dernier devient le premier.
* @param stack
* @returns none
**/
void reverse_rotate_b(t_stacks *s) //le dernier elem devient le premier
{
	DEBUG("RRB");
	printf ("décale d’une position vers le bas tous les élements dela pile B. \nLe dernier élément devient le premier.\n\n");

	int tmp;
	int i;

	if (s->n_elem_b < 1)
	{
		//NOTENOUGH("B");
		return ;
	}
	i = 0;
	tmp = s->stack_b[0]; //on save l'element du top de la stack
	while (i < s->n_elem_b)
	{
		s->stack_b[i] = s->stack_b[i + 1];
		i++;
	}
	s->stack_b[s->n_elem_b] = tmp;
	print_arrays(s);
	s->op_count++;
}





