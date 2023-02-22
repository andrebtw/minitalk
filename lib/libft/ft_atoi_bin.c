/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:16:41 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/22 13:38:33 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char character)
{
	if (character == ' ' || character == '\t' || character == '\n'
		|| character == '\v' || character == '\f' || character == '\r')
		return (1);
	return (0);
}

int	ft_atoi_bin(const char *nptr)
{
	long long		number;
	int				neg_mult;
	int				i;

	i = 0;
	number = 0;
	neg_mult = 1;
	while (ft_isspace(nptr[i]) == 1)
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		i++;
		neg_mult = -1;
	}
	while (nptr[i])
	{
		number = number * 2 + nptr[i++] - '0';
	}
	return (number * neg_mult);
}
