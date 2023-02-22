# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrodri2 <anrodri2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 15:08:40 by anrodri2          #+#    #+#              #
#    Updated: 2023/02/21 14:54:38 by anrodri2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#### SYSTEM ####
.PHONY: $(NAME) all clean fclean re libft_comp server client

### FLAGS ###
CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror 

#### LIBFT HEADER COMPILED ####
LIBFT_COMPILED = lib/libft_updated.a

### FINAL COMPILATION FILE ###
NAME = compiled

#### RULES ####
$(NAME):	 libft_comp server client

all:		 $(NAME)

clean:
			@$(MAKE) clean -C lib
			@$(MAKE) clean -C server_dir
			@$(MAKE) clean -C client_dir
			$(RM) client
			$(RM) server

fclean:
			@$(MAKE) fclean -C lib
			@$(MAKE) fclean -C server_dir
			@$(MAKE) fclean -C client_dir

libft_comp:
			@$(MAKE) all -C lib

server:	
			@$(MAKE) all -C server_dir

client:
			@$(MAKE) all -C client_dir

re:	fclean all
