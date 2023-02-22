/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:48:58 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/22 14:13:22 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#define START_OF_TEXT 2
#define END_OF_TEXT 3

int	send_byte(int pid, char c, int i)
{
	int	number;

	if (!c)
		return (EXIT_SUCCESS);
	return (send_byte(pid, c / 2, i + 1));
	number = (c % 2) + '0';
	write(1, &number, 1);
	return (EXIT_SUCCESS);
}

int	string_loop(int pid, char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		send_byte(pid, string[i], 0);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	binary_signal(int pid, char *string)
{
	if (send_byte(pid, START_OF_TEXT, 0) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (send_byte(pid, string[0], 0) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (send_byte(pid, END_OF_TEXT, 0) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
