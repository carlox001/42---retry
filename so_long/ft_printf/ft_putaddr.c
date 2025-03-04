/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:10:33 by cazerini          #+#    #+#             */
/*   Updated: 2024/12/21 13:24:12 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_nil(void *ptr)
{
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (0);
	}
	return (1);
}

static int	ft_count_len(unsigned long long addr)
{
	int	i;

	i = 0;
	while (addr > 0)
	{
		addr /= 10;
		i++;
	}
	return (i);
}

static void	ft_write(char *str, int len)
{
	write(1, "0x", 2);
	while (len >= 0)
	{
		write(1, &str[len], 1);
		len--;
	}
	free(str);
}

int	ft_putaddr(void *ptr)
{
	unsigned long long	addr;
	int					len;
	char				*str;

	if (ft_check_nil(ptr) == 0)
		return (5);
	addr = (unsigned long long)ptr;
	if (addr == 0)
	{
		write(1, "0x0", 3);
		return (1);
	}
	str = (char *)malloc(sizeof(char) * (ft_count_len(addr) + 1));
	if (!str)
		return (-1);
	len = 0;
	while (addr > 0)
	{
		str[len] = "0123456789abcdef"[addr % 16];
		addr /= 16;
		len++;
	}
	str[len] = '\0';
	ft_write(str, len - 1);
	return (len + 2);
}

/* int	main(void)(unsigned long long)
{
	char	*s;
	int		len;

	len = ft_putaddr(s);
	write(1, "\n", 1);
	printf("len: %d\n", len);
	len = printf("%p", s);
	printf("\nog len: %d\n", len);
	return (0);
}  */