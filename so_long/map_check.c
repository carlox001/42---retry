/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:53:18 by cazerini          #+#    #+#             */
/*   Updated: 2025/01/23 14:28:57 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_mtx(t_game *game, char *file)
{
	int		fd;

	fd = open_file(file);
	if (!fd)
		return (1);
	game->mtx.x = 0;
	game->mtx.map[game->mtx.x] = get_next_line(fd);
	if (!(game->mtx.map[game->mtx.x]))
		return (ft_printf("map not found\n"));
	while (game->mtx.map[game->mtx.x])
	{
		game->mtx.x++;
		game->mtx.map[game->mtx.x] = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening the file\n");
		close(fd);
		return (0);
	}
	return (fd);
}

int	allocate_mtx(char *file, t_game *game)
{
	char	*buf;
	int		fd;

	fd = open_file(file);
	if (!fd)
		return (1);
	buf = get_next_line(fd);
	if (!buf)
		return (ft_printf("map not found\n"));
	game->mtx.len = ft_strlen(buf, '\n');
	game->mtx.height = 1;
	while (buf)
	{
		free(buf);
		buf = get_next_line(fd);
		game->mtx.height++;
	}
	close(fd);
	game->mtx.map = (char **)ft_calloc(sizeof(char *), (game->mtx.height));
	if (!game->mtx.map)
		return (ft_printf("map's allocation failed\n"));
	if (create_mtx(game, file) != 0)
		return (1);
	return (0);
}

int	check_reb(char *str)
{
	const char	ext[4] = "reb.";
	int			len;
	int			i;

	len = ft_strlen(str, '\0') - 1;
	i = 0;
	while (i < 4)
	{
		if (ext[i] != str[len - i])
			return (ft_printf("Invalid extension!\n"));
		i++;
	}
	return (0);
}

int	check_map(char *file, t_game *game)
{
	game->mtx.map = NULL;
	game->mtx.dup = NULL;
	game->mtx.count = 0;
	game->mtx.e = 0;
	game->mtx.p = 0;
	game->mtx.o = 0;
	if (check_reb(file) != 0)
		return (0);
	if (allocate_mtx(file, game) != 0)
		return (0);
	if (is_rectangle(game) != 0)
		return (0);
	if (check_walls(game) != 0)
		return (0);
	game->mtx.x = 0;
	if (cpe_count(game) != 0)
		return (0);
	if (mtx_dup(game) != 0)
		return (0);
	player_pos(game);
	flood_fill(game, game->mtx.x, game->mtx.y);
	if (final_check(game) != 0)
		return (0);
	free_mtx(game, game->mtx.dup);
	return (1);
}
