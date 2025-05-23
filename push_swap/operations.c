/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:55:23 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/03 19:22:55 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_head *head)
{
	int	flag_a;
	int	flag_b;

	flag_a = ft_sa(&(*head).head_a, false);
	flag_b = ft_sb(&(*head).head_b, false);
	if (!flag_a || !flag_b)
	{
		if (!flag_b)
			ft_printf("sa\n");
		else if (!flag_a)
			ft_printf("sb\n");
		return ;
	}
	ft_printf("ss\n");
}

void	ft_rr(t_head *head)
{
	int	flag_a;
	int	flag_b;

	flag_a = ft_ra(&(*head).head_a, false);
	flag_b = ft_rb(&(*head).head_b, false);
	if (!flag_a || !flag_b)
	{
		if (!flag_b)
			ft_printf("ra\n");
		else if (!flag_a)
			ft_printf("rb\n");
		return ;
	}
	ft_printf("rr\n");
}

void	ft_rrr(t_head *head)
{
	int	flag_a;
	int	flag_b;

	flag_a = ft_rra(&(*head).head_a, false);
	flag_b = ft_rrb(&(*head).head_b, false);
	if (!flag_a || !flag_b)
	{
		if (!flag_b)
			ft_printf("rra\n");
		else if (!flag_a)
			ft_printf("rrb\n");
		return ;
	}
	ft_printf("rrr\n");
}
