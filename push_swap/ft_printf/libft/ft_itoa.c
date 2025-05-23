/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:13:12 by apeero            #+#    #+#             */
/*   Updated: 2024/11/22 18:13:16 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int num)
{
	int		i;

	i = 0;
	if (num <= 0)
		i = 1;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;
	long	num;

	num = n;
	count = ft_len(num);
	str = malloc((count + 1) * sizeof(char));
	str[count] = '\0';
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
	{
		str[0] = '0';
	}
	while (num != 0)
	{
		str[--count] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
/* 

int main ()
{
    int num;

    num = 0;
    printf("%s",ft_itoa(num));
} */