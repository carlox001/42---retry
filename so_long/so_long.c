/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:16:52 by cazerini          #+#    #+#             */
/*   Updated: 2025/01/23 15:30:02 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_printf("Invalid number of arguments!\n"));
	if (check_map(av[1], &game) == 0)
	{
		free_mtx(&game, game.mtx.dup);
		free_mtx(&game, game.mtx.map);
		return (1);
	}
	if (win_management(&game) == 0)
	{
		free_mtx(&game, game.mtx.map);
		return (1);
	}
	return (0);
}
