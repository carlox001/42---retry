NAME = push_swap

CHECKER = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRC = push_swap.c push_swap_utils.c check_errors.c allocate_free.c operations.c operations_2.c operations_3.c \
	cases.c cases_2.c case_gen.c cost.c controls.c controls_2.c find.c find_cost.c first_and_second.c put.c\
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

BONUS = ps_checker/checker_bonus.c ps_checker/operations_bonus.c ps_checker/operations_2_bonus.c \
	ps_checker/operations_3_bonus.c ps_checker/checker_utils_bonus.c ps_checker/check_errors_bonus.c \
	ps_checker/allocate_free_bonus.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

all: $(NAME)

$(NAME): $(SRC)
	$(MAKE) -C ft_printf
	$(CC) $(CFLAGS) $(SRC) -L ft_printf -l ftprintf -o $(NAME)

bonus: $(CHECKER)

$(CHECKER): $(BONUS)
	$(MAKE) -C ft_printf
	$(CC) $(CFLAGS) $(BONUS) -L ft_printf -l ftprintf -o $(CHECKER)

clean:
	$(MAKE) -C ft_printf clean

fclean: clean
	$(MAKE) -C ft_printf fclean
	rm -f $(NAME) $(CHECKER)

re: fclean $(NAME)