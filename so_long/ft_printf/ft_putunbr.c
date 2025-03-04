/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:59:06 by cazerini          #+#    #+#             */
/*   Updated: 2024/12/09 18:10:05 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_len(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_write_nbr(long int nb)
{
	if (nb > 9)
		ft_write_nbr(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
}

int	ft_putunbr(unsigned int n)
{
	unsigned long int	nb;
	static int			len;

	nb = n;
	len = 0;
	ft_write_nbr(nb);
	len += ft_count_len(nb);
	return (len);
}

/* int	main(void)
{
	int	len;

	len = ft_printf("\n %u %u %u %u", INT_MAX, INT_MIN, 0, -42);
	printf("\nlen: %d\n", len);
	len = printf("\n %u %u %u %u", INT_MAX, INT_MIN, 0, -42);
	printf("\nlen: %d\n", len);
	return (0);
	return (0);
} */