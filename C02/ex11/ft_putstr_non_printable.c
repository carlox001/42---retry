/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:20:48 by cazerini          #+#    #+#             */
/*   Updated: 2024/10/23 19:44:59 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_helper(unsigned char n)
{
	const char	hex[16] = "0123456789abcdef";

	write(1, &hex[n], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] < 127))
		{
			write(1, "\\", 1);
			ft_helper((unsigned char)str[i] / 16);
			ft_helper((unsigned char)str[i] % 16);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
/*
int	main(void)
{
	char	str[] = "Coucou\tu vas bien ?";
 
	ft_putstr_non_printable(str);
	return (0);
}*/
