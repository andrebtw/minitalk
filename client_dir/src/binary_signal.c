/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:48:58 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/20 16:25:52 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#define START_OF_TEXT 2
#define END_OF_TEXT 3

int	send_byte(int pid, char c)
{
	int	i;

	i = 0;
	while (c)
	{
		if (c % 2 == 0)
			if (kill(pid, SIGUSR1) == -1)
				return (EXIT_FAILURE);
		if (c % 2 == 1)
			if (kill(pid, SIGUSR2) == -1)
				return (EXIT_FAILURE);
		c = c / 2;
		i++;
	}
	while (i != 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	string_loop(int pid, char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		send_byte(pid, string[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	binary_signal(int pid, char *string)
{
	if (send_byte(pid, START_OF_TEXT) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (send_byte(pid, string[0]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (send_byte(pid, END_OF_TEXT) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
