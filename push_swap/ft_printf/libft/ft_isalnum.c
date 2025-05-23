/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeero <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:16:54 by apeero            #+#    #+#             */
/*   Updated: 2024/11/18 15:16:56 by apeero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

/* int main()
{
	printf("Numero: %d",ft_isalnum('8'));
	printf("Maiuscola: %d",ft_isalnum('A'));
	printf("Minuscola: %d",ft_isalnum('p'));
	printf("Carattere speciale: %d",ft_isalnum('/'));
} */
