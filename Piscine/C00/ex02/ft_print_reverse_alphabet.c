/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:23:48 by cazerini          #+#    #+#             */
/*   Updated: 2024/10/16 17:26:56 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	int	i;

	i = 122;
	while (i > 96)
	{
		write (1, &i, 1);
		i--;
	}
}

/* int	main(void)
{
	ft_print_reverse_alphabet();
	return (0);
} */
