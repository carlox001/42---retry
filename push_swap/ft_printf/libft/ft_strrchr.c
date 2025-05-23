/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:04:59 by apeero            #+#    #+#             */
/*   Updated: 2024/11/20 15:05:00 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		n;

	n = 0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			ptr = (char *)s;
			n = 1;
		}
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	else if (c != '\0' && n == 0)
		return (NULL);
	return ((char *)ptr);
}
/* 
int main()
{
    char s[] = "mannaggia a te";
	char n = ' ';
    printf("VERA:%s\n",strrchr(s,n));
	printf("MIA:%s",ft_strrchr(s,n));
}
 */