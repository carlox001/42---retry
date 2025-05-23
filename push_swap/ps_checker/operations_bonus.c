/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:15:49 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/05 14:01:36 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_ss(t_head *head)
{
	ft_sa(&(*head).head_a);
	ft_sb(&(*head).head_b);
}

void	ft_rr(t_head *head)
{
	ft_ra(&(*head).head_a);
	ft_rb(&(*head).head_b);
}

void	ft_rrr(t_head *head)
{
	ft_rra(&(*head).head_a);
	ft_rrb(&(*head).head_b);
}
