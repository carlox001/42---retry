/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 11:34:40 by cazerini          #+#    #+#             */
/*   Updated: 2025/03/30 11:34:42 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_conversions(char *str, va_list *arg)
{
	if (*(str + 1) == 'd' || *(str + 1) == 'i')
		return (ft_putnbr_fd(va_arg(*arg, int), 1));
	else if (*(str + 1) == 'c')
		return (ft_putchar_fd(va_arg(*arg, int), 1));
	else if (*(str + 1) == 's')
		return (ft_putstr_fd(va_arg(*arg, char *), 1));
	else if (*(str + 1) == 'u')
		return (ft_putnbr_unsigned_fd(va_arg(*arg, int), 1));
	else if (*(str + 1) == 'p')
		return (ft_print_memory_address(va_arg(*arg, void *), 1));
	else if (*(str + 1) == 'x' || *(str + 1) == 'X')
		return (ft_to_hex(va_arg(*arg, int), 1,*(str + 1)));
	else if (*(str + 1) == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

/* int main()
{	
	printf("%d\n",5345);
	ft_conversions("%d\n",5345);
}
 */