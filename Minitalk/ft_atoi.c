/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czerini <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:32:01 by czerini           #+#    #+#             */
/*   Updated: 2023/09/19 12:53:05 by czerini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_atoi(char *str)
{
	int	i;
	int	n;
	int	sign;

	sign = 1;
	n = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (sign * n);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = " ---+--+1234ab567";
	
	printf("%d", ft_atoi(str));
	return (0);
}*/
