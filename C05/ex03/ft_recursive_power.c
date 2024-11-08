/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:21:18 by cazerini          #+#    #+#             */
/*   Updated: 2024/11/01 16:13:54 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (nb < 0 || power < 0)
		return (0);
	else if (power == 0 || nb == 0)
		return (1);
	nb *= ft_recursive_power(nb, power - 1);
	return (nb);
}

/* int	main(void)
{
	printf("res : %d", ft_recursive_power(5, 2));
	return (0);
} */