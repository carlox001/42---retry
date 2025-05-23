/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 11:34:20 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/30 11:34:22 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digit(unsigned int n)
{
	int		number;

	number = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		number++;
	}
	return (number);
}

int	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	char	nb;

	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (n >= 10)
		ft_putnbr_unsigned_fd(n / 10, fd);
	nb = n % 10 + '0';
	write(fd, &nb, 1);
	return (count_digit(n));
}
