/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:00:14 by cazerini          #+#    #+#             */
/*   Updated: 2024/12/02 11:41:05 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dest);
	j = 0;
	if (size > i)
	{
		while (j < size - i - 1 && src[j] != '\0')
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[i + j] = '\0';
	}
	j = ft_strlen(src);
	if (i >= size)
		return (j + size);
	return (i + j);
}

/* int	main(void)
{
	char	dst[10] = "a";
	char	src[] = "lorem ipsum dolor sit amet";

	printf("og len: %zu\n", strlcat(dst, src, 0));
	printf("og dst: %s\n", dst);

	char	d[10] = "a";
	char	s[] = "lorem ipsum dolor sit amet";

	printf("len: %zu\n", ft_strlcat(d, s, 0));
	printf("dst: %s", d);
	return (0);
} */