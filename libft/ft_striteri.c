/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:57:21 by cazerini          #+#    #+#             */
/*   Updated: 2024/12/01 14:20:04 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/* 
void	f(unsigned int i, char *c)
{
	i += 0;
	*c = (char)ft_toupper((unsigned int)*c);
}

int	main(void)
{
	char	s[] = "Hello Wordl";

	ft_striteri(s, f);
	printf("%s\n", s);
	return (0);
} */