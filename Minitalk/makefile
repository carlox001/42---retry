# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: czerini <czerini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 16:19:46 by czerini           #+#    #+#              #
#    Updated: 2024/05/21 16:22:34 by czerini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAME2 = client

SRC = ft_printf/ft_printf.c ft_printf/helper_fnct.c ft_printf/print_fnct.c \
			ft_atoi.c
SERVER = server.c
CLIENT = client.c

OBJ = $(SRC:.c=.o)

CC = cc

RM = rm -f

AR = ar rcs

CFLAGS = -Wall -Wextra -Werror -I./ft_printf

all: $(NAME) $(NAME2) $(PRINTF)

$(NAME): $(OBJ) server.o
	$(CC) $(CFLAGS) server.o $(OBJ) -o server
$(NAME2): $(OBJ) client.o
	$(CC) $(CFLAGS) client.o $(OBJ) -o client

clean:
	rm *.o ft_printf/*.o
fclean: clean
	$(RM) server client

re: fclean all
.PHONY: all clean fclean re