/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_byte.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:27:36 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/23 15:27:36 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

extern int	g_sig_recept;

typedef struct s_bin_list
{
	int	*list;
	int	index;
}	t_bin_list;

void	wait_signal(void)
{
	int	time;

	time = 0;
	if (g_sig_recept == SIGUSR1)
	{
		g_sig_recept = 0;
		return ;
	}
	while (time < 2000000)
	{
		if (g_sig_recept == SIGUSR1)
		{
			g_sig_recept = 0;
			return ;
		}
		time = time + 100;
		usleep(100);
	}
	ft_printf("%sServer is not responding.%s\n", KRED, KNORMAL);
	exit(EXIT_FAILURE);
}

void	put_bits_in_list(t_bin_list *bin_lst, char c, int byte_size)
{
	while (byte_size != 8)
	{
		bin_lst->list[bin_lst->index] = SIGUSR1;
		bin_lst->index--;
		byte_size++;
	}
	if (!c)
		return ;
	put_bits_in_list(bin_lst, c / 2, 8);
	if (c % 2 == 1)
		bin_lst->list[bin_lst->index] = SIGUSR2;
	if (c % 2 == 0)
		bin_lst->list[bin_lst->index] = SIGUSR1;
	bin_lst->index--;
}

int	send_list(int pid, t_bin_list *bin_lst)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_sig_recept = 0;
		if (kill(pid, bin_lst->list[i]) == -1)
			return (ft_printf("%sServer is not responding. %s\n",
					KRED, KNORMAL),
				EXIT_FAILURE);
		wait_signal();
		i--;
	}
	return (EXIT_SUCCESS);
}

int	send_byte(int pid, int c, int byte_size)
{
	t_bin_list	bin_lst;

	if (!(c >= 0 && c <= 127))
	{
		ft_printf("%sOnly standard ASCII characters are supported. %s\n",
			KRED, KNORMAL);
		return (EXIT_FAILURE);
	}
	bin_lst.list = (int *) malloc (sizeof(int) * 8);
	if (!bin_lst.list)
	{
		ft_printf("%sMalloc failed. %s\n", KRED, KNORMAL);
		return (EXIT_FAILURE);
	}
	bin_lst.index = 7;
	put_bits_in_list(&bin_lst, c, byte_size);
	if (send_list(pid, &bin_lst))
		return (free(bin_lst.list), EXIT_FAILURE);
	free(bin_lst.list);
	return (EXIT_SUCCESS);
}
