/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:17:38 by apeero            #+#    #+#             */
/*   Updated: 2024/11/24 15:17:38 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*str)
	{
		if (*str != c && j == 0)
		{
			j = 1;
			i++;
		}
		else if (*str == c)
			j = 0;
		str++;
	}
	return (i);
}

static char	*ft_allochar(const char *s, char c, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	while (*s && *s != c)
	{
		str[i++] = *s++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**mat;
	size_t	i;
	int		len;

	i = 0;
	if (!s)
		return (NULL);
	mat = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!mat)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			mat[i++] = ft_allochar(s, c, len);
			s += len;
		}
		else
			s++;
	}
	mat[i] = NULL;
	return (mat);
}

/* 
int main() {
    char *s = "lorem ipsum dolor sit amet consectetur
	adipiscing elit Sed non risus. Suspendisse";
    char c = ' ';
    char **mat;
    int i = 0;

    mat = ft_split(s, c);
    while (mat[i] != NULL) {  // Changed condition to check for NULL pointer
        printf("%s\n", mat[i]);  // Print the whole substring
        i++;
    }
    free(mat);  // Free the array of strings

    return 0;
} */
