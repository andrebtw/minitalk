/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:46:03 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/21 15:12:42 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <signal.h>

int	index_code;

static void	pSigHandler(int signo)
{
	static char	*string;

	if (!string)
		string = ft_calloc(1, sizeof(char));
	if (!string)
	{
		index_code = MALLOC_FAILURE;
		return ;
	}
	if ()
	
}

int	main(void)
{
	index_code = 0;
	ft_printf("%d\n", (getpid()));
	struct sigaction signal;
	signal.sa_flags = SA_RESTART;
	signal.sa_handler = &pSigHandler;
    sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
	{
		pause();
		if (index_code == MALLOC_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
