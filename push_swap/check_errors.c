/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:17:38 by apeero            #+#    #+#             */
/*   Updated: 2025/03/23 16:51:32 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_char(char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (!(argv[j][i] >= '0' && argv[j][i] <= '9')
				&& !((argv[j][i] == '+' || argv[j][i] == '-')
					&& (argv[j][i + 1] >= '0' && argv[j][i + 1] <= '9')))
			{
				write(2, "Error\n", 6);
				return (false);
			}
			i++;
		}
		j++;
	}
	return (true);
}

bool	check_double(char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (argv[j])
	{
		i = j + 1;
		while (argv[i])
		{
			while (ft_atoi(argv[j]) == ft_atoi(argv[i]))
			{
				write(2, "Error\n", 6);
				return (false);
			}
			i++;
		}
		j++;
	}
	return (true);
}

long	ft_atol(const char *ptr)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	while (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' || \
	*ptr == '\v' || *ptr == '\f' || *ptr == '\r')
		ptr++;
	if (*ptr == '+' || *ptr == '-')
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	while (*ptr >= 48 && *ptr <= 57)
	{
		res = res * 10 + (*ptr - '0');
		ptr++;
	}
	return (res * sign);
}

int	is_number(char *av)
{
	int	i;

	i = 0;
	while ((av[i] == ' ' || av[i] == '\t' || av[i] == '\v' || av[i] == '\n'
			|| av[i] == '+' || av[i] == '-') && av[i])
		i++;
	while (av[i] >= 48 && av[i] <= 57)
		i++;
	if (av[i] != '\0')
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

bool	check_int(char **argv)
{
	int		j;
	long	res;

	j = 1;
	while (argv[j])
	{
		if (is_number(argv[j]) == 1)
			return (false);
		res = ft_atol(argv[j]);
		if (res > INT_MAX || res < INT_MIN)
		{
			write(2, "Error\n", 6);
			return (false);
		}
		j++;
	}
	return (true);
}
