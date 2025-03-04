/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:05:39 by cazerini          #+#    #+#             */
/*   Updated: 2025/02/23 16:04:48 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_map(t_game *game)
{
	game->mtx.x = 0;
	while (game->mtx.map[game->mtx.x])
	{
		game->mtx.y = 0;
		while (game->mtx.map[game->mtx.x][game->mtx.y] != '\n'
			&& game->mtx.map[game->mtx.x][game->mtx.y])
		{
			if (put_img(game->mtx.map[game->mtx.x][game->mtx.y], game) != 0)
			{
				return (1);
			}
			game->mtx.y++;
		}
		game->mtx.x++;
	}
	return (0);
}

int	ft_close(t_game *game)
{
	ft_printf("closing window...\n");
	free(game->win.str);
	free_mtx(game, game->mtx.map);
	destroy_images(game);
	mlx_destroy_window(game->win.mlx, game->win.win);
	mlx_destroy_display(game->win.mlx);
	free(game->win.mlx);
	exit(0);
	return (0);
}

char	*alloc_str(int moves, t_game *game)
{
	char	str[11];
	char	*res;

	ft_strlcpy(str, "n. mosse: ", 11);
	game->mtx.x = count_len(moves);
	res = (char *)ft_calloc(game->mtx.x + 1 + 11, sizeof(char));
	if (!res)
		return (NULL);
	game->mtx.x = 0;
	while (str[game->mtx.x])
	{
		res[game->mtx.x] = str[game->mtx.x];
		game->mtx.x++;
	}
	game->win.num = ft_itoa(game->win.moves);
	if (!game->win.num)
		return (NULL);
	game->mtx.y = 0;
	while (game->win.num[game->mtx.y])
	{
		res[game->mtx.x + game->mtx.y] = game->win.num[game->mtx.y];
		game->mtx.y++;
	}
	free(game->win.num);
	return (res);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		return (ft_close(game));
	if (keycode == 'w' || keycode == 65362)
		up(game);
	if (keycode == 's' || keycode == 65364)
		down(game);
	if (keycode == 'a' || keycode == 65361)
		left(game);
	if (keycode == 'd' || keycode == 65363)
		right(game);
	return (0);
}

int	win_management(t_game *game)
{
	game->img.flag = 0;
	game->win.moves = 0;
	game->win.str = NULL;
	game->mtx.c_count = 0;
	game->win.mlx = mlx_init();
	game->win.win = mlx_new_window(game->win.mlx, game->mtx.len * 32, \
	game->mtx.height * 32, "so_long");
	if (!game->win.win || !game->win.mlx)
		return (ft_printf("Unable to create the window!\n"));
	if (put_map(game) != 0)
		return (1);
	mlx_hook(game->win.win, 17, 1L << 2, ft_close, game);
	mlx_key_hook(game->win.win, key_press, game);
	mlx_loop_hook(game->win.mlx, refresh_map, game);
	mlx_loop(game->win.mlx);
	return (0);
}
