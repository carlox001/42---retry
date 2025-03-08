/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:54:21 by cazerini          #+#    #+#             */
/*   Updated: 2024/11/25 11:16:06 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/* int	main(void)
{
	int		fd;
	char	c[] = "HELLO WORLD";

	fd = open("a.txt", O_WRONLY | O_CREAT , S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		printf("Errore nell'apertura\n");
		return (1);
	}
	ft_putendl_fd(c, fd);
	if (close(fd) == -1)
	{
		printf("Error nella scrittura\n");
		return (1);
	}
	return (0);
} */