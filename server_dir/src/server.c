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

int pid_client;

static void psighandler(int sig, siginfo_t *info, void *ucontext)
{
	static int 	j;
	static int	byte;
	static char	*string;

	if (pid_client == -1)
		pid_client = info->si_pid;
	if (pid_client != info->si_pid)
	{
		pid_client = info->si_pid;
		byte = 0;
		j = 0;
		if (string)
			free(string);
		string = NULL;
	}
	(void)ucontext;
	if (!string)
		string = ft_calloc(1, sizeof(char));
	if (!string)
		exit(EXIT_FAILURE);
	if (j < 8)
	{
		if (byte == 0)
		{
			if (sig == SIGUSR1)
				byte = (byte << 0) + 0;
			else if (sig == SIGUSR2)
				byte = (byte << 0) + 1;
		}
		else
		{
			if (sig == SIGUSR1)
				byte = (byte << 1) + 0;
			else if (sig == SIGUSR2)
				byte = (byte << 1) + 1;
		}
		j++;
	}
	if (j == 8)
	{
		if (byte == SEND_END)
		{
			ft_printf("%s", string);
			free(string);
			string = NULL;
			usleep(1000);
			j = 0;
			byte = 0;
			if (kill(info->si_pid, SIGUSR2) == -1)
				ft_printf("%sError while sending signal to client. %s\n", KRED, KNORMAL);
			return;
		}
		string = ft_strjoin_free_char(string, (char)byte, 1);
		j = 0;
		byte = 0;
	}
	usleep(2);
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		ft_printf("%sError while sending signal to client. %s\n", KRED, KNORMAL);
		if (string)
			free(string);
		exit(EXIT_FAILURE);
	}
}

int main(void)
{
	struct sigaction signal;

	pid_client = -1;
	ft_printf("%d\n", (getpid()));
	signal.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&signal.sa_mask);
	sigaddset(&signal.sa_mask, SIGUSR1);
	sigaddset(&signal.sa_mask, SIGUSR2);
	signal.sa_sigaction = psighandler;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
