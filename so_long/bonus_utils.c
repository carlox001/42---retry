/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:26:00 by cazerini          #+#    #+#             */
/*   Updated: 2025/02/23 16:23:35 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lets_move(t_game *game)
{
	static clock_t	start = 0;
	clock_t			range;
	clock_t			time;

	if (start == 0)
		start = clock();
	range = 300;
	time = (clock() - start) * 1000 / CLOCKS_PER_SEC;
	if (time >= range && time)
	{
		enemies(game);
		if (player_pos(game))
		{
			print_game_over();
			ft_close(game);
			return ;
		}
		start = clock();
	}
}
