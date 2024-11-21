/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:54:51 by cazerini          #+#    #+#             */
/*   Updated: 2024/11/21 17:52:06 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	memory_count_wd(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

static char	*cpy_wd(const char *s, char c, char *arr)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	arr = (char *)malloc(sizeof(char) * len);
	if (arr == NULL)
		return (NULL);
	while (i < len)
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		nb_wd;
	char	**arr;

	i = 0;
	nb_wd = memory_count_wd(s, c);
	arr = (char **)malloc(sizeof(char *) * nb_wd);
	if (arr == NULL)
		return (NULL);
	while (i < nb_wd)
	{
		if (*s == c)
			s++;
		if (*s != '\0')
			arr[i] = cpy_wd(s, c, arr[i]);
		if (arr[i] == NULL)
			free(arr);
		while (*s != c && *s != '\0')
			s++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

/* int	main(void)
{
	const char	str[15] = "iaiciao";
	char	c = 'c';
	char	**arr;
	int		i = 0;

	arr = ft_split(str, c);
	while (i < 3)
	{
		printf("%s\n", arr[i]);
		i++;
	}
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
} */