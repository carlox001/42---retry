/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:41:10 by cazerini          #+#    #+#             */
/*   Updated: 2024/12/02 17:20:51 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*str;
	size_t			i;

	ch = c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n && str[i] != ch)
		i++;
	if (str[i] == ch && i < n)
		return ((void *)str + i);
	return (NULL);
}

/* int	main(void)
{
	int		c = 'n';
	char	*s = "bonjourno";

	printf("og : %s\n", (char *)memchr(s, c, 2));
	printf("%s\n", (char *)ft_memchr(s, c, 2));
	return (0);
} */