/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:08:00 by cazerini          #+#    #+#             */
/*   Updated: 2025/02/23 16:08:41 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_en(t_game *game)
{
	int	num;

	num = rand() % 4;
	if (num == 0)
		en_up(game);
	else if (num == 1)
		en_down(game);
	else if (num == 2)
		en_left(game);
	else if (num == 3)
		en_right(game);
}

void	en_up(t_game *game)
{
	if (game->mtx.map[game->mtx.x - 1][game->mtx.y] == '1'
		|| game->mtx.map[game->mtx.x - 1][game->mtx.y] == 'E'
		|| game->mtx.map[game->mtx.x - 1][game->mtx.y] == 'C'
		|| game->mtx.map[game->mtx.x - 1][game->mtx.y] == 'W'
		|| game->mtx.map[game->mtx.x - 1][game->mtx.y] == 'A'
		|| game->mtx.map[game->mtx.x - 1][game->mtx.y] == 'S'
		|| game->mtx.map[game->mtx.x - 1][game->mtx.y] == 'D')
		return ;
	game->mtx.map[game->mtx.x - 1][game->mtx.y] = 'W';
	game->mtx.map[game->mtx.x][game->mtx.y] = '0';
}

void	en_down(t_game *game)
{
	if (game->mtx.map[game->mtx.x + 1][game->mtx.y] == '1'
		|| game->mtx.map[game->mtx.x + 1][game->mtx.y] == 'E'
		|| game->mtx.map[game->mtx.x + 1][game->mtx.y] == 'C'
		|| game->mtx.map[game->mtx.x + 1][game->mtx.y] == 'W'
		|| game->mtx.map[game->mtx.x + 1][game->mtx.y] == 'A'
		|| game->mtx.map[game->mtx.x + 1][game->mtx.y] == 'S'
		|| game->mtx.map[game->mtx.x + 1][game->mtx.y] == 'D')
		return ;
	game->mtx.map[game->mtx.x + 1][game->mtx.y] = 'S';
	game->mtx.map[game->mtx.x][game->mtx.y] = '0';
}

void	en_left(t_game *game)
{
	if (game->mtx.map[game->mtx.x][game->mtx.y - 1] == '1'
		|| game->mtx.map[game->mtx.x][game->mtx.y - 1] == 'E'
		|| game->mtx.map[game->mtx.x][game->mtx.y - 1] == 'C'
		|| game->mtx.map[game->mtx.x][game->mtx.y - 1] == 'W'
		|| game->mtx.map[game->mtx.x][game->mtx.y - 1] == 'A'
		|| game->mtx.map[game->mtx.x][game->mtx.y - 1] == 'S'
		|| game->mtx.map[game->mtx.x][game->mtx.y - 1] == 'D')
		return ;
	game->mtx.map[game->mtx.x][game->mtx.y - 1] = 'A';
	game->mtx.map[game->mtx.x][game->mtx.y] = '0';
}

void	en_right(t_game *game)
{
	if (game->mtx.map[game->mtx.x][game->mtx.y + 1] == '1'
		|| game->mtx.map[game->mtx.x][game->mtx.y + 1] == 'E'
		|| game->mtx.map[game->mtx.x][game->mtx.y + 1] == 'C'
		|| game->mtx.map[game->mtx.x][game->mtx.y + 1] == 'W'
		|| game->mtx.map[game->mtx.x][game->mtx.y + 1] == 'A'
		|| game->mtx.map[game->mtx.x][game->mtx.y + 1] == 'S'
		|| game->mtx.map[game->mtx.x][game->mtx.y + 1] == 'D')
		return ;
	game->mtx.map[game->mtx.x][game->mtx.y + 1] = 'D';
	game->mtx.map[game->mtx.x][game->mtx.y] = '0';
}
