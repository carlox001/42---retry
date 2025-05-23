/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:03:34 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/10 17:57:44 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

//ritorna l'elemento minore dello stack
t_list	*find_min(t_list **stack)
{
	t_list	*tmp;
	t_list	*min;

	tmp = (*stack);
	min = (*stack);
	while (tmp != (*stack)->prev)
	{
		if (min->content > tmp->content)
			min = tmp;
		tmp = tmp->next;
	}
	if (min->content > tmp->content)
		min = tmp;
	return (min);
}

t_list	*find_last_node(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp->next != stack)
		tmp = tmp->next;
	return (tmp);
}

//trova la posizione in cui inserire l'elemento,
//restituisce l'elemento successivo
t_list	*first_find_place(t_list *stack, int element)
{
	t_list	*tmp;

	tmp = first_control_max(stack, element);
	if (tmp)
		return (tmp);
	tmp = first_control_min(stack, element);
	if (tmp)
		return (tmp);
	tmp = stack;
	while (tmp != stack->prev)
	{
		if (element < tmp->prev->content
			&& element > tmp->content)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

//trova la posizione in cui inserire l'elemento,
//restituisce l'elemento successivo
t_list	*second_find_place(t_list *stack, int element)
{
	t_list	*tmp;

	tmp = second_control_max(stack, element);
	if (tmp)
		return (tmp);
	tmp = second_control_min(stack, element);
	if (tmp)
		return (tmp);
	tmp = stack;
	while (tmp != stack->prev)
	{
		if (element > tmp->prev->content
			&& element < tmp->content)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}
