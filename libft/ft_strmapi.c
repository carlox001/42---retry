/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:33:22 by cazerini          #+#    #+#             */
/*   Updated: 2024/12/03 19:41:08 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;
	size_t	len;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[len] = '\0';
	return (str);
}

/* char	f(unsigned int i, char c)
{
	i += 0;
	c = (char)ft_toupper((unsigned char)c);
	return (c);
}

int	main(void)
{
	const char	*s = "LoReM iPsUm";
	char		*str;

	str = ft_strmapi(s, f);
	if (str == NULL)
		return (1);
	if (str[11] != '\0')
    	printf("\nString is not null terminated");
	printf("%s\n", str);
	free(str);
	return (0);
} */