/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:56:20 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/03 17:04:47 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned long	count;
	unsigned char	*a;

	count = 0;
	a = (unsigned char *)s;
	while (count < n)
	{
		a[count] = (unsigned char)c;
		count++;
	}
	return (s);
}

// int main(void)
// {
// 	char a[6];	
// 	printf("%s", (char *)ft_memset(a, 'A', 5));
// 	return(0);
// }