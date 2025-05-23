/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:41:10 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/10 18:34:23 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_elements(t_list *stack)
{
	t_list	*tmp;
	int		count;

	tmp = stack;
	count = 1;
	while (tmp->content != stack->prev->content)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	rr_rrr_do(int index_a, int index_b)
{
	int	a;
	int	b;

	a = ft_abs(index_a);
	b = ft_abs(index_b);
	if ((index_a > 0 && index_b > 0) || (index_a < 0 && index_b < 0))
	{
		if (a >= b)
			return (index_b);
		else if (a < b)
			return (index_a);
	}
	return (0);
}

int	ft_abs(int num)
{
	int	nb;

	if (num >= 0)
		nb = num;
	else
		nb = num * (-1);
	return (nb);
}

void	start_and_finish(t_head *head, int argc)
{
	cost(&(*head).head_a);
	hub_cases(head, argc - 1);
	free_all(head);
}

/* void	print_list(t_list *a, int stack)
{
	t_list	*tmp;
	int		i;

	if (stack == 0)
		printf("Lista: a\n");
	else
		printf("Lista: b\n");
	tmp = a;
	i = 1;
	while (tmp && tmp->next != a)
	{
		printf("%d: %d -- next: %d -- prev: %d\n", i, \
			tmp->content, tmp->next->content, tmp->prev->content);
		i++;
		tmp = tmp->next;
	}
	if (tmp)
		printf("%d: %d -- next: %d -- prev: %d\n", i, \
			tmp->content, tmp->next->content, tmp->prev->content);
	
}

void	print_cost(t_list *a, int stack)
{
	t_list	*tmp;
	int		i;

	if (stack == 0)
		printf("Lista: a\n");
	else
		printf("Lista: b\n");
	tmp = a;
	i = 1;
	while (tmp->next != a)
	{
		printf("%d | cost: %d\n", tmp->content, tmp->index);
		i++;
		tmp = tmp->next;
	}
	printf("%d | cost: %d\n", tmp->content, tmp->index);
} */
