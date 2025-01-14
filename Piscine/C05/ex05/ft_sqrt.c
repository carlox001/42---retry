/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:38:24 by cazerini          #+#    #+#             */
/*   Updated: 2024/11/05 18:18:42 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	if (nb > 0)
	{
		while (i < nb / i)
			i++;
		if (i * i == nb && i <= 46340)
			return (i);
	}
	return (0);
}

/* int	main(void)
{
	printf("res : %d", ft_sqrt(144));
	return (0);
} */