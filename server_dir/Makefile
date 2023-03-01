# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 17:23:01 by anrodri2          #+#    #+#              #
#    Updated: 2023/03/01 20:22:02 by anrodri2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#### SYSTEM ####
.PHONY: $(NAME) all clean fclean re 
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

#### DIRECTORIES ####
SRC_DIR = src

#### SOURCE FILES ####
SRCS =	$(SRC_DIR)/server.c \

OBJS = $(SRCS:.c=.o)

HEADER = $(SRC_DIR)/server.h

#### LIBFT HEADER COMPILED ####
LIBFT_COMPILED = ../lib/libft_updated.a

### FINAL COMPILATION FILE ###
NAME = ../server

#### RULES ####
$(NAME):	$(OBJS) $(HEADER)
			cd .. && cd lib && $(MAKE) all
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT_COMPILED) -o $(NAME) -g3

%.o: %.c	$(HEADER) Makefile
			$(CC) $(CFLAGS) -c $< -o $@ -g3

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
