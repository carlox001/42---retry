/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:11:03 by cazerini          #+#    #+#             */
/*   Updated: 2024/11/22 19:24:34 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*str;
	size_t	i;

	ch = c;
	str = (char *)s;
	i = ft_strlen(str);
	while (str[i] != ch && i > 0)
		i--;
	if (str[i] == ch)
		return (&str[i]);
	return (NULL);
}

/* int	main(void)
{
	int		c = 'a';
	char	*s = "hlloa";

	printf("og : %s\n", strrchr(s, c));
	printf("%s\n", ft_strrchr(s, c));
	return (0);
} */