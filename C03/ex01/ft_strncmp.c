/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:08:01 by cazerini          #+#    #+#             */
/*   Updated: 2024/10/25 16:53:07 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n - 1 && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/* int	main(void)
{
	char	*s1 = "Helloll";
	char	*s2 = "Ciao";
	int		i;

	i = ft_strncmp(s1, s2, 3);
	printf("res : %d", i);
	return (0);
} */
