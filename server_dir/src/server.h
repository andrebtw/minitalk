/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:06:25 by anrodri2          #+#    #+#             */
/*   Updated: 2023/03/02 05:13:11 by anrodri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

/* HEADER FILES */
# include "../../lib/libft.h"

/* COLORS */
# define KNORMAL "\x1B[0m"
# define KRED "\x1B[31m"
# define KGREEN "\x1B[32m"
# define KYELLOW "\x1B[33m"
# define KBLUE "\x1B[34m"
# define KWHITE "\x1B[37m"

/* ERROR MESSAGES */
# define ERROR_MSG "%s\nError while sending signal to client. %s\n"
# define MALLOC_ERR_MSG "%sMalloc failed. %s\n"

# define SEND_END 4
# define SEND_START 2
# define MALLOC_FAILURE -2

#endif
