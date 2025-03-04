/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:52:33 by cazerini          #+#    #+#             */
/*   Updated: 2025/01/18 10:19:30 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cases(char c, va_list argp)
{
	if (c == 'c')
		return (ft_putchar(va_arg(argp, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(argp, char *)));
	else if (c == 'p')
		return (ft_putaddr(va_arg(argp, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(argp, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(argp, unsigned int)));
	else if (c == 'x')
		return (ft_printhex_low(va_arg(argp, int)));
	else if (c == 'X')
		return (ft_printhex_up(va_arg(argp, int)));
	else if (c == '%')
	{
		write(1, "%%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	argp;
	int		len;
	int		i;

	if (str == NULL)
		return (-1);
	i = 0;
	len = 0;
	va_start(argp, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			len += cases(str[i], argp);
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		str++;
	}
	va_end(argp);
	return (len);
}

/* int main(void)
{
	int		len;
	//char	*a = "CIAO";
	//int	a = -42;

	len = printf("%\n");
	printf("len : %d\n", len);
	len = ft_printf("%\n");
	printf("len : %d\n", len);
	return (0);
} */