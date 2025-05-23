/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:01:01 by apeero            #+#    #+#             */
/*   Updated: 2024/11/18 17:01:03 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	ptr = (unsigned char *)dest;
	ptr2 = (const unsigned char *)src;
	while (n > 0)
	{
		*ptr = *ptr2;
		ptr++;
		ptr2++;
		n--;
	}
	return (dest);
}
/* 
int main()
{
	char src[] = "she is just a girl";
	char dest[5];
	int n = 0;
	printf("SRC: %s\n",src);
	printf("DEST PRIMA: %s\n",dest);
	ft_memcpy(dest,src, 2);
	printf("DEST DOPO: %s",dest);
	while (n < 2)
	{
		printf("dhn");
		write(1,&dest[n],1);
		n++;
	}
} */