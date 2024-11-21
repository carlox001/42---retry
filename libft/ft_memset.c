/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:46:18 by cazerini          #+#    #+#             */
/*   Updated: 2024/11/18 15:18:25 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*str;
	unsigned char	l;

	str = s;
	l = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		str[i] = l;
		i++;
	}
	return (s);
}

/* int	main(void)
{
	int	s[5];
	int	i = 0;

	ft_memset(s, 0, 8 * sizeof(int));
	while (i < 5)
	{
		printf("s[%d] = %d\n", i, s[i]);
		i++;
	}
	return (0);
} */