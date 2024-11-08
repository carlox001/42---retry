/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:42:55 by cazerini          #+#    #+#             */
/*   Updated: 2024/10/16 19:24:45 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(int m, int n, int l)
{
	m += 48;
	n += 48;
	l += 48;
	write (1, &m, 1);
	write (1, &n, 1);
	write (1, &l, 1);
	if (m != '7' || n != '8' || l != '9')
		write (1, ", ", 2);
}

void	ft_print_comb(void)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i <= 7)
	{
		j = 1;
		while (j <= 8)
		{
			while (j <= i)
				j++;
			k = 2;
			while (k <= 9)
			{
				while (k <= j || k <= i)
					k++;
				ft_write(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
