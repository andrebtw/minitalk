/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:46:03 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/22 14:06:00 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <signal.h>
/*
int			g_index_code;

static void	psighandler(int sig)
{
	static char	*string;
	char		byte;

	if (!string)
		string = ft_calloc(1, sizeof(char));
	if (!string || !bin_str)
	{
		g_index_code = MALLOC_FAILURE;
		return ;
	}
	if (sig == SIGUSR1)
	{
		byte 
	}
}
*/
int	main(void)
{
	/*
	struct sigaction	signal;

	g_index_code = 0;
	ft_printf("%d\n", (getpid()));
	signal.sa_flags = SA_RESTART;
	signal.sa_handler = &psighandler;
	sigaction(SIGUSR1, &signal, NULL);
	sigaction(SIGUSR2, &signal, NULL);
	while (1)
	{
		pause();
		if (g_index_code == MALLOC_FAILURE)
			return (EXIT_FAILURE);
	}*/
	return (EXIT_SUCCESS);
}
