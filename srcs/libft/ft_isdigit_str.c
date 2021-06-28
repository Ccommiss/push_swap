/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:37:55 by ccommiss          #+#    #+#             */
/*   Updated: 2021/06/28 10:30:19 by ccommiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '-' && ft_strlen(str) == 1)
			return (0);
		if ((!ft_isdigit(str[i]) && str[i] != '-')
			|| (i != 0 && str[i] == '-'))
			return (0);
		i++;
	}
	return (1);
}
