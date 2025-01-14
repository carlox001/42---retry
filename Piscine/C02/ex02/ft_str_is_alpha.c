/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:09:49 by cazerini          #+#    #+#             */
/*   Updated: 2024/10/21 20:19:01 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] <= 64 || (str[i] >= 91 && str[i] <= 96) || str[i] >= 123)
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
	i = ft_str_is_alpha(str);
	if (i == 1)
		printf("Solo caratteri alfabetici");
	else
		printf("Carattere di altro tipo presente");
	return (0);
} */
