/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:36:42 by sfiorini          #+#    #+#             */
/*   Updated: 2025/02/03 17:04:47 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			count;
	unsigned char	*a;

	count = 0;
	a = (unsigned char *) s;
	while (count < n)
	{
		a[count] = 0;
		count++;
	}
}

// int main()
// {
// 	char b[5];
// 	ft_bzero(b, 5);
// 	printf("%s", b);
// 	return(0);
// }