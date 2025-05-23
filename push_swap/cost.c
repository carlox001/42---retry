/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:54:47 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/05 10:56:01 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	uneven(t_list **stack, t_list *tmp, int len)
{
	int		i;

	len++;
	i = 0;
	while (i < len / 2)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
	i = (i - 1) * (-1);
	while (tmp->next != (*stack))
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
	tmp->index = i;
}

void	even(t_list **stack, t_list *tmp, int len)
{
	int		i;

	i = 0;
	while (i <= len / 2)
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
	i = (i - 2) * (-1);
	while (tmp->next != (*stack))
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
	tmp->index = i;
}

void	put_index(t_list **head, int len)
{
	t_list	*tmp;

	tmp = (*head);
	if (len % 2 == 0)
		even(head, tmp, len);
	else
		uneven(head, tmp, len);
}

void	cost(t_list **stack)
{
	int		len;
	t_list	*tmp;
	int		i;

	tmp = (*stack);
	len = 0;
	while (tmp->next != (*stack))
	{
		tmp = tmp->next;
		len++;
	}
	len++;
	tmp = (*stack);
	i = 0;
	if (len == 2)
	{
		while (i < len)
		{
			tmp->index = i;
			i++;
			tmp = tmp->next;
		}
	}
	else
		put_index(stack, len);
}
