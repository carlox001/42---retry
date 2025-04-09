/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:02:26 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/03 17:04:47 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*smell;

	smell = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			smell = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *) smell);
}

//  int main()
// {
// 	char a[] = "cacato";
// 	char b[] = "a";
// 	printf("%s", ft_strrchr(a, *b));
// 	return(0);
// }