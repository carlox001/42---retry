/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:06:55 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/10 18:05:32 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_on_top(t_list **stack, int index, bool flag)
{
	if (!flag)
	{
		while ((*stack)->index != index)
		{
			if (index > 0)
				ft_ra(stack, true);
			else if (index < 0)
				ft_rra(stack, true);
		}
	}
	else
	{
		while ((*stack)->index != index)
		{
			if (index > 0)
				ft_rb(stack, true);
			else
				ft_rrb(stack, true);
		}
	}
}

void	put_in_ord_decresc(t_list **stack_b)
{
	t_list	*max;

	max = find_max(stack_b);
	while (!control_order_decresc(stack_b))
	{
		if (max->index > 0)
			ft_rb(stack_b, true);
		else
			ft_rrb(stack_b, true);
		cost(stack_b);
	}
}

void	put_in_ord_cresc(t_list **stack_a)
{
	t_list	*min;

	min = find_min(stack_a);
	while (!control_order_cresc(stack_a))
	{
		if (min->index > 0)
			ft_ra(stack_a, true);
		else
			ft_rra(stack_a, true);
		cost(stack_a);
	}
}
