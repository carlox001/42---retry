/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:00:49 by cazerini          #+#    #+#             */
/*   Updated: 2024/10/21 20:16:45 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] <= 96 || str[i] >= 123)
			return (0);
		i++;
	}
	return (1);
}

/* int	main(void)
{
	char	*str;
	int		i;

	str = "1a";
	i = ft_str_is_lowercase(str);
	if (i == 1)
		printf("Solo caratteri alfabetici minuscoli");
	else
		printf("Carattere di altro tipo presente");
	return (0);
} */
