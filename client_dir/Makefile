# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 17:23:09 by anrodri2          #+#    #+#              #
#    Updated: 2023/03/01 20:22:11 by anrodri2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#### SYSTEM ####
.PHONY: $(NAME) all clean fclean re
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f


#### DIRECTORIES ####
SRC_DIR = src

#### SOURCE FILES ####
SRCS =	$(SRC_DIR)/client.c \
		$(SRC_DIR)/binary_signal.c \
		$(SRC_DIR)/send_byte.c

OBJS = $(SRCS:.c=.o)

HEADER = $(SRC_DIR)/client.h

#### LIBFT HEADER COMPILED ####
LIBFT_COMPILED = ../lib/libft_updated.a

### FINAL COMPILATION FILE ###
NAME = ../client

#### RULES ####
$(NAME):	$(OBJS) $(HEADER)
			cd .. && cd lib && $(MAKE) all
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT_COMPILED) -o $(NAME) -g

%.o: %.c	$(HEADER) Makefile
			$(CC) $(CFLAGS) -c $< -o $@ -g

all:		$(NAME)

clean:
			cd .. && cd lib && $(MAKE) clean
			$(RM) $(OBJS)

fclean:
			cd .. && cd lib && $(MAKE) fclean
			$(RM) $(OBJS) $(NAME)

lib:
			cd .. && cd lib && $(MAKE) re

bonus:
			$(NAME)

re:	fclean $(NAME)
