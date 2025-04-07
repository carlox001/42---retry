NAME = minishell

UTILS = utils/utils.a
UTILS_DIR = utils/

CC = cc
CFLAGS = -Wall -Werror -Wextra -g 

SRC = errors.c \
	  main.c \
	  matrix_utils.c \
	  parsing.c \
	  count_words.c \
	  matrix_handler.c \
	  quotes_core.c \
	  commands_hub.c \
	  builtin_command_1.c \
	  builtin_command_2.c \
	  parsing_utils.c \
	  exec.c \
	  ft_export.c \
	  ft_export_utils_1.c \
	  ft_export_utils_2.c \
	  ft_unset.c \
	  ft_unset_utils.c \
	  ft_echo.c \
	  ft_echo_utils.c \
	  ft_cd_utils_1.c \
	  ft_cd_utils_2.c \
	  ft_cd_utils_3.c \

all: $(NAME)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(UTILS):
	$(MAKE) -C $(UTILS_DIR)

$(NAME): $(PRINTF) $(UTILS)
	$(CC) $(CFLAGS) $(SRC) $(UTILS) -lreadline -o $(NAME)

clean:
	rm -f

fclean: clean
	rm -f $(NAME)
	
re: fclean $(NAME)

.PHONY: all clean fclean re

