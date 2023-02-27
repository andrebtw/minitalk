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

int paused = 1;

typedef struct s_bin_list
{
	int	*list;
	int	index;
}	t_bin_list;

void	put_bits_in_list(t_bin_list *bin_lst, char c, int byte_size)
{
	while (byte_size != 8)
	{
		bin_lst->list[bin_lst->index] = SIGUSR1;
//		ft_printf("%d\n", bin_lst->list[bin_lst->index]);
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
//	ft_printf("%d\n", bin_lst->list[bin_lst->index]);
	bin_lst->index--;
}

int send_list(int pid, t_bin_list *bin_lst)
{
	int i;
	int kill_nb;

	i = 7;
	while (i >= 0)
	{
//		ft_printf("PAUSED : %d\n", paused);
//		paused++;
		kill_nb = kill(pid, bin_lst->list[i]);
		if (kill_nb == -1) {
			return (EXIT_FAILURE);
		}
		usleep(200);
//		ft_printf("AFTER PAUSE : %d\n", paused);
//		ft_printf("BIT : %d\n", i);
		i--;
	}
	return (EXIT_SUCCESS);
}

int send_byte(int pid, char c, int byte_size)
{
	t_bin_list bin_lst;

	bin_lst.list = (int *) malloc (sizeof(int) * 8);
	if (!bin_lst.list)
		return (MALLOC_FAILURE);
	bin_lst.index = 7;
	put_bits_in_list(&bin_lst, c, byte_size);
	if (send_list(pid, &bin_lst))
		return (free(bin_lst.list), EXIT_FAILURE);
	free(bin_lst.list);
	return (EXIT_SUCCESS);
}
