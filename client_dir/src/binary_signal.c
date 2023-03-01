/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:28:42 by anrodri2          #+#    #+#             */
/*   Updated: 2023/03/01 20:38:30 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

extern int	g_sig_recept;

size_t	byte_size(int nb)
{
	size_t	counter;

	counter = 0;
	while (nb)
	{
		nb = nb / 2;
		counter++;
	}
	return (counter);
}

int	string_loop(int pid, char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (send_byte(pid, string[i],
				byte_size((int) string[i])) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	binary_signal(int pid, char *string)
{
	if (string_loop(pid, string) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (send_byte(pid, SEND_END, byte_size(SEND_END)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
