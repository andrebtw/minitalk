/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:46:03 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/21 11:26:41 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <signal.h>

static void pSigHandler(int signo){
    if (signo == SIGUSR1)
	{
		ft_printf("0");
    }
	else
	{
		ft_printf("1");
	}
}

int	main(void)
{
	ft_printf("%d\n", (getpid()));
	struct sigaction sa;
	sa.sa_flags = SA_RESTART;
    signal.sa_handler = &pSigHandler;
    sigaction(SIGUSR1, &signal, NULL);
	ft_printf("teyeye");
	while (1)
	{
		/* code */
	}
	ft_printf("test");
	return (EXIT_SUCCESS);
}
