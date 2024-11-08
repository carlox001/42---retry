/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:54:55 by cazerini          #+#    #+#             */
/*   Updated: 2024/10/30 17:18:02 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int	ft_power(int j)
{
	int	nb;

	nb = 1;
	while (j > 0)
	{
		nb *= 10;
		j--;
	}
	return (nb);
}

int	conversion(int n, char *base)
{
	int	i;
	static int	j = 0;

	i = 0;
	while (base[i] != '\0')
		i++;
	if (n >= i)
	{
		conversion(n / i, base);
		n %= i;
	}
	n += base[n] * ft_power(j);
	j++;
	return (n);
}

int	ft_putnbr_base(int nbr, char *base)
{
	long int	n;

	n = nbr;
	if (check_base(base) == 0)
		return (0);
	n = conversion(n, base);
	return (n);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	n;
	int	sign;

	sign = 1;
	n = 0;
	i = 0;
	while (str[i] >= 9 && str[i] <= 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	n = ft_putnbr_base(n, base);
	return (sign * n);
}

int	main(void)
{
	char	base[] = "01";
	char	str[] = "  ---+--+12ab567";

	printf("res: %d", ft_atoi_base(str, base));
	return (0);
}