/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:34:59 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/12 12:34:42 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fillstack(t_list **head, int content)
{
	t_list			*new_node;
	t_list			*current;
	static t_list	*prev;

	new_node = (t_list *)ft_calloc(1, sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->content = content;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		current = (*head);
		current->prev = new_node;
		new_node->next = current;
		while (current->next != (*head))
			current = current->next;
		current->next = new_node;
		new_node->prev = prev;
	}
	prev = new_node;
}

void	ft_free_stack(t_list **stack)
{
	t_list	*current;
	t_list	*tmp;

	if (!(*stack))
		return ;
	current = (*stack)->next;
	while (current != *stack)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(current);
}

void	free_all(t_head *head)
{
	ft_free_stack(&head->head_a);
	ft_free_stack(&head->head_b);
	free(head);
}
