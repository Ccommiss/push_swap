/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pivot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:43:20 by ccommiss          #+#    #+#             */
/*   Updated: 2021/06/22 13:43:20 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/**
 *		_Checks if the array still contains numbers lower than provided one
 *		@param {int*}s : the stack or array we want to look in
 *		@param {int} n : the nb of elems we need to check
 *		@param {int} pivot : the pivot nb
 *		@return : false if no nb < pivot, true if yes
 **/
int	check_lower_than_pivot(int *s, int n_elem, int pivot)
{
	int	i;

	i = 0;
	while (i <= n_elem)
	{
		if (s[i] < pivot)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

/**
 *		_Checks if the array still contains numbers higher than provided one
 *		@param {int*}s : the stack or array we want to look in
 *		@param {int} n : the nb of elems we need to check
 *		@param {int} pivot : the pivot nb
 *		@return : false if no nb < pivot, true if yes
 **/
int	check_higher_than_pivot(int *s, int n_elem, int pivot)
{
	int	i;

	i = 0;
	while (i <= n_elem)
	{
		if (s[i] > pivot)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
