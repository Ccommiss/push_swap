/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 15:46:53 by ccommiss          #+#    #+#             */
/*   Updated: 2021/06/18 11:46:33 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ftoa(float n, int afterpoint)
{
	int		ipart;
	float	fpart;
	char	*res;
	char	*res2;
	char	*tmp;

	ipart = (int)n;
	fpart = n - (float)ipart;
	res = ft_itoa(ipart);
	res2 = NULL;
	if (afterpoint != 0)
	{
		tmp = res;
		res = ft_strjoin(res, ".");
		free(tmp);
		fpart = fpart * pow(10, afterpoint);
		res2 = ft_itoa((int)fpart);
	}
	free(res);
	free(res2);
	return (ft_strjoin(res, res2));
}
