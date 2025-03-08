# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 12:29:46 by cazerini          #+#    #+#              #
#    Updated: 2024/12/01 14:25:24 by cazerini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
	ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c\
	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c\
	ft_strrchr.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_substr.c\

B_SRC = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
	ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c\

OBJ = ${SRC:.c=.o}

B_OBJ = ${B_SRC:.c=.o}

CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) 
	ar rc $(NAME) $(OBJ)

bonus: $(OBJ) $(B_OBJ)
	ar rc $(NAME) $(OBJ) $(B_OBJ)

%.o: %.c
	${CC} -c ${CFLAGS} -I. $< -o $@
	
clean:
	rm -rf $(OBJ) $(B_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all