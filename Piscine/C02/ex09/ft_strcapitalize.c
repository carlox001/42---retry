/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:40:50 by cazerini          #+#    #+#             */
/*   Updated: 2024/11/05 17:44:31 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && (str[i] >= 'a' && str[i] <= 'z'))
			str[i] -= 32;
		else if ((!(str[i - 1] >= 'A' && str[i -1] <= 'Z')
				&& !(str[i - 1] >= 'a' && str[i - 1] <= 'z'))
			&& !(str[i - 1] >= '0' && str[i - 1] <= '9')
			&& ((str[i + 1] >= 'A' && str[i + 1] <= 'Z')
				|| (str[i + 1] >= 'a' && str[i + 1] <= 'z'))
			&& (str[i] >= 'a' && str[i] <= 'z'))
			str[i] -= 32;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

/* int	main(void)
{
	char	str[] = "";
	int		i;

	i = 0;
	ft_strcapitalize(str);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}
 */
