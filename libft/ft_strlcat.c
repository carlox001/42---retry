/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:00:14 by cazerini          #+#    #+#             */
/*   Updated: 2024/11/21 20:18:03 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dest);
	if (src == NULL)
	{
		if (size - i > 0)
			dest[0] = '\0';
		return (0);
	}
	j = 0;
	if (size > 0)
	{
		while (j < size - i - 1)
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[i + j] = '\0';
	}
	i += ft_strlen(src);
	return (i);
}

int	main(void)
{
	char	dst[] = "hello ";
	char	src[] = "world";

	printf("len: %ld\n", strlcat(dst, src, 7));
	printf("dst: %s", dst);
	return (0);
}