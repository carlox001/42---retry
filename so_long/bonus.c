/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:46:37 by cazerini          #+#    #+#             */
/*   Updated: 2025/02/23 16:20:53 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_img_pn(t_game *game)
{
	game->img.p_l = mlx_xpm_file_to_image(game->win.mlx, PL, &game->img.len, \
					&game->img.height);
	game->img.p_r = mlx_xpm_file_to_image(game->win.mlx, PR, &game->img.len, \
					&game->img.height);
	game->img.p_b = mlx_xpm_file_to_image(game->win.mlx, PB, &game->img.len, \
					&game->img.height);
	game->img.n_l = mlx_xpm_file_to_image(game->win.mlx, NL, &game->img.len, \
					&game->img.height);
	game->img.n_r = mlx_xpm_file_to_image(game->win.mlx, NR, &game->img.len, \
					&game->img.height);
	game->img.n_b = mlx_xpm_file_to_image(game->win.mlx, NB, &game->img.len, \
					&game->img.height);
	if (!game->img.p_l || !game->img.p_r || !game->img.p_b || !game->img.n_b
		|| !game->img.n_l || !game->img.n_r)
	{
		ft_printf("Error uploading images, path not found\n");
		ft_close(game);
		return (1);
	}
	return (0);
}

int	put_img_pn(char c, t_game *game)
{
	if (c == 'B')
		mlx_put_image_to_window(game->win.mlx, game->win.win, game->img.p_b, \
			game->mtx.y * 32, game->mtx.x * 32);
	else if (c == 'L')
		mlx_put_image_to_window(game->win.mlx, game->win.win, game->img.p_l, \
			game->mtx.y * 32, game->mtx.x * 32);
	else if (c == 'R')
		mlx_put_image_to_window(game->win.mlx, game->win.win, game->img.p_r, \
			game->mtx.y * 32, game->mtx.x * 32);
	else if (c == 'S')
		mlx_put_image_to_window(game->win.mlx, game->win.win, game->img.n_f, \
			game->mtx.y * 32, game->mtx.x * 32);
	else if (c == 'W')
		mlx_put_image_to_window(game->win.mlx, game->win.win, game->img.n_b, \
			game->mtx.y * 32, game->mtx.x * 32);
	else if (c == 'A')
		mlx_put_image_to_window(game->win.mlx, game->win.win, game->img.n_r, \
			game->mtx.y * 32, game->mtx.x * 32);
	else if (c == 'D')
		mlx_put_image_to_window(game->win.mlx, game->win.win, game->img.n_l, \
			game->mtx.y * 32, game->mtx.x * 32);
	return (0);
}

int	put_str(t_game *game)
{
	if (game->win.str)
		mlx_string_put(game->win.mlx, game->win.win, \
			15, game->mtx.height * 31, 0x000000, game->win.str);
	free(game->win.str);
	game->win.str = alloc_str(game->win.moves, game);
	if (game->win.str == NULL)
		return (1);
	mlx_string_put(game->win.mlx, game->win.win, 15, \
		game->mtx.height * 31, 0x03fc66, game->win.str);
	return (0);
}

void	enemies(t_game *game)
{
	game->mtx.dup = game->mtx.map;
	game->mtx.x = 0;
	while (game->mtx.map[game->mtx.x])
	{
		game->mtx.y = 0;
		while (game->mtx.map[game->mtx.x][game->mtx.y] != '\0'
				&& game->mtx.map[game->mtx.x][game->mtx.y] != '\n')
		{
			if (game->mtx.map[game->mtx.x][game->mtx.y] == 'S'
			|| game->mtx.map[game->mtx.x][game->mtx.y] == 'W'
			|| game->mtx.map[game->mtx.x][game->mtx.y] == 'A'
			|| game->mtx.map[game->mtx.x][game->mtx.y] == 'D')
			{
				if (game->mtx.dup[game->mtx.x][game->mtx.y] == 'S'
					|| game->mtx.dup[game->mtx.x][game->mtx.y] == 'W'
					|| game->mtx.dup[game->mtx.x][game->mtx.y] == 'A'
					|| game->mtx.dup[game->mtx.x][game->mtx.y] == 'D')
					move_en(game);
			}
			game->mtx.y++;
		}
		game->mtx.x++;
	}
}

int	refresh_map(t_game *game)
{
	static clock_t	start = 0;
	clock_t			range;
	clock_t			time;

	if (start == 0)
		start = clock();
	range = 75;
	time = (clock() - start) * 1000 / CLOCKS_PER_SEC;
	if (time >= range)
	{
		mlx_clear_window(game->win.mlx, game->win.win);
		if (put_map(game) != 0)
			return (1);
		if (put_str(game) != 0)
			return (1);
		lets_move(game);
		start = clock();
	}
	return (0);
}
