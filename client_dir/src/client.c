/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:46:01 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/22 20:36:20 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	sig_recept;

static void	handler(int sig)
{
	sig_recept = sig;
	if (sig == SIGUSR2)
	{
		ft_printf("Message sent successfully !\n");
		exit(EXIT_SUCCESS);
	}
}

int main(int argc, char **argv)
{
	struct sigaction signal;

	sig_recept = 0;
	signal.sa_flags = SA_RESTART;
	signal.sa_handler = &handler;
	sigemptyset(&signal.sa_mask);
//	sigaddset(&signal.sa_mask, SIGUSR1);
//	sigaddset(&signal.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	if (argc != 3)
		return (EXIT_FAILURE);
	if (!ft_atoi(argv[1]))
		return (EXIT_FAILURE);
	if (!argv[2][0])
		return (EXIT_FAILURE);
	if (binary_signal(ft_atoi(argv[1]), argv[2]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
