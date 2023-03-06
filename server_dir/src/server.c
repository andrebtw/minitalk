/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:46:03 by anrodri2          #+#    #+#             */
/*   Updated: 2023/03/02 05:13:36 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	g_pid_client;

void	check_pid_string(siginfo_t *info, char **string,
	int *byte, int *byte_index)
{
	if (g_pid_client == -1)
		g_pid_client = info->si_pid;
	if (g_pid_client != info->si_pid)
	{
		g_pid_client = info->si_pid;
		*byte = 0;
		*byte_index = 0;
		if (*string)
			free(*string);
		*string = NULL;
	}
	if (!(*string))
		*string = ft_calloc(1, sizeof(char));
	if (!(*string))
	{
		ft_printf(MALLOC_ERR_MSG, KRED, KNORMAL);
		exit(MALLOC_FAILURE);
	}
}

int	bin_to_dec(int *byte, int sig, int byte_index)
{
	if (byte_index < 8)
	{
		if (*byte == 0)
		{
			if (sig == SIGUSR1)
				*byte = (*byte << 0) + 0;
			else if (sig == SIGUSR2)
				*byte = (*byte << 0) + 1;
		}
		else
		{
			if (sig == SIGUSR1)
				*byte = (*byte << 1) + 0;
			else if (sig == SIGUSR2)
				*byte = (*byte << 1) + 1;
		}
		byte_index++;
	}
	return (byte_index);
}

void	char_receive(int *byte_index, int *byte, char **string, siginfo_t *info)
{
	if (*byte_index == 8)
	{
		if (*byte == SEND_END)
		{
			ft_printf("%s", *string);
			free(*string);
			*string = NULL;
			usleep(1000);
			*byte_index = 0;
			*byte = 0;
			if (kill(info->si_pid, SIGUSR2) == -1)
				ft_printf(ERROR_MSG, KRED, KNORMAL);
			return ;
		}
		*string = ft_strjoin_free_char(*string, (char)*byte, 1);
		if (!(*string))
		{
			ft_printf(MALLOC_ERR_MSG, KRED, KNORMAL);
			exit(MALLOC_FAILURE);
		}
		*byte_index = 0;
		*byte = 0;
	}
}

static void	psighandler(int sig, siginfo_t *info, void *ucontext)
{
	static int	byte_index;
	static int	byte;
	static char	*string;

	check_pid_string(info, &string, &byte, &byte_index);
	(void)ucontext;
	byte_index = bin_to_dec(&byte, sig, byte_index);
	char_receive(&byte_index, &byte, &string, info);
	usleep(2);
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		ft_printf(ERROR_MSG, KRED, KNORMAL);
		if (string)
			free(string);
		string = NULL;
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	struct sigaction	signal;

	g_pid_client = -1;
	ft_printf("%d\n", (getpid()));
	signal.sa_flags = SA_RESTART | SA_SIGINFO;
	if (sigemptyset(&signal.sa_mask) == -1)
		return (EXIT_FAILURE);
	sigaddset(&signal.sa_mask, SIGUSR1);
	sigaddset(&signal.sa_mask, SIGUSR2);
	signal.sa_sigaction = psighandler;
	if (sigaction(SIGUSR1, &signal, NULL) == -1)
		return (EXIT_FAILURE);
	if (sigaction(SIGUSR2, &signal, NULL) == -1)
		return (EXIT_FAILURE);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
