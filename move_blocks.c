#include "pushswap.h"

void insert_blocks_on_a(t_stacks *s)
{
	int max;
	int i;

	i = 0;
	if (s->n_elem_b == -1)
		return;
	//int tmp = 3;
	int tmp = s->n_elem_a + 1; // test, c le nb elements nvellement tries

	take_biggest(STACK_B, s->n_elem_b, &max);
	while (STACK_B[s->n_elem_b] != max && s->high_chunk - tmp != 0)
	{
		if (find_index(max, STACK_B, s->n_elem_b) >= s->n_elem_b / 2)
			rotate_b(s); //on remonte la pile
		else
			reverse_rotate_b(s); // le sens depend de l'index ou on est
	}
	//printf ("HIGH CHUNK HERE  = %d\n", s->high_chunk);
	while (i < s->high_chunk - tmp) // on retranche les tous mneufs, avant g mis 3
	{
		push_a(s); // on bouge sur A tous les gros elements d'abord
		i++;
	}
	i = 0;

	int min;
	take_smallest(STACK_A, s->n_elem_a, &min);

	//while (i < s->high_chunk - tmp) // on retranche les tout neufs ; au debut g mis trois, essayer avec n elems
	if (find_index(min, STACK_A, s->n_elem_a) >= s->n_elem_a)
		while (STACK_A[s->n_elem_a] != min)
			rotate_a(s); // on met les + gros elements deja tries en dessous de la pile
	else
		while (STACK_A[s->n_elem_a] != min)
			reverse_rotate_a(s); // on met les + gros elements deja tries en dessous de la pile

	i = 0;
	while (i < s->low_chunk)
	{
		push_a(s); // on met tous les low chunks sur le dessus
		i++;
	}
}

void insert_blocks_on_b(t_stacks *s)
{
	//int min;
	int i;

	i = 0;
	if (s->n_elem_a == -1)
		return;

	//int tmp = 3;
	int tmp = s->n_elem_b + 1;

	int block;

	block = s->high_chunk + s->low_chunk - tmp;
	printf("BAS DES ELEMS TRIES = %d\n", s->n_elem_a - block);

	if (tmp < 3) // TEST POUR PAS TOUT REMETTRE SUR B SI IL Y A JUSTE DEUX NOUVEAU ELEMENTS 
	{
		while (i < s->low_chunk - tmp) //on rotate les petits pour les mettre en bas
		{
			rotate_a(s);
			i++;
		}
		
		i = 0;
		while (i < tmp)
		{
			push_a(s);
			i++;
		}
		i = 0;
		while (i < s->low_chunk - tmp) //on reverse totate pour remettre les petits en haut 
		{
			reverse_rotate_a(s);
			i++;
		}
		sleep(5);
		return;
	}

	

	if (block > s->n_elem_a / 2)
	{
		while (i <= s->n_elem_a - block)
		{
			rotate_a(s);
			printf("hi there\n\n");
			i++;
		}
	}
	else
	{
		while (i < s->high_chunk + s->low_chunk - tmp)
		{
			reverse_rotate_a(s); //on remonte la pile
								 //printf ("coucou\n\n");
			i++;
		}
	}

	i = 0;
	while (i < s->low_chunk - tmp) //on push les petits ...
	{
		push_b(s);
		i++;
	}
	i = 0;

	//while (i < s->low_chunk - tmp)// et on les mets en dessous de la pile B
	while (i < tmp && s->low_chunk - tmp != 0) //tmp sera svt egal a genre 2 ou 3, ou le nb delem tries qui sera tjrs inf au reste la
	{										   // si lowchunk - tmp = 0 veut dire que c la premiere fois quon trie des short
		reverse_rotate_b(s);				   // a bien marche
		//printf ("wesh alors \n");
		i++;
	}
	//exit(0);

	i = 0;

	while (i < s->high_chunk)
	{
		push_b(s); // on met les gros au dessus de la pile B
		i++;
	}
	printf ("end moveblocks\n");
}
