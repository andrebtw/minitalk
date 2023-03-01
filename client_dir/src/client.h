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
# define SEND_END 4
# define SEND_START 2

/* COLORS */
# define KNORMAL "\x1B[0m"
# define KRED "\x1B[31m"
# define KGREEN "\x1B[32m"
# define KYELLOW "\x1B[33m"
# define KBLUE "\x1B[34m"
# define KWHITE "\x1B[37m"

/* FUNCTIONS */
int	binary_signal(int pid, char *string);
int send_byte(int pid, int c, int byte_size);

#endif
