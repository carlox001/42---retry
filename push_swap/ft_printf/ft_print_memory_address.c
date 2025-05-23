/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory_address.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 11:34:35 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/30 11:34:37 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digit(unsigned long long n)
{
	int		number;

	number = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		number++;
	}
	return (number);
}

static void	ft_to_hex_lowercase(unsigned long long num, int fd)
{
	int		bf;
	char	*bff;

	bff = "0123456789abcdef";
	if (num == 0)
		return ;
	bf = (((unsigned char) num) % 16);
	num /= 16;
	ft_to_hex_lowercase(num, fd);
	write(1, &bff[bf], fd);
}

int	ft_print_memory_address(void *ptr, int fd)
{
	if (!ptr)
		return (ft_putstr_fd("(nil)", fd));
	write(fd, "0x", 2);
	ft_to_hex_lowercase((unsigned long long)ptr, fd);
	return (count_digit((unsigned long long)ptr) + 2);
}
