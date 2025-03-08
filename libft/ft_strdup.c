/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:28:00 by cazerini          #+#    #+#             */
/*   Updated: 2024/11/23 15:52:57 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;

	dup = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, s, (ft_strlen(s) + 1));
	return (dup);
}

/* int	main(void)
{
	const char s[] = "\0";

	printf("%s\n", strdup(s));
	printf("%s\n", ft_strdup(s));
	return (0);
} */