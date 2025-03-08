/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:59:32 by cazerini          #+#    #+#             */
/*   Updated: 2024/12/02 15:16:18 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] == str2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	if (str1[i] > str2[i])
		return (1);
	else if (str1[i] < str2[i])
		return (-1);
	return (0);
}

/* int	main(void)
{
	const char	*s1 = "abcdefghij";
	const char *s2 = "abcdefgxyz";

	printf("%d\n", memcmp(s1, s2, 7));
	printf("%d\n", ft_memcmp(s1, s2, 7));
	return (0);
} */