/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:56:48 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/12 12:38:03 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	control_order_decresc(t_list **stack)
{
	t_list	*tmp;
	t_list	*min;

	min = find_min(stack);
	tmp = (*stack);
	while (tmp != (*stack)->prev && tmp->index != min->index)
	{
		if (tmp->content < tmp->next->content)
			return (false);
		tmp = tmp->next;
	}
	if (tmp != (*stack) || tmp->index != min->index)
		return (false);
	return (true);
}

bool	control_order_cresc(t_list **stack)
{
	t_list	*tmp;
	t_list	*max;

	max = find_max(stack);
	tmp = (*stack);
	while (tmp != (*stack)->prev && tmp->index != max->index)
	{
		if (tmp->content > tmp->next->content)
		{
			return (false);
		}
		tmp = tmp->next;
	}
	if (tmp->next != (*stack) || tmp->index != max->index)
		return (false);
	return (true);
}

t_list	*first_control_min(t_list *stack, int element)
{
	t_list	*min;
	t_list	*tmp;

	min = find_min(&stack);
	tmp = stack;
	if (element < min->content)
	{
		while (tmp->index != min->index)
			tmp = tmp->next;
		return (tmp->next);
	}
	return (NULL);
}

t_list	*first_control_max(t_list *stack, int element)
{
	t_list	*max;
	t_list	*tmp;

	max = find_max(&stack);
	tmp = stack;
	if (element > max->content)
	{
		while (tmp->index != max->index)
			tmp = tmp->next;
		return (tmp);
	}
	return (NULL);
}
