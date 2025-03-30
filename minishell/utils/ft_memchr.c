/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:08:36 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/03 17:04:47 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*a;

	a = (const unsigned char *)s;
	while (n--)
	{
		if (*a == (unsigned char)c)
		{
			return ((void *)a);
		}
		a++;
	}
	return (NULL);
}

// int main()
// {
// 	char b[] = "E` L`ORA DELLO SBUSO";
// 	printf("%s", (char *)ft_memchr(b, 'T', 10000000));
// 	return(0);
// }