/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:46:12 by cazerin           #+#    #+#             */
/*   Updated: 2025/03/12 12:36:21 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_ra(t_list **stack_a, bool flag)
{
	t_list	*top;
	t_list	*tmp;

	if (!(*stack_a) || (*stack_a)->next == (*stack_a))
		return (false);
	top = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!top)
	{
		free(top);
		return (false);
	}
	tmp = top;
	top = (*stack_a);
	ft_lstadd_back(stack_a, top);
	(*stack_a) = (*stack_a)->next;
	free(tmp);
	if (flag)
		ft_printf("ra\n");
	return (true);
}

bool	ft_rb(t_list **stack_b, bool flag)
{
	t_list	*top;
	t_list	*tmp;

	if (!(*stack_b) || (*stack_b)->next == (*stack_b))
		return (false);
	top = (t_list *)ft_calloc(1, sizeof(t_list));
	if (!top)
	{
		free(top);
		return (false);
	}
	tmp = top;
	top = (*stack_b);
	ft_lstadd_back(stack_b, top);
	(*stack_b) = (*stack_b)->next;
	free(tmp);
	if (flag)
		ft_printf("rb\n");
	return (true);
}

bool	ft_rra(t_list **stack_a, bool flag)
{
	t_list	*back;
	t_list	*tmp;

	if (!(*stack_a) || (*stack_a)->next == (*stack_a))
		return (false);
	back = (*stack_a);
	while (back->next->next != (*stack_a))
		back = back->next;
	tmp = back;
	ft_lstadd_front(stack_a, back->next);
	back->next = (*stack_a);
	if (flag)
		ft_printf("rra\n");
	return (true);
}

bool	ft_rrb(t_list **stack_b, bool flag)
{
	t_list	*back;
	t_list	*tmp;

	if (!(*stack_b) || (*stack_b)->next == (*stack_b))
		return (false);
	back = (*stack_b);
	while (back->next->next != (*stack_b))
		back = back->next;
	tmp = back;
	ft_lstadd_front(stack_b, back->next);
	back->next = (*stack_b);
	if (flag)
		ft_printf("rrb\n");
	return (true);
}
