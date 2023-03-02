/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:46:01 by anrodri2          #+#    #+#             */
/*   Updated: 2023/03/02 04:36:09 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	g_sig_recept;

static void	handler(int sig)
{
	g_sig_recept = sig;
	if (sig == SIGUSR2)
	{
		ft_printf("%sMessage sent successfully. %s\n", KGREEN, KNORMAL);
		exit (EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	signal;

	usleep(1000 * 5);
	g_sig_recept = 0;
	signal.sa_flags = SA_RESTART;
	signal.sa_handler = &handler;
	if (sigemptyset(&signal.sa_mask) == -1)
		return (EXIT_FAILURE);
	sigaddset(&signal.sa_mask, SIGUSR1);
	sigaddset(&signal.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &signal, NULL) == -1)
		return (EXIT_FAILURE);
	if (sigaction(SIGUSR2, &signal, NULL) == -1)
		return (EXIT_FAILURE);
	if (argc != 3)
		return (ft_printf("%sWrong number of arguments. %s\n", KRED, KNORMAL),
			EXIT_FAILURE);
	if (!ft_atoi(argv[1]))
		return (ft_printf("%sWrong PID. %s\n", KRED, KNORMAL), EXIT_FAILURE);
	if (!argv[2][0])
		return (ft_printf("%sEmpty message. %s\n", KRED, KNORMAL), EXIT_FAILURE);
	if (binary_signal(ft_atoi(argv[1]), argv[2]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
