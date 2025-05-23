/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_gen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:16:31 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/12 12:37:06 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// prima parte dell'algoritmo:
//	- trovo l'elemento con costo minore;
//	- pusho in b;
//	- ordino in modo decrescente b;
void	put_in_b(t_head *head)
{
	t_list	*cheapest;

	ft_pb(head);
	while (count_elements((*head).head_a) > 3)
	{
		cost(&(*head).head_a);
		cost(&(*head).head_b);
		cheapest = first_cheapest_cost((*head).head_a, (*head).head_b);
		first_contemp_rotations(head, &(*head).head_b, cheapest);
		put_on_top(&(*head).head_a, cheapest->index, false);
		first_prepare_for_push(&(*head).head_b, cheapest, true);
		ft_pb(head);
	}
	put_in_ord_decresc(&(*head).head_b);
}

// seconda parte dell'algoritmo:
//	- trovo l'elemento con costo minore;
//	- pusho in a;
//	- ordino in modo crescente a;
void	put_in_a(t_head *head)
{
	t_list	*cheapest;

	case_3(&(*head).head_a, false);
	while ((*head).head_b)
	{
		cost(&(*head).head_a);
		cost(&(*head).head_b);
		cheapest = second_cheapest_cost((*head).head_b, (*head).head_a);
		second_contemp_rotations(head, &(*head).head_a, cheapest);
		put_on_top(&(*head).head_b, cheapest->index, true);
		second_prepare_for_push(&(*head).head_a, cheapest, false);
		ft_pa(head);
	}
	put_in_ord_cresc(&(*head).head_a);
}
