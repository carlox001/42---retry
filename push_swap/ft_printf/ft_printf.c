/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 11:34:30 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/30 11:34:32 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		value;

	value = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i] != '\0')
		{
			value += ft_conversions((char *)&str[i], &arg);
			i++;
		}
		else
			value += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(arg);
	return (value);
}
