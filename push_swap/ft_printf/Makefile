NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRC = ft_printf.c ft_conversions.c ft_print_memory_address.c ft_to_hex.c ft_putnbr_unsigned_fd.c

OBJECT = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT)
	$(MAKE) -C libft
	cp libft/libft.a ./$(NAME)
	ar rcs $(NAME) $(OBJECT)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJECT)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean $(NAME)