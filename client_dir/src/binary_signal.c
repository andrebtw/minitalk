/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:28:42 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/23 15:28:42 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

extern int sig_recept;

size_t byte_size(int nb)
{
	size_t counter;

	counter = 0;
	while (nb) {
		nb = nb / 2;
		counter++;
	}
	return (counter);
}

int string_loop(int pid, char *string)
{
	int i;

	i = 0;
	while (string[i])
	{
		if (send_byte(pid, string[i], byte_size((int) string[i])) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static void	check_end(void)
{
	if (sig_recept == SIGUSR2)
	{
		ft_printf("%sMessage sent successfully !%s\n", KGREEN, KNORMAL);
		sig_recept = 0;
	}
	else
	{
		ft_printf("%sServer is not responding.%s\n", KRED, KNORMAL);
		sig_recept = 0;
		exit(EXIT_FAILURE);
	}
}

int	binary_signal(int pid, char *string)
{
	if (send_byte(pid, SEND_START, byte_size(SEND_START)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (string_loop(pid, string) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (send_byte(pid, SEND_END, byte_size(SEND_END)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	check_end();
	return (EXIT_SUCCESS);
}
