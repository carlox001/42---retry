/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:38:02 by cazerini          #+#    #+#             */
/*   Updated: 2025/01/23 14:54:50 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_mtx(t_game	*game, char **mtx)
{
	if (mtx)
	{
		game->mtx.x = 0;
		while (mtx[game->mtx.x])
		{
			free(mtx[game->mtx.x]);
			game->mtx.x++;
		}
	}
	free(mtx);
}

int	final_check(t_game *game)
{
	game->mtx.c = 0;
	game->mtx.e = 0;
	game->mtx.p = 0;
	game->mtx.x = 0;
	while (game->mtx.dup[game->mtx.x] != NULL)
	{
		game->mtx.y = 0;
		while (game->mtx.dup[game->mtx.x][game->mtx.y] != '\n'
				&& game->mtx.dup[game->mtx.x][game->mtx.y] != '\0')
		{
			if (game->mtx.dup[game->mtx.x][game->mtx.y] == 'C')
				game->mtx.c++;
			if (game->mtx.dup[game->mtx.x][game->mtx.y] == 'P')
				game->mtx.p++;
			game->mtx.y++;
		}
		game->mtx.x++;
	}
	if (game->mtx.p != 0 || game->mtx.c != 0)
		return (ft_printf("Do you want to get stuck in a game loop?!\n"));
	return (0);
}

int	mtx_dup(t_game *game)
{
	int	x;

	game->mtx.dup = (char **)ft_calloc(sizeof(char *), game->mtx.height);
	if (!game->mtx.dup)
		return (ft_printf("dup's rows' allocation failed\n"));
	x = 0;
	while (game->mtx.map[x])
	{
		game->mtx.dup[x] = (char *)ft_calloc(sizeof(char), game->mtx.len + 1);
		if (!game->mtx.dup[x])
			return (ft_printf("dup's cols'allocation failed\n"));
		game->mtx.y = 0;
		while (game->mtx.map[x][game->mtx.y] != '\0'
			&& game->mtx.map[x][game->mtx.y] != '\n')
		{
			game->mtx.dup[x][game->mtx.y] = game->mtx.map[x][game->mtx.y];
			game->mtx.y++;
		}
		x++;
	}
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;
	char	*str;

	ptr = (void *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	str = ptr;
	i = 0;
	while (i < (nmemb * size))
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

size_t	ft_strlen(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
			i++;
		else
			break ;
	}
	return (i);
}
