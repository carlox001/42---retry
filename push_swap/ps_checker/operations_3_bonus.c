/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:01:03 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/05 14:01:36 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_ra(t_list **stack_a)
{
	t_list	*top;
	t_list	*tmp;

	if (!(*stack_a) || (*stack_a)->next == (*stack_a))
		return ;
	top = (t_list *)malloc(sizeof(t_list));
	if (!top)
	{
		free(top);
		return ;
	}
	tmp = top;
	top = (*stack_a);
	ft_lstadd_back(stack_a, top);
	(*stack_a) = (*stack_a)->next;
	free(tmp);
}

void	ft_rb(t_list **stack_b)
{
	t_list	*top;
	t_list	*tmp;

	if (!(*stack_b) || (*stack_b)->next == (*stack_b))
		return ;
	top = (t_list *)malloc(sizeof(t_list));
	if (!top)
	{
		free(top);
		return ;
	}
	tmp = top;
	top = (*stack_b);
	ft_lstadd_back(stack_b, top);
	(*stack_b) = (*stack_b)->next;
	free(tmp);
}

void	ft_rra(t_list **stack_a)
{
	t_list	*back;
	t_list	*tmp;

	if (!(*stack_a) || (*stack_a)->next == (*stack_a))
		return ;
	back = (*stack_a);
	while (back->next->next != (*stack_a))
		back = back->next;
	tmp = back;
	ft_lstadd_front(stack_a, back->next);
	back->next = (*stack_a);
}

void	ft_rrb(t_list **stack_b)
{
	t_list	*back;
	t_list	*tmp;

	if (!(*stack_b) || (*stack_b)->next == (*stack_b))
		return ;
	back = (*stack_b);
	while (back->next->next != (*stack_b))
		back = back->next;
	tmp = back;
	ft_lstadd_front(stack_b, back->next);
	back->next = (*stack_b);
}
