/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:39:21 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/05 14:01:36 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_sa(t_list **stack_a)
{
	int	tmp;

	if (!(*stack_a) || (*stack_a)->next == (*stack_a))
		return ;
	tmp = (*stack_a)->content;
	(*stack_a)->content = (*stack_a)->next->content;
	(*stack_a)->next->content = tmp;
}

void	ft_sb(t_list **stack_b)
{
	int	tmp;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = (*stack_b)->content;
	(*stack_b)->content = (*stack_b)->next->content;
	(*stack_b)->next->content = tmp;
}

void	fix_stack(t_list **stack)
{
	t_list	*tmp;

	if ((*stack)->next == (*stack))
	{
		tmp = (*stack);
		(*stack) = NULL;
		free(tmp);
		return ;
	}
	else
	{
		(*stack) = (*stack)->next;
		tmp = find_last_node((*stack));
		(*stack)->prev = tmp->prev;
		tmp->prev->next = (*stack);
		free(tmp);
	}
}

void	ft_pa(t_head *head)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new || !(head->head_b))
		return ;
	new->content = head->head_b->content;
	if (head->head_a)
	{
		new->next = head->head_a;
		new->prev = find_last_node(head->head_a);
	}
	else
	{
		new->next = new;
		new->prev = new;
	}
	head->head_a = new;
	head->head_a->prev->next = head->head_a;
	head->head_a->next->prev = head->head_a;
	fix_stack(&head->head_b);
}

void	ft_pb(t_head *head)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new || !(head->head_a))
		return ;
	new->content = head->head_a->content;
	if (head->head_b)
	{
		new->next = head->head_b;
		new->prev = find_last_node(head->head_b);
		head->head_b->prev = new;
	}
	else
	{
		new->next = new;
		new->prev = new;
	}
	head->head_b = new;
	new->prev->next = head->head_b;
	head->head_b->next->prev = head->head_b;
	fix_stack(&head->head_a);
}
