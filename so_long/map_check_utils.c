/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:23:18 by cazerini          #+#    #+#             */
/*   Updated: 2025/02/23 16:06:49 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game, int x, int y)
{
	if (game->mtx.dup[x][y] == '1' || game->mtx.dup[x][y] == 'x'
		|| game->mtx.dup[x][y] == 'E' || game->mtx.dup[x][y] == 'W')
		return ;
	game->mtx.dup[x][y] = 'x';
	flood_fill(game, x, (y + 1));
	flood_fill(game, x, (y - 1));
	flood_fill(game, (x + 1), y);
	flood_fill(game, (x - 1), y);
}

int	player_pos(t_game *game)
{
	game->mtx.x = 0;
	while (game->mtx.map[game->mtx.x])
	{
		game->mtx.y = 0;
		while (game->mtx.map[game->mtx.x][game->mtx.y] != '\0'
				&& game->mtx.map[game->mtx.x][game->mtx.y] != '\n')
		{
			if (game->mtx.map[game->mtx.x][game->mtx.y] == 'P'
			|| game->mtx.map[game->mtx.x][game->mtx.y] == 'L'
			|| game->mtx.map[game->mtx.x][game->mtx.y] == 'R'
			|| game->mtx.map[game->mtx.x][game->mtx.y] == 'B')
				return (0);
			game->mtx.y++;
		}
		game->mtx.x++;
	}
	return (1);
}

int	cpe_count(t_game *game)
{
	while (game->mtx.map[game->mtx.x] != NULL)
	{
		game->mtx.y = 0;
		while (game->mtx.map[game->mtx.x][game->mtx.y] != '\n'
				&& game->mtx.map[game->mtx.x][game->mtx.y] != '\0')
		{
			if (game->mtx.map[game->mtx.x][game->mtx.y] == 'C')
				game->mtx.count++;
			if (game->mtx.map[game->mtx.x][game->mtx.y] == 'E')
				game->mtx.e++;
			if (game->mtx.map[game->mtx.x][game->mtx.y] == 'P')
				game->mtx.p++;
			if (game->mtx.map[game->mtx.x][game->mtx.y] != 'P'
				&& game->mtx.map[game->mtx.x][game->mtx.y] != 'C'
				&& game->mtx.map[game->mtx.x][game->mtx.y] != 'E'
				&& game->mtx.map[game->mtx.x][game->mtx.y] != '0'
				&& game->mtx.map[game->mtx.x][game->mtx.y] != '1'
				&& game->mtx.map[game->mtx.x][game->mtx.y] != 'S')
				game->mtx.o++;
			game->mtx.y++;
		}
		game->mtx.x++;
	}
	return (check_cpe_count(game));
}

int	check_walls(t_game *game)
{
	game->mtx.x = 0;
	while (game->mtx.map[game->mtx.x + 1] != NULL)
	{
		if (game->mtx.map[game->mtx.x][0] != '1'
			|| game->mtx.map[game->mtx.x][game->mtx.len - 1] != '1')
			return (ft_printf("The walls! Where are they??\n"));
		game->mtx.x++;
	}
	game->mtx.y = 0;
	while (game->mtx.map[0][game->mtx.y]
		&& game->mtx.map[game->mtx.x][game->mtx.y]
			&& game->mtx.y < game->mtx.len)
	{
		if (game->mtx.map[0][game->mtx.y] != '1'
			|| game->mtx.map[game->mtx.x][game->mtx.y] != '1')
			return (ft_printf("This is not how you build a wall.\n"));
		game->mtx.y++;
	}
	return (0);
}

int	is_rectangle(t_game *game)
{
	game->mtx.x = 0;
	while (game->mtx.map[game->mtx.x] != NULL)
	{
		game->mtx.y = 0;
		while (game->mtx.map[game->mtx.x][game->mtx.y] != '\0'
			&& game->mtx.map[game->mtx.x][game->mtx.y] != '\n')
			game->mtx.y++;
		if (game->mtx.y != game->mtx.len)
			return (ft_printf("Invalid width!\n"));
		game->mtx.x++;
	}
	if ((game->mtx.x < 2 || game->mtx.y < 4)
		&& (game->mtx.x < 4 || game->mtx.y < 2))
		return (ft_printf("Invalid dimensions!\n"));
	return (0);
}
