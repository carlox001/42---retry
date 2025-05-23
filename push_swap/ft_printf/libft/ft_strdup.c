/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:44:59 by apeero            #+#    #+#             */
/*   Updated: 2024/11/20 17:45:04 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

static int	len(const char *s)
{
	int		len;

	len = 0;
	while (*s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	char	*start;

	ptr = (char *)malloc(sizeof(char) * (len(s) + 1));
	if (!ptr)
		return (NULL);
	start = ptr;
	while (*s != '\0')
	{
		*ptr = *s;
		s++;
		ptr++;
	}
	*ptr = '\0';
	return (start);
}

/* 
int main(void)
{
	char *string = "this is a copy";
	printf("The new string is: %s\n", ft_strdup(string));
	return 0;
} */