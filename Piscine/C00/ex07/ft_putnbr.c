/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:35:03 by cazerini          #+#    #+#             */
/*   Updated: 2024/10/21 16:35:27 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_helper(int n)
{
	n += 48;
	write(1, &n, 1);
}

void	ft_putnbr(int nb)
{
	long int	n;
	int			m[11];
	int			i;

	m[10] = '\0';
	i = 0;
	n = nb;
	if (n != 0)
	{
		if (nb < 0)
		{
			n = -n;
			write(1, "-", 1);
		}
		while (n > 0)
		{
			m[i++] = n % 10;
			n = n / 10;
		}
		while (--i >= 0)
			ft_helper(m[i]);
	}
	else
		ft_helper(n);
}

/* int	main(void)
{
	ft_putnbr(90);
	return (0);
}; */