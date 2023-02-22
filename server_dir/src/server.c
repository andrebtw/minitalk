/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:46:03 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/22 20:29:18 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <signal.h>

int			pid_client;

static void pid_recept(int sig)
{
	if (!pid_client)
	{
		if (sig == SIGUSR1)
			pid_client = (pid_client << 0) + 0;
		else if (sig == SIGUSR2)
			pid_client = (pid_client << 0) + 1;
		return ;
	}
	if (sig == SIGUSR1)
			pid_client = (pid_client << 1) + 0;
	else if (sig == SIGUSR2)
		pid_client = (pid_client << 1) + 1;
}

static void	psighandler(int sig)
{
	static int i;
	// static char	*string;

	if (i < 32)
	{
		pid_recept(sig);
		i++;
	}
	else if (i == 32)
	{	
		// if (!string)
		// 	string = ft_calloc(1, sizeof(char));
		// if (!string)
		// {
		// 	pid_client = MALLOC_FAILURE;
		// 	return ;
		// }
		if (sig == SIGUSR1)
		{
			write(1, "0", 1); 
		}
		else if (sig == SIGUSR2)
		{
			write(1, "1", 1);
		}
	}
	if (i == 32)
		kill(pid_client, SIGUSR1);
}


int	main(void)
{
	struct sigaction	signal;

	pid_client = 0;
	ft_printf("%d\n", (getpid()));
	signal.sa_flags = SA_RESTART;
	signal.sa_handler = &psighandler;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	
	while (1)
	{
		usleep(1000);
		if (pid_client == MALLOC_FAILURE)
			return (EXIT_FAILURE);
		//ft_printf("%d\n", pid_client);
	}
	
	return (EXIT_SUCCESS);
}
