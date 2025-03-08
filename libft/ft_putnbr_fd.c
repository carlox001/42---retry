/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:16:43 by cazerini          #+#    #+#             */
/*   Updated: 2024/11/25 11:34:21 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_helper(int n, int fd)
{
	n += 48;
	ft_putchar_fd(n, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	int			m[11];
	int			i;

	m[10] = '\0';
	i = 0;
	nb = n;
	if (nb != 0)
	{
		if (n < 0)
		{
			nb = -nb;
			write(fd, "-", 1);
		}
		while (nb > 0)
		{
			m[i++] = nb % 10;
			nb = nb / 10;
		}
		while (--i >= 0)
			ft_helper(m[i], fd);
	}
	else
		ft_helper(nb, fd);
}

/* int	main(void)
{
	int	fd;

	fd = open("a.txt", O_WRONLY | O_CREAT , S_IRUSR | S_IWUSR, 0644);
	if (fd == -1)
	{
		printf("Errore in apertura\n");
		return (1);
	}
	ft_putnbr_fd(-2147483648, fd);
	if (close(fd) == -1)
	{
		printf("Errore in scrittura\n");
		return (1);
	}
	return (0);
} */