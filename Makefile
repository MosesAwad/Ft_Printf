NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = 	ft_printf.c ft_print_nbr.c ft_print_hex.c \
		ft_print_address.c ft_print_unsigned.c

OBJS = $(SRCS:.c=.o)

LIBFT_PATH		=	./Libft
LIBFT			=	$(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cp	$(LIBFT) $(NAME)
	ar rcs $@ $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
