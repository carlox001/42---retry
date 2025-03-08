/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:54:51 by cazerini          #+#    #+#             */
/*   Updated: 2024/12/06 17:33:28 by cazerini         ###   ########.fr       */
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
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (arr == NULL)
		return (NULL);
	ft_strlcpy(arr, s, len + 1);
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		nb_wd;
	char	**arr;

	if (s == NULL)
		return (NULL);
	i = 0;
	nb_wd = memory_count_wd(s, c);
	arr = (char **)malloc(sizeof(char *) * (nb_wd + 1));
	if (arr == NULL)
		return (NULL);
	while (i < nb_wd)
	{
		while (*s == c && c != '\0')
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
	const char	*str = "";
	char	c = 'z';
	char	**arr;
	int		i = 0;

	arr = ft_split(str, c);
	while (arr[i])
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