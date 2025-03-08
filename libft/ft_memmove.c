/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:07:33 by cazerini          #+#    #+#             */
/*   Updated: 2024/11/22 17:58:00 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*temp_d;
	const unsigned char	*temp_s;

	temp_d = dest;
	temp_s = src;
	i = 0;
	if (temp_d <= temp_s)
		ft_memcpy(temp_d, temp_s, n);
	else
	{
		while (n > 0)
		{
			temp_d[n - 1] = temp_s[n - 1];
			n--;
		}
	}
	return (dest);
}

/* int	main(void)
{
	char	str[] = "hello world";
	char	str2[] = "this is a test.";

	printf("before (no overlap):  %s\n", str);
	ft_memmove(str + 6, str, 5);
	printf("after (no overlap):  %s\n", str);

	printf("before (overlap):  %s\n", str2);
	ft_memmove(str2 + 5, str2, 7);
	printf("after (overlap):  %s\n", str2);
	return (0);
} */