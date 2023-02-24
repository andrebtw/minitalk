/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:46:03 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/24 11:43:16 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <signal.h>

int user_signal;

static int pid_recept(int sig, int pid_client)
{
	if (!pid_client) {
		if (sig == SIGUSR1)
			pid_client = (pid_client << 0) + 0;
		else if (sig == SIGUSR2)
			pid_client = (pid_client << 0) + 1;
		return (pid_client);
	}
	if (sig == SIGUSR1)
		pid_client = (pid_client << 1) + 0;
	else if (sig == SIGUSR2)
		pid_client = (pid_client << 1) + 1;
	return (pid_client);
}

static void psighandler(int sig)
{
	user_signal = sig;
}

static int bitrecept(int sig, int pid_client)
{
	static int 	i;
	static char	*string;

	if (i < 32)
	{
		pid_client = pid_recept(sig, pid_client);
		i++;
	}
	else if (i >= 32)
	{
		if (!string)
			string = ft_calloc(1, sizeof(char));
		if (!string)
			return (MALLOC_FAILURE);
		
		usleep(70);
		kill(pid_client, SIGUSR1);
	}
	return (pid_client);
}

int main(void) {
	struct sigaction signal;
	int pid_client;

	user_signal = 0;
	pid_client = 0;
	times= 0;
	ft_printf("%d\n", (getpid()));
	signal.sa_flags = SA_RESTART;
	sigemptyset(&signal.sa_mask);
	sigaddset(&signal.sa_mask, SIGUSR1);
	sigaddset(&signal.sa_mask, SIGUSR2);
	signal.sa_handler = &psighandler;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);

	while (1)
	{
		pause();
		pid_client = bitrecept(user_signal, pid_client);
	return (EXIT_SUCCESS);
}
