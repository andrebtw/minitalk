# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 15:08:40 by anrodri2          #+#    #+#              #
#    Updated: 2023/03/06 19:53:50 by anrodri2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


### FLAGS ###
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror 

#### LIBFT HEADER COMPILED ####
LIBFT_COMPILED = lib/libft.a

### FINAL COMPILATION FILE ###
NAME = compiled
CLIENT = ./client
SERVER = ./server

### SERVER FILES ###
SRCS_SERVER = server_dir/src/server.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

### CLIENT FILES ###
SRCS_CLIENT =	client_dir/src/client.c \
				client_dir/src/binary_signal.c \
				client_dir/src/send_byte.c
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
DEPENDS := $(SRCS_CLIENT:.c=.d) $(SRCS_SERVER:.c=.d)

#### RULES ####
all:		 libft_comp $(SERVER) $(CLIENT) Makefile

%.o: %.c	Makefile $(LIBFT_COMPILED)
			$(CC) $(CFLAGS) -c $< -MD -o $@ -g3

clean:
			@$(MAKE) clean -C lib
			$(RM) $(OBJS_CLIENT)
			$(RM) $(OBJS_SERVER)
			$(RM) $(DEPENDS)

fclean: 	clean
			$(RM) $(SERVER)
			$(RM) $(CLIENT)

libft_comp:
			@$(MAKE) all -C lib

$(CLIENT):  $(OBJS_CLIENT) $(LIBFT_COMPILED)
			$(CC) $(OBJS_CLIENT) $(LIBFT_COMPILED) $(CFLAGS) -o $(CLIENT)

$(SERVER):  $(OBJS_SERVER) $(LIBFT_COMPILED)
			$(CC) $(OBJS_SERVER) $(LIBFT_COMPILED) $(CFLAGS) -o $(SERVER)


bonus:		$(NAME)

re:	fclean all

-include $(DEPENDS)

#### SYSTEM ####

.PHONY:  all clean fclean re libft_comp bonus
