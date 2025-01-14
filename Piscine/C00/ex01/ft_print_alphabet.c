/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:49:01 by cazerini          #+#    #+#             */
/*   Updated: 2024/10/16 17:22:08 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	int	i;

	i = 97;
	while (i < 123)
	{
		write (1, &i, 1);
		i++;
	}
}

/* int	main(void)
{
	ft_print_alphabet();
	return (0);
} */
