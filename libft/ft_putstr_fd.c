/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:47:54 by cazerini          #+#    #+#             */
/*   Updated: 2024/11/25 15:27:52 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

/* int	main(void)
{
	int		fd;
	char	*c = NULL;

	fd = open("a.txt", O_WRONLY | O_CREAT , S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		printf("Errore nell'apertura\n");
		return (1);
	}
	ft_putstr_fd(c, fd);
	if (close(fd) == -1)
	{
		printf("Error nella scrittura\n");
		return (1);
	}
	return (0);
} */