/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:06:35 by cazerini          #+#    #+#             */
/*   Updated: 2024/10/23 19:36:26 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (size == 0)
		return (len);
	while (i < (size - 1) && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

/* int	main(void)
{
	char			dest[10];
	char			src[] = "Hello World";
	unsigned int	size;
	unsigned int	i;

	size = 11;
	i = ft_strlcpy(dest, src, size);
	printf("size copied : %d\n", i);
	printf("source : %s\n", src);
	printf("dest : %s\n", dest);
	return (0);
}
*/
