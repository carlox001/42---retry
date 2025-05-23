/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:35:30 by apeero            #+#    #+#             */
/*   Updated: 2024/11/18 16:35:32 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memchr(void const *str, int c, size_t n)
{
	unsigned int		i;
	unsigned char		*ptr;

	ptr = (unsigned char *)str;
	i = 0;
	while (n > 0)
	{
		if (ptr[i] == (unsigned char)c)
		{
			return ((void *)(ptr + i));
		}
		i++;
		n--;
	}
	return (NULL);
}
/* 
int main()
{
	char str[] = "bye bye bye";
	char b = 'b';
	printf("%s",ft_memchr(str,b,100));
} */