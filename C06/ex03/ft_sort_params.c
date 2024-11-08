/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:35:29 by cazerini          #+#    #+#             */
/*   Updated: 2024/11/07 19:15:45 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(char **str, int n)
{
	int	i;
	int	j;

	i = 1;
	while (i < n)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			write(1, &str[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		i;
	char	*tmp;
	int		j;
	int		n;

	n = 1;
	if (ac < 2)
		return (1);
	while (n < ac - 1)
	{
		i = 1;
		while (i < ac - n)
		{
			j = 0;
			while (av[i][j] == av[i + 1][j] && av[i][j] != '\0')
				j++;
			if (av[i][j] > av[i + 1][j])
			{
				tmp = av[i];
				av[i] = av[i + 1];
				av[i + 1] = tmp;
			}
			i++;
		}
		n++;
	}
	ft_write(av, ac);
	return (0);
}