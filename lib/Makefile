#### SYSTEM ####
.PHONY: $(NAME) all clean fclean re bonus
CC = gcc
AR = ar rc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

#### DIRS ####
LIBFT_DIR = libft
GNL_DIR = get_next_line
PRINTF_DIR = ft_printf

#### SOURCE FILES ####
SRCS = 	ft_atoi.c \
		ft_atoi_bin.c \
		ft_strchr.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strjoin_free.c \
		ft_strjoin_free_char.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strlcpy.c \
		ft_substr.c \
		ft_strtrim.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_itoa.c \
		ft_split.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_null_found.c \
		ft_print_char.c \
		ft_print_decimals.c \
		ft_print_hex.c \
		ft_print_pointer_hex.c \
		ft_print_pourcentage.c \
		ft_print_string.c \
		ft_printf.c \
		ft_putbase_fd.c \
		ft_putchar_fd_printf.c \
		ft_putnbr_fd_printf.c \
		ft_putstr_fd_printf.c \
		ft_sizeof_nb_base.c \
		ft_strlen_printf.c

OBJS = $(SRCS:.c=.o)
HEADER = libft.h

### FINAL COMPILATION FILE ###
NAME = libft.a

#### RULES ####
$(NAME):	$(OBJS) $(HEADER) Makefile
			$(AR) $(NAME) $(OBJS)

%.o: %.c	$(HEADER) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:
			$(RM) $(OBJS) $(OBJS_BONUS) $(NAME)

re:	fclean $(NAME)
