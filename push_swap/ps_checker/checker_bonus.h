/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:26:33 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/30 13:04:32 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include "../ft_printf/ft_printf.h"
# include "../ft_printf/libft/libft.h"
# include "../get_next_line/get_next_line.h"

bool	check_char(char **argv);
bool	check_double(char **argv);
int		is_number(char *av);
bool	check_int(char **argv);
long	ft_atol(const char *ptr);

void	ft_sa(t_list **stack_a);
void	ft_sb(t_list **stack_b);
void	ft_ss(t_head *head);
void	fix_stack(t_list **stack);
void	ft_pa(t_head *head);
void	ft_pb(t_head *head);
void	ft_ra(t_list **stack_a);
void	ft_rb(t_list **stack_b);
void	ft_rr(t_head *head);
void	ft_rra(t_list **stack_a);
void	ft_rrb(t_list **stack_b);
void	ft_rrr(t_head *head);

void	operations(char *command, t_head *head);
void	read_move(t_head *head);
void	final_control(t_head *head);
void	free_all(t_head *head);
void	start_finish(t_head *head);

void	fillstack(t_list **head, int content);
void	ft_free_stack(t_list **stack);
bool	control_order_cresc(t_list **stack);
t_list	*find_max(t_list **stack);
bool	check_char(char **argv);
bool	check_double(char **argv);
t_list	*find_last_node(t_list *stack);

#endif