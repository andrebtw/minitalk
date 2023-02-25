/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:06:25 by anrodri2          #+#    #+#             */
/*   Updated: 2023/02/22 18:19:37 by anrodri2         ###   ########.fr       */
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
# include "../../lib/libft_updated.h"

/* CONSTANTS */
# define MALLOC_FAILURE -500
# define CLIENT_END -1000

/* FUNCTIONS */
int	check_start(int end);

#endif
