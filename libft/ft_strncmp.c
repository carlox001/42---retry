/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:25:41 by cazerini          #+#    #+#             */
/*   Updated: 2024/12/02 14:43:33 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (str1[i] == str2[i] && i < n && str1[i] != '\0' && str2[i] != '\0')
		i++;
	if (i == n)
		return (0);
	return (str1[i] - str2[i]);
}

/* int	main(void)
{
	const char	*s1 = "t";
	const char *s2 = "";

	printf("%d\n", strncmp(s1, s2, 0));
	printf("%d\n", ft_strncmp(s1, s2, 0));
	return (0);
} */