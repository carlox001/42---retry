/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:25:51 by cazerini          #+#    #+#             */
/*   Updated: 2024/10/23 18:45:49 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_helper(int n)
{
	char	c;

	c = n + 48;
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 00;
	b = 01;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_helper(a / 10);
			ft_helper(a % 10);
			write(1, " ", 1);
			ft_helper(b / 10);
			ft_helper(b % 10);
			if (a != 98 || b != 99)
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}

/* int	main(void)
{
	ft_print_comb2();
	return (0);
} */
