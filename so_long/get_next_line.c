/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:15:07 by cazerini          #+#    #+#             */
/*   Updated: 2025/02/23 15:35:55 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*last_line(char *nextl, char c)
{
	int		i;
	int		j;
	char	*last;

	i = 0;
	while (nextl[i] != c && nextl[i])
		i++;
	if (nextl[i] == c)
		i += 1;
	last = (char *)malloc(sizeof(char) * (ft_strlen_gnl(nextl) - i + 1));
	if (!last)
		return (NULL);
	j = 0;
	while (nextl[i + j])
	{
		last[j] = nextl[i + j];
		j++;
	}
	last[j] = '\0';
	free(nextl);
	return (last);
}

char	*ft_substr(char *str, char c)
{
	int		i;
	int		j;
	char	*sub;

	if (str == NULL)
		return (NULL);
	i = ft_strchr(str, c);
	if (i == -1)
		i = ft_strlen_gnl(str) + 1;
	sub = (char *)malloc(sizeof(char) * (i + 2));
	if (!sub)
		return (NULL);
	j = -1;
	while (str[++j] && j < i - 1 && str[j] != c)
		sub[j] = str[j];
	if (str && str[j] == c)
		sub[j++] = '\n';
	sub[j] = '\0';
	return (sub);
}

char	*read_line(char **nextl, char *buf, int fd)
{
	int		check;

	check = 1;
	while (check > 0)
	{
		check = read(fd, buf, BUFFER_SIZE);
		if (check < 0)
		{
			if (*(nextl) != NULL)
				free(*(nextl));
			return (NULL);
		}
		buf[check] = '\0';
		if (check == 0 && !*(nextl))
			return (NULL);
		if (check == 0 && *(nextl)[0] == 0)
			return (NULL);
		*(nextl) = ft_strjoin(*(nextl), buf);
		if (ft_strchr(*(nextl), '\n') >= 0)
			break ;
	}
	return (*(nextl));
}

char	*get_next_line(int fd)
{
	static char	*nextl = NULL;
	char		*buf;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		if (nextl != NULL)
			free (nextl);
		return (NULL);
	}
	nextl = read_line(&nextl, buf, fd);
	free(buf);
	if (nextl == NULL)
		return (NULL);
	res = ft_substr(nextl, '\n');
	nextl = last_line(nextl, '\n');
	if (nextl != NULL && nextl[0] == 0)
	{
		free(nextl);
		nextl = NULL;
	}
	return (res);
}
