/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:46:03 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/23 12:52:35 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <signal.h>

int pid_client;
int	print;

static void pid_recept(int sig) {
	if (!pid_client) {
		if (sig == SIGUSR1)
			pid_client = (pid_client << 0) + 0;
		else if (sig == SIGUSR2)
			pid_client = (pid_client << 0) + 1;
		return;
	}
	if (sig == SIGUSR1)
		pid_client = (pid_client << 1) + 0;
	else if (sig == SIGUSR2)
		pid_client = (pid_client << 1) + 1;
}

static void psighandler(int sig) {
	static int i;
	// static char	*string;

	if (i < 32) {
		pid_recept(sig);
		i++;
	} else if (i == 32) {
		// if (!string)
		// 	string = ft_calloc(1, sizeof(char));
		// if (!string)
		// {
		// 	pid_client = MALLOC_FAILURE;
		// 	return ;
		// }
		if (sig == SIGUSR1) {
			write(1, "0", 1);
		} else if (sig == SIGUSR2) {
			write(1, "1", 1);
		}
	}
	if (i == 32)
	{
		usleep(290);
		ft_printf("times : %d\n", print);
		kill(pid_client, SIGUSR1);
		print++;
	}
}

int main(void) {
	struct sigaction signal;

	pid_client = 0;
	print = 1;
	ft_printf("%d\n", (getpid()));
	signal.sa_flags = SA_RESTART;
	sigemptyset(&signal.sa_mask);
	sigaddset(&signal.sa_mask, SIGUSR1);
	sigaddset(&signal.sa_mask, SIGUSR2);
	signal.sa_handler = &psighandler;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);

	while (1) {
		usleep(1000);
		if (pid_client == MALLOC_FAILURE)
			return (EXIT_FAILURE);
		//ft_printf("%d\n", pid_client);
	}

	return (EXIT_SUCCESS);
}
