/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:25:19 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/05 14:01:36 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	start_finish(t_head *head)
{
	read_move(head);
	final_control(head);
	ft_free_stack(&head->head_a);
	ft_free_stack(&head->head_b);
}

void	final_control(t_head *head)
{
	if (control_order_cresc(&(*head).head_a) && !(*head).head_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

//ritorna l'elemento maggiore dello stack
t_list	*find_max(t_list **stack)
{
	t_list	*tmp;
	t_list	*max;

	tmp = (*stack);
	max = (*stack);
	while (tmp != (*stack)->prev)
	{
		if (max->content < tmp->content)
			max = tmp;
		tmp = tmp->next;
	}
	if (max->content < tmp->content)
		max = tmp;
	return (max);
}

bool	control_order_cresc(t_list **stack)
{
	t_list	*tmp;
	t_list	*max;

	max = find_max(stack);
	tmp = (*stack);
	while (tmp != (*stack)->prev && tmp->content != max->content)
	{
		if (tmp->content > tmp->next->content)
		{
			return (false);
		}
		tmp = tmp->next;
	}
	if (tmp->next != (*stack) || tmp->content != max->content)
		return (false);
	return (true);
}

t_list	*find_last_node(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp->next != stack)
		tmp = tmp->next;
	return (tmp);
}
