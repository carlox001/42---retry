/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:08:08 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/30 11:25:32 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h> 
# include <limits.h>
# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"

//check errori

bool	check_char(char **argv);
bool	check_double(char **argv);
int		is_number(char *av);
bool	check_int(char **argv);
long	ft_atol(const char *ptr);

//operazioni

bool	ft_sa(t_list **stack_a, bool flag);
bool	ft_sb(t_list **stack_b, bool flag);
void	ft_ss(t_head *head);
void	fix_stack(t_list **stack);
void	ft_pa(t_head *head);
void	ft_pb(t_head *head);
bool	ft_ra(t_list **stack_a, bool flag);
bool	ft_rb(t_list **stack_b, bool flag);
void	ft_rr(t_head *head);
bool	ft_rra(t_list **stack_a, bool flag);
bool	ft_rrb(t_list **stack_b, bool flag);
void	ft_rrr(t_head *head);

//utils

void	fillstack(t_list **head, int content);
void	ft_free_stack( t_list **stack);
void	cost(t_list **stack);
void	put_index(t_list **head, int len);
void	even(t_list **stack, t_list *tmp, int len);
void	uneven(t_list **stack, t_list *tmp, int len);
t_list	*find_max(t_list **stack);
t_list	*find_min(t_list **stack);
bool	control_order_cresc(t_list **stack);
bool	control_order_decresc(t_list **stack);
int		ft_abs(int num);
t_list	*find_last_node(t_list *stack);
void	put_on_top(t_list **stack, int index, bool flag);
t_list	*first_control_min(t_list *stack, int element);
t_list	*first_control_max(t_list *stack, int element);
t_list	*second_control_min(t_list *stack, int element);
t_list	*second_control_max(t_list *stack, int element);
void	start_and_finish(t_head *head, int argc);
void	free_all(t_head *head);
//void	print_list(t_list *a, int stack);
//void	print_cost(t_list *a, int stack);

//cases

void	hub_cases(t_head *head, int argc);
void	case_2(t_list **stack, bool flag);
void	case_3(t_list **stack, bool flag);
void	case_3_a(t_list **stack);
void	case_3_b(t_list **stack);
void	case_4(t_list **stack, t_head *head);
void	case_gen(t_head *head);

//algorithm

void	put_in_b(t_head *head);
void	put_in_a(t_head *head);
int		count_elements(t_list *stack);
t_list	*first_cheapest_cost(t_list *stack_a, t_list *stack_b);
t_list	*second_cheapest_cost(t_list *stack_a, t_list *stack_b);
t_list	*first_find_place(t_list *stack, int element);
t_list	*second_find_place(t_list *stack, int element);
int		rr_rrr_cost(int index_a, int index_b);
int		rr_rrr_do(int index_a, int index_b);
void	first_prepare_for_push(t_list **stack, t_list *element, bool flag);
void	second_prepare_for_push(t_list **stack, t_list *element, bool flag);
void	put_in_ord_decresc(t_list **stack_b);
void	put_in_ord_cresc(t_list **stack_a);
void	first_contemp_rotations(t_head *head, \
		t_list **stack, t_list *cheapest);
void	second_contemp_rotations(t_head *head, \
		t_list **stack, t_list *cheapest);

#endif