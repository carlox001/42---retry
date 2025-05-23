/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:41:35 by apeero            #+#    #+#             */
/*   Updated: 2024/07/25 11:41:37 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, char const *src, size_t size)
{
	size_t				i;
	size_t				cont;

	i = -1;
	cont = 0;
	if (src == NULL)
		return (ft_strlen(dest));
	while (src[++i])
		cont++;
	if (size <= 0)
		return (cont);
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i = -1;
	cont = 0;
	while (src[++i])
		cont++;
	return (cont);
}

/* int main()
{	

	char	dest[10];

	printf("ft: (%zu) ", ft_strlcpy(dest, "aasdjj;s;sa", 100));
	printf("%s\n", dest);
}
 */
