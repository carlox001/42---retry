/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:34:16 by cazerini          #+#    #+#             */
/*   Updated: 2024/11/22 19:08:54 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	char	*str;

	ch = c;
	str = (char *)s;
	while (*str != ch && *str != '\0')
		str++;
	if (*str == ch)
		return (str);
	return (NULL);
}

/* int	main(void)
{
	int		c = '\0';
	char	*s = "hllo";

	printf("og : %s\n", strchr(s, c));
	printf("%s\n", ft_strchr(s, c));
	return (0);
} */