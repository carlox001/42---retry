/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:32:40 by cazerini          #+#    #+#             */
/*   Updated: 2024/10/30 17:49:40 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	n;
	int	res;

	n = 1;
	res = 1;
	if (nb < 0)
		return (0);
	while (n <= nb)
	{
		res *= n;
		n++;
	}
	return (res);
}

/* int	main(void)
{
	printf("res : %d", ft_iterative_factorial(7));
	return (0);
} */
