/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:07:42 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/19 18:51:38 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdarg.h>

/* HEADER FILES */
# include "../../lib/libft_updated.h"

/* CONSTANTS */
# define MALLOC_FAILURE -2
# define SEND_START 1
# define SEND_END 4

/* FUNCTIONS */
int	binary_signal(int pid, char *string);
int send_byte(int pid, char c, int byte_size);

#endif
