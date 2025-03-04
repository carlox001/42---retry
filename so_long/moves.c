/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:08:38 by cazerini          #+#    #+#             */
/*   Updated: 2025/02/23 15:44:51 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	lost(t_game *game, int x, int y)
{
	if (game->mtx.map[x][y] == 'S' || game->mtx.map[x][y] == 'W'
		|| game->mtx.map[x][y] == 'A' || game->mtx.map[x][y] == 'D')
	{
		print_game_over();
		ft_close(game);
		return (1);
	}
	return (0);
}

void	up(t_game *game)
{
	if (player_pos(game))
		return ;
	if (game->mtx.map[game->mtx.x - 1][game->mtx.y] == '1')
		return ;
	if (game->mtx.map[game->mtx.x - 1][game->mtx.y] == 'E')
	{
		if (game->mtx.c_count == game->mtx.count)
		{
			print_victory();
			ft_close(game);
		}
		return ;
	}
	if (lost(game, game->mtx.x - 1, game->mtx.y))
		return ;
	if (game->mtx.map[game->mtx.x - 1][game->mtx.y] == 'C')
		game->mtx.c_count++;
	game->win.moves += 1;
	game->mtx.map[game->mtx.x - 1][game->mtx.y] = 'B';
	game->mtx.map[game->mtx.x][game->mtx.y] = '0';
}

void	down(t_game *game)
{
	if (player_pos(game))
		return ;
	if (game->mtx.map[game->mtx.x + 1][game->mtx.y] == '1')
		return ;
	if (game->mtx.map[game->mtx.x + 1][game->mtx.y] == 'E')
	{
		if (game->mtx.c_count == game->mtx.count)
		{
			print_victory();
			ft_close(game);
		}
		return ;
	}
	if (lost(game, game->mtx.x + 1, game->mtx.y))
		return ;
	if (game->mtx.map[game->mtx.x + 1][game->mtx.y] == 'C')
		game->mtx.c_count++;
	game->win.moves += 1;
	game->mtx.map[game->mtx.x + 1][game->mtx.y] = 'P';
	game->mtx.map[game->mtx.x][game->mtx.y] = '0';
}

void	right(t_game *game)
{
	if (player_pos(game))
		return ;
	if (game->mtx.map[game->mtx.x][game->mtx.y + 1] == '1')
		return ;
	if (game->mtx.map[game->mtx.x][game->mtx.y + 1] == 'E')
	{
		if (game->mtx.c_count == game->mtx.count)
		{
			print_victory();
			ft_close(game);
		}
		return ;
	}
	if (lost(game, game->mtx.x, game->mtx.y + 1))
		return ;
	if (game->mtx.map[game->mtx.x][game->mtx.y + 1] == 'C')
		game->mtx.c_count++;
	game->win.moves += 1;
	game->mtx.map[game->mtx.x][game->mtx.y + 1] = 'R';
	game->mtx.map[game->mtx.x][game->mtx.y] = '0';
}

void	left(t_game *game)
{
	if (player_pos(game))
		return ;
	if (game->mtx.map[game->mtx.x][game->mtx.y - 1] == '1')
		return ;
	if (game->mtx.map[game->mtx.x][game->mtx.y - 1] == 'E')
	{
		if (game->mtx.c_count == game->mtx.count)
		{
			print_victory();
			ft_close(game);
		}
		return ;
	}
	if (lost(game, game->mtx.x, game->mtx.y - 1))
		return ;
	if (game->mtx.map[game->mtx.x][game->mtx.y - 1] == 'C')
		game->mtx.c_count++;
	game->win.moves += 1;
	game->mtx.map[game->mtx.x][game->mtx.y - 1] = 'L';
	game->mtx.map[game->mtx.x][game->mtx.y] = '0';
}
