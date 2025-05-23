/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_and_second.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:10:15 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/05 11:11:24 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//prepara lo stack per pushare un elemento nella posizione giusta
//flag:
//	- true: stack_b;
//	- false: stack_a;
void	first_prepare_for_push(t_list **stack, t_list *element, bool flag)
{
	t_list	*pos;

	pos = first_find_place((*stack), element->content);
	put_on_top(stack, pos->index, flag);
}

void	first_contemp_rotations(t_head *head, t_list **stack, t_list *cheapest)
{
	int		rot;
	t_list	*tmp;

	tmp = first_find_place((*stack), cheapest->content);
	rot = rr_rrr_do(cheapest->index, tmp->index);
	while (rot != 0)
	{
		if (rot > 0)
		{
			ft_rr(head);
			rot--;
		}
		else
		{
			ft_rrr(head);
			rot++;
		}
	}
}

//prepara lo stack per pushare un elemento nella posizione giusta
//flag:
//	- true: stack_b;
//	- false: stack_a;
void	second_prepare_for_push(t_list **stack, t_list *element, bool flag)
{
	t_list	*pos;

	pos = second_find_place((*stack), element->content);
	put_on_top(stack, pos->index, flag);
}

void	second_contemp_rotations(t_head *head, t_list **stack, t_list *cheapest)
{
	int		rot;
	t_list	*tmp;

	tmp = second_find_place((*stack), cheapest->content);
	rot = rr_rrr_do(cheapest->index, tmp->index);
	while (rot != 0)
	{
		if (rot > 0)
		{
			ft_rr(head);
			rot--;
		}
		else
		{
			ft_rrr(head);
			rot++;
		}
	}
}
