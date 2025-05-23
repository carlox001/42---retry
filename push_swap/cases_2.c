/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:51:02 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/30 11:26:24 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_gen(t_head *head)
{
	put_in_b(head);
	put_in_a(head);
}

void	hub_cases(t_head *head, int argc)
{
	if (control_order_cresc(&(*head).head_a))
		return ;
	if (argc == 2)
		case_2(&(*head).head_a, 0);
	else if (argc == 3)
		case_3(&(*head).head_a, 0);
	else if (argc == 4)
		case_4(&(*head).head_a, head);
	else
		case_gen(head);
}
