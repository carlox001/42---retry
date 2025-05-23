/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:58:16 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/12 12:25:03 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*second_control_min(t_list *stack, int element)
{
	t_list	*min;
	t_list	*tmp;

	min = find_min(&stack);
	tmp = stack;
	if (element < min->content)
	{
		while (tmp->index != min->index)
			tmp = tmp->next;
		return (tmp);
	}
	return (NULL);
}

t_list	*second_control_max(t_list *stack, int element)
{
	t_list	*max;
	t_list	*tmp;

	max = find_max(&stack);
	tmp = stack;
	if (element > max->content)
	{
		while (tmp->index != max->index)
			tmp = tmp->next;
		return (tmp->next);
	}
	return (NULL);
}
