/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:53:42 by cazerini          #+#    #+#             */
/*   Updated: 2025/02/23 16:08:04 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_victory(void)
{
	int		fd;
	char	*str;

	fd = open("./textures/Victory.txt", O_RDONLY);
	if (fd < 0)
	{
		ft_printf("an error has occurred while reading\n");
		close(fd);
		return ;
	}
	else if (fd == 0)
	{
		ft_printf("nothing to read\n");
		return ;
	}
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		ft_printf("%s", str);
		free(str);
	}
	close(fd);
	return ;
}

void	print_game_over(void)
{
	int		fd;
	char	*str;

	fd = open("./textures/Game_over.txt", O_RDONLY);
	if (fd < 0)
	{
		ft_printf("an error has occurred while reading\n");
		close(fd);
		return ;
	}
	else if (fd == 0)
	{
		ft_printf("nothing to read\n");
		return ;
	}
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		ft_printf("%s", str);
		free(str);
	}
	close(fd);
	return ;
}

int	check_cpe_count(t_game *game)
{
	if (game->mtx.p != 1 || game->mtx.count == 0 || game->mtx.e != 1
		|| game->mtx.o != 0)
		return (ft_printf("Wrong number of PCE \\ strange object found!\n"));
	return (0);
}

size_t	ft_strlcpy(char	*dst, char *src, size_t size)
{
	size_t	i;

	if (src == NULL)
	{
		if (size > 0)
			dst[0] = '\0';
		return (0);
	}
	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = ft_strlen(src, '\0');
	return (i);
}
