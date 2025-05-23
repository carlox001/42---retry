/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:19:13 by apeero            #+#    #+#             */
/*   Updated: 2024/11/22 15:19:15 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		i;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substr = malloc(1);
		return (substr);
	}
	i = 0;
	substr = (char *)malloc((len + 1));
	if (substr == NULL)
		return (NULL);
	while (len > 0 && s[start] != '\0')
	{
		substr[i] = s[start];
		i++;
		start++;
		len--;
	}
	substr[i] = '\0';
	return (substr);
}
/* 
int main()
{
	char s[] = "suca palle";
	char *s2;
	unsigned int n = 10;
	int len = 10;
	s2 = ft_substr(s,n,len);
	printf("%s",s2);

} */
