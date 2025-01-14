/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:02:37 by cazerini          #+#    #+#             */
/*   Updated: 2024/10/29 20:16:49 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	conversion(int n, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	if (n >= i)
	{
		conversion(n / i, base);
		n %= i;
	}
	write(1, &base[n], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	n;

	n = nbr;
	if (check_base(base) == 0)
		write(1, "Error : invalid base\n", 21);
	if (nbr < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	conversion(n, base);
}

/* int	main(void)
{
	char	base[] = "01234567";
	ft_putnbr_base(16, base);
	return (0);
} */
