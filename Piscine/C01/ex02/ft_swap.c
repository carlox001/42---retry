/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:13:31 by cazerini          #+#    #+#             */
/*   Updated: 2024/10/25 16:19:35 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int*b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/* int	main(void)
{
	int	a;
	int	b;

	a = 5;
	b = 9;
	ft_swap(&x, &y);
	printf("a = %d, b = %d\n", a, b);
	return (0);
}
 */