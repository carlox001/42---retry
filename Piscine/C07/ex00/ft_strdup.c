/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:56:22 by cazerini          #+#    #+#             */
/*   Updated: 2024/11/07 20:07:45 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*buf;

	j = 0;
	i = 0;
	while (src[i] != '\0')
		i++;
	buf = (char *)malloc(sizeof(char) * (i + 1));
	if (buf == NULL)
		return (NULL);
	while (j <= i)
	{
		buf[j] = src[j];
		j++;
	}
	return (buf);
}

int	main(void)
{
	char	*src = "Hello World";

	printf("%s", ft_strdup(src));
	return (0);
}