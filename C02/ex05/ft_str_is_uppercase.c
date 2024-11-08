/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:22:40 by cazerini          #+#    #+#             */
/*   Updated: 2024/10/21 20:26:44 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] <= 64 || str[i] >= 91)
			return (0);
		i++;
	}
	return (1);
}

/* int	main(void)
{
	char	*str;
	int		i;

	str = "";
	i = ft_str_is_uppercase(str);
	if (i == 1)
		printf("Solo caratteri alfabetici maiuscoli");
	else
		printf("Carattere di altro tipo presente");
	return (0);
} */