/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:15:37 by apeero            #+#    #+#             */
/*   Updated: 2024/11/22 15:15:47 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	checkpos(int nb, int fd)
{
	int		number;
	char	n;

	number = nb;
	if (number == 0)
		return ;
	number = nb / 10;
	checkpos(number, fd);
	n = nb % 10 + '0';
	write(fd, &n, 1);
}

static void	checkneg(int nb, int fd)
{
	int		number;
	char	n;

	number = nb;
	if (number == 0)
		return ;
	number = nb / 10;
	checkneg(number, fd);
	n = nb % 10 + '0';
	write(fd, &n, 1);
}

static int	count_digit(int n)
{
	int		number;

	number = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		number++;
	while (n != 0)
	{
		n /= 10;
		number++;
	}
	return (number);
}

int	ft_putnbr_fd(int n, int fd)
{
	int		number;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n == 0)
	{
		number = 48;
		write(fd, &number, 1);
		return (1);
	}
	if (n < 0)
	{
		number = 45;
		write(fd, &number, 1);
		checkneg(n * -1, fd);
	}
	if (n > 0)
		checkpos(n, fd);
	return (count_digit(n));
}
