/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:57:27 by cazerini          #+#    #+#             */
/*   Updated: 2024/10/30 18:22:25 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	n;

	n = nb;
	if (nb < 0 || power < 0)
		return (0);
	if (power == 0 || nb == 0)
		return (1);
	while (power > 1)
	{
		nb *= n;
		power--;
	}
	return (nb);
}

/* int	main(void)
{
	printf("res : %d", ft_iterative_power(2, 5));
	return (0);
} */