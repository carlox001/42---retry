/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:17:44 by cazerini          #+#    #+#             */
/*   Updated: 2024/10/28 17:39:26 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int unsigned	j;
	int unsigned	len;

	len = 0;
	j = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[len] != '\0')
		len++;
	while (src[j] != '\0' && i < (size - 1))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (i + len);
}

/* int	main(void)
{
	char	*src = "world!";
	char	dest[10] = "hello";
	unsigned int	i;

	i = ft_strlcat(dest, src, 7);
	printf("num : %d\n", i);
	printf("res : %s\n", dest);
	return (0);
} */