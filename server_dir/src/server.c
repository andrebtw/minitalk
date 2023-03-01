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

int user_signal;

static void psighandler(int sig, siginfo_t *info, void *ucontext)
{
	static int 	j;
	static int	byte;
	static char	*string;

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
		if (sig == SIGUSR1)
			byte = (byte << 1) + 0;
		else if (sig == SIGUSR2)
			byte = (byte << 1) + 1;
		j++;
	}
	if (j == 8)
	{
		ft_printf("%c", byte - 128);
//		string = ft_strjoin_free_char(string, (char)byte, 1);
		j = 0;
		byte = 0;
	}
	usleep(15);
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		ft_printf("CLIENT ERROR.\n");
		exit(EXIT_FAILURE);
	}
}

//static int bitrecept(int sig, int pid_client)
//{
//	static int 	j;
//	static int	byte;
//	static char	*string;
//
//	if (!string)
//		string = ft_calloc(1, sizeof(char));
//	if (!string)
//		return (MALLOC_FAILURE);
//	if (j < 8)
//	{
//		if (byte == 0)
//		{
//			if (sig == SIGUSR1)
//				byte = (byte << 0) + 0;
//			else if (sig == SIGUSR2)
//				byte = (byte << 0) + 1;
//		}
//		if (sig == SIGUSR1)
//			byte = (byte << 1) + 0;
//		else if (sig == SIGUSR2)
//			byte = (byte << 1) + 1;
//		j++;
//	}
//	if (j == 8)
//	{
//		if (byte - 8 == 4)
//		{
//
////				ft_printf("%s\n", string);
//			byte = 0;
//			string = NULL;
//			j = 0;
//			usleep(500);
//			kill(pid_client, SIGUSR2);
//			return (CLIENT_END);
//		}
//		ft_printf("%c", byte - 128);
////			string = ft_strjoin_free_char(string, byte - 128, 1);
//		byte = 0;
//		j = 0;
//	}
////		ft_printf("PAUSED : %d\n", paused);
////		paused++;
//	return (pid_client);
//}

int main(void)
{
	struct sigaction signal;

	user_signal = 0;
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
