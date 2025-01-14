/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:15:07 by cazerini          #+#    #+#             */
/*   Updated: 2024/12/23 18:37:48 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*last_line_b(char *nextl, char c)
{
	int		i;
	int		j;
	char	*last;

	i = 0;
	while (nextl[i] != c && nextl[i])
		i++;
	if (nextl[i] == c)
		i += 1;
	last = (char *)malloc(sizeof(char) * (ft_strlen_b(nextl) - i + 1));
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

char	*ft_substr_b(char *str, char c)
{
	int		i;
	int		j;
	char	*sub;

	if (str == NULL)
		return (NULL);
	i = ft_strchr_b(str, c);
	if (i == -1)
		i = ft_strlen_b(str) + 1;
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

char	*read_line_b(char **nextl, char *buf, int fd)
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
		*(nextl) = ft_strjoin_b(*(nextl), buf);
		if (ft_strchr_b(*(nextl), '\n') >= 0)
			break ;
	}
	return (*(nextl));
}

char	*get_next_line(int fd)
{
	static char	*nextl[1024];
	char		*buf;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free (nextl[fd]);
		nextl[fd] = NULL;
		return (NULL);
	}
	nextl[fd] = read_line_b(&nextl[fd], buf, fd);
	free(buf);
	if (nextl[fd] == NULL)
		return (NULL);
	res = ft_substr_b(nextl[fd], '\n');
	nextl[fd] = last_line_b(nextl[fd], '\n');
	if (nextl[fd] != NULL && nextl[fd][0] == 0)
	{
		free(nextl[fd]);
		nextl[fd] = NULL;
	}
	return (res);
}

/* int	main(void)
{
	int		fd1;
	int		fd2;

	fd1 = open("pls.txt", O_RDONLY);
	fd2 = open("prova.txt", O_RDONLY);
	if (fd1 < 0)
	{
		close(fd1);
		return (0);
	}
	if (fd2 < 0)
	{
		close(fd2);
		return (0);
	}
	while (1)
	{
		char *s1 = get_next_line(fd1);
		if (!s1)
			break;
		printf("%s\n", s1);
		free (s1);
	}
	while (1)
	{
		char *s2 = get_next_line(fd2);
		if (!s2)
			break;
		printf("%s\n", s2);
		free (s2);
	}
	close(fd1);
	close(fd2);
	return (0);
} */
