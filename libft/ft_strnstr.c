/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:30:11 by cazerini          #+#    #+#             */
/*   Updated: 2024/12/03 17:51:32 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			j++;
			if (j == ft_strlen(little))
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char	lil[20] = "";
	char	big[20] = "world hello";
	char	*s;
	s = strnstr(big, lil, 5);

	printf("og :%s\n", s);
	printf("%s\n", ft_strnstr(big, lil, 5));
	return (0);
} */