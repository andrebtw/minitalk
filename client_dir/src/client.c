/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:46:01 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/19 19:03:28 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char **argv)
{
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
