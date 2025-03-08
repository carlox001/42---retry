/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:17:20 by cazerini          #+#    #+#             */
/*   Updated: 2024/11/25 16:26:06 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/* int	main(void)
{
	int	i = 0;
	int	*arr = (int *)ft_calloc(0, 0);

	if (arr == NULL)
		return (1);
	i = 0;
	while (arr[i])
	{
		printf("%d", arr[i]);
		i++;
	}
	printf("\n");
	free(arr);
	return (0);
} */