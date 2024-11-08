/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:52:06 by cazerini          #+#    #+#             */
/*   Updated: 2024/10/21 20:17:22 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] <= 47 || str[i] >= 58)
			return (0);
		i++;
	}
	return (1);
}

/* int	main(void)
{
	char	*str;
	int		i;

	str = "aaaa3";
	i = ft_str_is_numeric(str);
	if (i == 1)
		printf("Solo caratteri numerici");
	else
		printf("Carattere di altro tipo presente");
	return (0);
} */