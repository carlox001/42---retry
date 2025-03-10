/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:24:01 by cazerini          #+#    #+#             */
/*   Updated: 2024/12/02 12:25:06 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dst, const char *src, size_t size)
{
	size_t	i;

	if (src == NULL)
	{
		if (size > 0)
			dst[0] = '\0';
		return (0);
	}
	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = ft_strlen(src);
	return (i);
}

/* int	main(void)
{
	char	dst[] = "Messi";
	char	src[] = "ciao";

	printf("len: %ld\n", strlcpy(dst, src, 0));
	printf("dst: %s", dst);
	return (0);
} */