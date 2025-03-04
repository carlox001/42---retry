# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 11:21:39 by cazerini          #+#    #+#              #
#    Updated: 2025/02/23 18:34:33 by cazerini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

FT_PRINTF = ./ft_printf/libftprintf.a

SRC = so_long.c map_check.c map_check_utils.c get_next_line.c \
	get_next_line_utils.c so_long_utils.c win_check.c \
	win_check_utils.c moves.c last_utils.c bonus.c enemies_moves.c bonus_utils.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

all: $(NAME) $(FT_PRINTF)

minilibx:
	@$(MAKE) -C minilibx-linux

.c.o:
	$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

$(NAME): minilibx $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(FT_PRINTF)
	
clean:
	rm $(OBJ)

fclean: clean
	rm -f

re: fclean all