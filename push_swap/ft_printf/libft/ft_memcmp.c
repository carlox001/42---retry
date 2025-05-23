/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:48:12 by apeero            #+#    #+#             */
/*   Updated: 2024/11/18 16:48:15 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(void const *str, void const *str2, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptr2;

	ptr = (unsigned char *)str;
	ptr2 = (unsigned char *)str2;
	while (n > 0)
	{
		if (*ptr != *ptr2)
		{
			if (*ptr < *ptr2)
				return (-1);
			return (1);
		}
		n--;
		ptr++;
		ptr2++;
	}
	return (0);
}
/* 
int main()
{
	char str[] = "mannaggia";
	char str2[] = "z chi ti porta fori";

	printf("%d",ft_memcmp(str,str2,0));

} */