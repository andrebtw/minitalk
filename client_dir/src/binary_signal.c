/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:28:42 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/23 15:28:42 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int send_pid(int pid_client, int byte_size, int pid)
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

size_t byte_size(int nb)
{
	size_t counter;

	counter = 0;
	while (nb) {
		nb = nb / 2;
		counter++;
	}
	return (counter);
}

int string_loop(int pid, char *string)
{
	int i;

	i = 0;
	while (string[i])
	{
		if (send_byte(pid, string[i], byte_size((int) string[i])) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int send_first_byte(int pid)
{
	int i;

	i = 0;
	while (i < 7)
	{
		if (kill(pid, SIGUSR1) == -1)
			return (EXIT_FAILURE);
		usleep(1000 * 2.5);
		i++;
	}
	if (kill(pid, SIGUSR2) == -1)
		return (EXIT_FAILURE);
	usleep(1000 * 2.5);
	return (EXIT_SUCCESS);
}

int	binary_signal(int pid, char *string)
{
	int pid_client;

	pid_client = getpid();
	ft_printf("PID : %d\n", pid_client);
	if (send_first_byte(pid) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	usleep(2000);
	if (send_pid(pid_client, byte_size(pid_client), pid))
		return (EXIT_FAILURE);
	usleep(50);
	if (string_loop(pid, string) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (send_byte(pid, SEND_END, byte_size(SEND_END)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
