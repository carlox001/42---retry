/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 12:01:25 by cazerini          #+#    #+#             */
/*   Updated: 2024/10/20 12:10:32 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	if (*a != 0 && *b != 0)
	{
		div = *a / *b;
		mod = *a % *b;
		*a = div;
		*b = mod;
	}
	else
	{
		*a = 0;
		*b = 0;
	}
}

/* int	main(void)
{
	int	*a;
	int	*b;
	int	c;
	int	d;

	c = 10;
	d = 3;
	a = &c;
	b = &d;
	ft_ultimate_div_mod(a, b);
	printf("a = %d, b = %d\n", c, d);
	return (0);
} */