/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:13:24 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/05 11:16:13 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ricerca dell'elemento con il costo minore:
// 	- calcolo il costo di ogni elemento sommando:
//		-> costo del push;
//		-> numero di rotazioni da eseguire;
//		-> mosse per riordinare stack_b
//	- ritorno l'indice dell'elemento con costo minore
//		(valore univoco per ogni stack);
t_list	*first_cheapest_cost(t_list *stack_1, t_list *stack_2)
{
	t_list	*tmp_1;
	t_list	*tmp_2;
	t_list	*cost;

	tmp_1 = stack_1;
	tmp_2 = first_find_place(stack_2, tmp_1->content);
	cost = tmp_1;
	cost->cost = 1 + rr_rrr_cost(tmp_1->index, tmp_2->index);
	while (tmp_1 != stack_1->prev)
	{
		tmp_2 = first_find_place(stack_2, tmp_1->content);
		if (cost->cost > (1 + ft_abs(rr_rrr_cost(tmp_1->index, tmp_2->index))))
		{
			cost = tmp_1;
			cost->cost = 1 + ft_abs(rr_rrr_cost(tmp_1->index, tmp_2->index));
		}
		tmp_1 = tmp_1->next;
	}
	tmp_2 = first_find_place(stack_2, tmp_1->content);
	if (cost->cost > (1 + ft_abs(rr_rrr_cost(tmp_1->index, tmp_2->index))))
		cost = tmp_1;
	return (cost);
}

// ricerca dell'elemento con il costo minore:
// 	- calcolo il costo di ogni elemento sommando:
//		-> costo del push;
//		-> numero di rotazioni da eseguire;
//		-> mosse per riordinare stack_a
//	- ritorno l'indice dell'elemento con costo minore
//		(valore univoco per ogni stack);
t_list	*second_cheapest_cost(t_list *stack_1, t_list *stack_2)
{
	t_list	*tmp_1;
	t_list	*tmp_2;
	t_list	*cost;

	tmp_1 = stack_1;
	tmp_2 = second_find_place(stack_2, tmp_1->content);
	cost = tmp_1;
	cost->cost = 1 + rr_rrr_cost(tmp_1->index, tmp_2->index);
	while (tmp_1 != stack_1->prev)
	{
		tmp_2 = second_find_place(stack_2, tmp_1->content);
		if (cost->cost > (1 + ft_abs(rr_rrr_cost(tmp_1->index, tmp_2->index))))
		{
			cost = tmp_1;
			cost->cost = 1 + ft_abs(rr_rrr_cost(tmp_1->index, tmp_2->index));
		}
		tmp_1 = tmp_1->next;
	}
	tmp_2 = first_find_place(stack_2, tmp_1->content);
	if (cost->cost > (1 + ft_abs(rr_rrr_cost(tmp_1->index, tmp_2->index))))
		cost = tmp_1;
	return (cost);
}

//per il calcolo dei costi (rotazioni totali);
int	rr_rrr_cost(int index_a, int index_b)
{
	int	a;
	int	b;

	a = ft_abs(index_a);
	b = ft_abs(index_b);
	if ((index_a > 0 && index_b > 0) || (index_a < 0 && index_b < 0))
	{
		if (a >= b)
			return (index_a);
		else if (a < b)
			return (index_b);
	}
	return (a + b);
}
