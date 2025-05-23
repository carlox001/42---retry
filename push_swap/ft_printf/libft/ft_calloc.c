/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:13:53 by apeero            #+#    #+#             */
/*   Updated: 2024/11/18 19:13:56 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	int		*ptr;

	ptr = malloc(size * nitems);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nitems * size);
	return (ptr);
}
/* 
int main()
{
	int n = 5;
	int *array;
	
	array = (int*)ft_calloc(n, sizeof(int));
	for(int i = 0; i < n; i++)
	{
		printf("N: %d\nValue: %d\n",i,array[i]);
	}
	free(array);
	return 0;
} */