/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:02:43 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/03 17:04:47 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	check_nsign(const char *nptr, int i)
{
	if (nptr[i] == '+')
	{
		i++;
		if (nptr[i] == '+' || nptr[i] == '-')
			return (1);
	}
	if (nptr[i] == '-')
	{
		i++;
		if (nptr[i] == '+' || nptr[i] == '-')
			return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	minus;
	int	number;
	int	sign;

	i = 0;
	minus = 1;
	number = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	sign = check_nsign(nptr, i);
	if (sign == 1)
		return (0);
	while (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			minus *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10 + (nptr[i] - '0');
		i++;
	}
	return (number * minus);
}

// int main()
// {
// 	char *a = "+-2367";
// 	char *b = "-+4";
// 	char *c = "--276";
// 	char *d = "+32";
// 	printf("%d\n", ft_atoi(a));
// 	printf("%d\n", ft_atoi(b));
// 	printf("%d\n", ft_atoi(c));
// 	printf("%d\n", ft_atoi(d));
// 	return(0);
// }
