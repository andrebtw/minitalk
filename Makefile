# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 15:08:40 by anrodri2          #+#    #+#              #
#    Updated: 2023/02/19 16:35:26 by anrodri2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#### SYSTEM ####
.PHONY: $(NAME) all clean fclean re libft_comp


### FLAGS ###
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror 

SRCS_CLIENT =	client/src/client.c \
				
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

SRCS_SERVER =	client/src/client.c \
				
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

CLIENT_HEADER = client/src/client.h

SERVER_HEADER = server/src/server.h

#### LIBFT HEADER COMPILED ####
LIBFT_COMPILED = lib/libft_updated.a


### FINAL COMPILATION FILE ###
CLIENT = client
SERVER = server

#### RULES ####
$(NAME):	libft_comp server client $(OBJS_SERVER) $(OBJS_CLIENT) $(HEADER)

%.o: %.c	$(HEADER) Makefile
			$(CC) $(CFLAGS) -c $< -o $@ -g3

all:		$(NAME)

clean:
			cd lib && $(MAKE) clean
			$(RM) $(OBJS_SERVER)
			$(RM) $(OBJS_CLIENT)

fclean:
			cd lib && $(MAKE) fclean
			$(RM) $(OBJS_SERVER) $(SERVER)
			$(RM) $(OBJS_CLIENT) $(CLIENT)

libft_comp:
			cd lib && $(MAKE)

server:
			$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT_COMPILED) -o $(SERVER) -g

client:
			$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT_COMPILED) -o $(CLIENT) -g

re:	fclean $(NAME)
