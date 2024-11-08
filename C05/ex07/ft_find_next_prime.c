/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:31:57 by cazerini          #+#    #+#             */
/*   Updated: 2024/11/06 16:37:47 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_find_next_prime(int nb)
{
	int	n;
	int	i;

	i = 2;
	n = nb;
	if (nb < 0 || nb == 0 || nb == 1)
		return (2);
	while (i < nb / 2 && nb % i != 0)
		i++;
	if (nb % i == 0)
		n = ft_find_next_prime(nb + 1);
	return (n);
}

/* int	main(void)
{
	printf("res : %d", ft_find_next_prime(-91));
	return (0);
} */