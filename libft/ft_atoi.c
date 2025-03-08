/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:13:19 by cazerini          #+#    #+#             */
/*   Updated: 2024/12/09 16:31:21 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_sign(const char *n, int i, int *index, int sign)
{
	int	count;

	count = 0;
	while (n[i] == '+' || n[i] == '-')
	{
		if (n[i] == '-')
			sign *= -1;
		if (count > 0)
			return (0);
		count++;
		i++;
	}
	*index = i;
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	sign = ft_check_sign(nptr, i, &i, sign);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (nptr[i] - 48) + (res * 10);
		i++;
	}
	return (res * sign);
}

/* int	main (void)
{
	//char	s[] = "";

	printf("og : %d\n", atoi("\t\n\r\v\f  1 \n"));
	printf("%d\n", ft_atoi("\t\n\r\v\f  1 \n"));
	return (0);
} */
