#include "pushswap.h"


/**
*	Find index of the next lower/higher number from pivot
*
*	@param {int} top of stack
*	@param {int} pivot
*	@param {int*} stack
*	@param {char} id of stack
*	@return none
**/
int		find_next(int *stack, int pivot, int top, char id) // je crois que cette opti est useless
{
	int i;
	int j;

	i = 0;
	j = top;
	if (id == 'B') // stack B = on cherche le prochain plus GRAND que le pivot
	{
		while (i <= top)
		{
			if (stack[i] > pivot)
				break;
			i++;
		}
		while (j >= 0)
		{
			if (stack[j] > pivot)
				break;
			j--;
		}
	}
	else if (id == 'A') // stack A = on cherche les inf
	{
		while (i <= top)
		{
			if (stack[i] < pivot)
				break;
			i++;
		}
		while (j >= 0)
		{
			if (stack[j] < pivot)
				break;
			j--;
		}
	}
	if (top - j <= i) //car si j est egal a i, ex 0 - top, vaut mieux prendre le top
	{
	 	//printf ("pivot = %d j = %d ; i = %d \n",pivot,  j, i);
		return (j);
	}
	else
	{
		//printf ("pivot = %d j = %d ; i = %d \n",pivot,  j, i);
		return (i);
	}
	return (-1);
}

/**
*	Find index of the number on the provided stack
*
*	@param {int} nb to look for
*	@param {int} top of stack
*	@param {int*} stack
*	@return none
**/
int find_index(int nb, int *array, int top)
{
	int i;

	i = 0;
	while (i <= top)
	{
		if (array[i] == nb)
			return (i);
		i++;
	}
	return (-1);
}


/**
*
*	Set the pivot to the biggest nb found
*
*	@param {t_stacks*} our main structure's pointer
*	@param {int} top of stack
*	@param {int*} pivot to be set
*	@return none
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

/**
*
*	Set the pivot to the *smallest* nb found
*
*	@param {t_stacks*} our main structure's pointer
*	@param {int} top of stack
*	@param {int*} pivot to be set
*	@return none
**/
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


/**
 *	calculate_median : computes median
 *
 *	@param {int*} stack array
 *	@param {int} numbers of elems
 *	@param {int} size : minimum size of nb lower
 *	@return {number} median
 **/
int calculate_median(int *stack, int n_elems, int size)
{
	int min;
	int max;
	int sum = 0;

	printf ("size = %d \n\n", size);
	take_biggest(stack, n_elems, &max);
	//printf ("Biggest = %d \n", max);
	take_smallest(stack, n_elems, &min);
	//printf ("smallest = %d \n", min);
	int j;

	j = 0;
	//printf ("HELLO N ELEM = %d\n", n_elems);
	while (min <= max)
	{
		j = 0;
		while (j <= n_elems)
		{

			if (min == stack[j])
			{
				printf ("min = %d :)\n", min);
				sum++; 	//printf ("sum = %d\n", sum);
			}
			j++;
		}
		if (size != 0 && sum > size)
			return (min);
		if (size == 0 && sum >= (n_elems + 1) / 2) //on rajoute + 1 car ca part de 0
		{
			printf ("N ELEMS =%d -- N ELEMS / 2 = %d  SUM = %d \n", n_elems, (n_elems + 1) / 2, sum);
			return (min); //avant c t sup ou egal test avec sup
		}
		min++;
	}
//	printf ("sum = %d\n", sum);
	return (0);
}
