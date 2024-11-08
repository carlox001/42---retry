/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:39:07 by cazerini          #+#    #+#             */
/*   Updated: 2024/10/21 17:27:07 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n)
{
	int	a;
	int	b;
	int	nb;
	int	b;

	nb = 10;
	if (n > 0 && n < 10)
	{
		a = 0;
		while (a <= nb - n)
		{
			b = a + (n - 1);
			while (b > a)
			{
				ft_helper(b);
				b--;
			}
			ft_helper(a);
			a++;
		}
	}
		
}