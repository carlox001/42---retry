/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:47:07 by cazerini          #+#    #+#             */
/*   Updated: 2025/02/25 17:23:06 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_2(t_list **stack, bool flag)
{
	if (!flag)
	{
		if ((*stack)->content > (*stack)->next->content)
			ft_sa(stack, true);
	}
	else
	{
		if ((*stack)->content > (*stack)->next->content)
			ft_sb(stack, true);
	}
}

void	case_3_a(t_list **stack)
{
	if ((*stack)->content < (*stack)->next->content
		&& (*stack)->content < (*stack)->next->next->content)
		ft_sa(stack, true);
	if ((*stack)->content > (*stack)->next->content
		&& (*stack)->content > (*stack)->next->next->content)
		ft_ra(stack, true);
	if ((*stack)->content > (*stack)->next->content
		&& (*stack)->content < (*stack)->next->next->content)
		ft_sa(stack, true);
	if ((*stack)->content < (*stack)->next->content
		&& (*stack)->content > (*stack)->next->next->content)
		ft_rra(stack, true);
}

void	case_3_b(t_list **stack)
{
	if ((*stack)->content < (*stack)->next->content
		&& (*stack)->content < (*stack)->next->next->content)
		ft_sb(stack, true);
	if ((*stack)->content > (*stack)->next->content
		&& (*stack)->content > (*stack)->next->next->content)
		ft_rb(stack, true);
	if ((*stack)->content > (*stack)->next->content
		&& (*stack)->content < (*stack)->next->next->content)
		ft_sb(stack, true);
	if ((*stack)->content < (*stack)->next->content
		&& (*stack)->content > (*stack)->next->next->content)
		ft_rrb(stack, true);
}

void	case_3(t_list **stack, bool flag)
{
	if (!flag)
		case_3_a(stack);
	else
		case_3_b(stack);
}

void	case_4(t_list **stack, t_head *head)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*stack)->next;
	tmp2 = tmp;
	while (tmp != (*stack))
	{
		if (tmp2->content > tmp->content)
			tmp2 = tmp;
		tmp = tmp->next;
	}
	if (tmp2->content > tmp->content)
		tmp2 = tmp;
	while ((*stack)->content != tmp2->content)
	{
		if (tmp2->index > 0)
			ft_ra(stack, true);
		else
			ft_rra(stack, true);
	}
	ft_pb(head);
	case_3(stack, 0);
	ft_pa(head);
	return ;
}
