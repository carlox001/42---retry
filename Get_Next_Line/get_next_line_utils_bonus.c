/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:26:33 by cazerini          #+#    #+#             */
/*   Updated: 2024/12/23 16:45:02 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr_b(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i + 1);
	return (-1);
}

char	*ft_strdup_b(char *buf)
{
	int		i;
	char	*res;

	res = (char *)malloc(sizeof(char) * (ft_strlen_b(buf) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (buf[i])
	{
		res[i] = buf[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

size_t	ft_strlen_b(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_b(char *nextl, char *buf)
{
	int		i;
	int		j;
	char	*res;

	if (nextl == NULL)
	{
		nextl = ft_strdup_b(buf);
		return (nextl);
	}
	res = (char *)malloc((ft_strlen_b(nextl) + ft_strlen_b(buf) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (nextl[i])
	{
		res[i] = nextl[i];
		i++;
	}
	j = -1;
	while (buf[++j])
		res[i + j] = buf[j];
	res[i + j] = '\0';
	free(nextl);
	return (res);
}
