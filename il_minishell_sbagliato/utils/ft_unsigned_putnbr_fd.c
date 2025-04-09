/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:52:46 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/03 17:05:21 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/* void	ft_unsigned_putnbr_fd(unsigned int n, int fd)
{
	char	nb;

	if (n >= 10)
		ft_unsigned_putnbr_fd(n / 10, fd);
	nb = (n % 10) + '0';
	write (fd, &nb, 1);
} */

int	ft_unsigned_putnbr_fd(unsigned int n, int fd)
{
	char	nb[11];
	int		i;
	int		numb;

	i = 0;
	numb = n;
	if (n == 0)
		write(fd, "0", 1);
	while (n > 0)
	{
		nb[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (--i >= 0)
		write(fd, &nb[i], 1);
	return (ft_unsigned_numlen(numb));
}
