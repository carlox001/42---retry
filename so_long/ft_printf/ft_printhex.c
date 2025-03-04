/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:50:38 by cazerini          #+#    #+#             */
/*   Updated: 2024/12/09 13:56:57 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_len(unsigned int n)
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

static void	ft_write(char *str, int len)
{
	str[len + 1] = '\0';
	while (len >= 0)
	{
		write(1, &str[len], 1);
		len--;
	}
	free(str);
}

int	ft_printhex_up(unsigned int nb)
{
	const char	h[] = "0123456789ABCDEF";
	int			len;
	char		*str;

	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	str = (char *)malloc(sizeof(char) * (ft_count_len(nb) + 1));
	if (!str)
		return (-1);
	len = 0;
	while (nb > 0)
	{
		str[len] = h[nb % 16];
		nb /= 16;
		len++;
	}
	ft_write(str, len - 1);
	return (len);
}

int	ft_printhex_low(unsigned int nb)
{
	const char	h[] = "0123456789abcdef";
	int			len;
	char		*str;

	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	str = (char *)malloc(sizeof(char) * (ft_count_len(nb) + 1));
	if (!str)
		return (-1);
	len = 0;
	while (nb > 0)
	{
		str[len] = h[nb % 16];
		nb /= 16;
		len++;
	}
	ft_write(str, len - 1);
	return (len);
}

/* int	main(void)
{
	//int		len;

	len = ft_printhex(-20, 'X');
	write(1, "\n", 1);
	printf("len: %d\n", len);long
	len = printf("%X", -20);
	printf("\nog len: %d\n", len);

	ft_printhex_up(-42);
	printf("\n%X", -42);

	return (0);
}
 */