/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:52:32 by cazerini          #+#    #+#             */
/*   Updated: 2024/11/25 15:19:21 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = 0;
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * i);
	if (str == NULL)
		return (NULL);
	while (s1[j] != '\0')
	{
		str[j] = s1[j];
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[i + j] = s2[i];
		i++;
	}
	str[i + j] = '\0';
	return (str);
}

/* int	main(void)
{
	const char	*s2 = NULL;
	const char	s1[] = "";

	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
} */