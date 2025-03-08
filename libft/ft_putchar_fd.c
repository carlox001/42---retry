/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:21:53 by cazerini          #+#    #+#             */
/*   Updated: 2024/12/02 14:21:31 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* int	main(void)
{
	int		fd;
	char	c = 'c';

	fd = open("a.txt", O_WRONLY | O_CREAT , S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		printf("Errore nell'apertura\n");
		return (1);
	}
	ft_putchar_fd(c, fd);
	if (close(fd) == -1)
	{
		printf("Error nella scrittura\n");
		return (1);
	}
	return (0);
} */