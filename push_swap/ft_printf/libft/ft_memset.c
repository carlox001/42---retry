/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:02:01 by apeero            #+#    #+#             */
/*   Updated: 2024/11/18 16:02:03 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (n > 0)
	{
		n--;
		ptr[n] = c;
	}
	return (ptr);
}
/* 
int  main()
{
    char str[] = "Ciao bella";
    ft_memset(str,48,4);
    printf("%s",str);
} */