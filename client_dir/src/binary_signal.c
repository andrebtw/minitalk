/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:48:58 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/22 20:46:36 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#define START_OF_TEXT 2
#define END_OF_TEXT 3

int	send_pid(int pid_client, int byte_size, int pid)
{
	while (byte_size != 32)
	{
		if (kill(pid, SIGUSR1) == -1)
			return (EXIT_FAILURE);
		usleep(1000 * 2.5);
		byte_size++;
	}
	if (!pid_client)
		return (EXIT_SUCCESS);
	send_pid(pid_client / 2, 32, pid);
	usleep(1000 * 2.5);
	if (pid_client % 2 == 0)
		if (kill(pid, SIGUSR1) == -1)
			return (EXIT_FAILURE);
	if (pid_client % 2 == 1)
		if (kill(pid, SIGUSR2) == -1)
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

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

int	send_byte(int pid, char c, int byte_size, int pause_p)
{
	int	number;

	while (byte_size != 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			return (EXIT_FAILURE);
		if (pause_p)
			pause();
		byte_size++;
	}
	if (!c)
		return (EXIT_SUCCESS);
	send_byte(pid, c / 2, 8, pause_p);
	if (c % 2 == 0)
		if (kill(pid, SIGUSR1) == -1)
			return (EXIT_FAILURE);
	if (c % 2 == 1)
		if (kill(pid, SIGUSR2) == -1)
			return (EXIT_FAILURE);
	if (pause_p)
		pause();
	return (EXIT_SUCCESS);
}

int	string_loop(int pid, char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (send_byte(pid, string[i], byte_size((int)string[i]), 1) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	binary_signal(int pid, char *string)
{
	int	pid_client;

	pid_client = getpid();
	ft_printf("%d", pid_client);
	if (send_pid(pid_client, byte_size(pid_client), pid))
		return (EXIT_FAILURE);
	pause();
	usleep(50);
	if (send_byte(pid, 2, 2, 1) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (string_loop(pid, string) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (send_byte(pid, 3, 2, 1) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
