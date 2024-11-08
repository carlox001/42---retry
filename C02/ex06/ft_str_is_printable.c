/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:26:56 by cazerini          #+#    #+#             */
/*   Updated: 2024/10/21 20:29:50 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] <= 31 || str[i] == 127)
			return (0);
		i++;
	}
	return (1);
}

/* int	main(void)
{
	char	*str;
	int		i;

	str = "fffAA174329+=~";
	i = ft_str_is_printable(str);
	if (i == 1)
		printf("Solo caratteri stampabili");
	else
		printf("Carattere di altro tipo presente");
	return (0);
} */