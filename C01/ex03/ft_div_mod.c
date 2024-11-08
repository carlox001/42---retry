/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 11:27:38 by cazerini          #+#    #+#             */
/*   Updated: 2024/10/20 12:04:47 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>
#include <unistd.h> */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (a != 0 && b != 0)
	{
		*div = a / b;
		*mod = a % b;
	}
	else
	{
		*div = 0;
		*mod = 0;
	}
}

/* int	main(void)
{
	int	a;
	int	b;
	int	*div;
	int	*mod;
	int	i;
	int	k;

	i = 0;
	k = 0;
	div = &i;
	mod = &k;
	a = 10;
	b = 3;
	ft_div_mod(a, b, div, mod);
	printf("a = %d, b = %d, div = %d, mod %d\n", a, b, i, k);
	return (0);
} */