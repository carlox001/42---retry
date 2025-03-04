/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:22:48 by cazerini          #+#    #+#             */
/*   Updated: 2025/02/23 13:09:00 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_len(long n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long		nb;

	nb = n;
	len = count_len(nb);
	str = (char *)ft_calloc(sizeof(char), (len + 1));
	if (str == NULL)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[len - 1] = (nb % 10) + 48;
		nb /= 10;
		len--;
	}
	return (str);
}

void	destroy_images(t_game *game)
{
	if (game->img.c)
		mlx_destroy_image(game->win.mlx, game->img.c);
	if (game->img.e)
		mlx_destroy_image(game->win.mlx, game->img.e);
	if (game->img.w)
		mlx_destroy_image(game->win.mlx, game->img.w);
	if (game->img.g)
		mlx_destroy_image(game->win.mlx, game->img.g);
	if (game->img.p_f)
		mlx_destroy_image(game->win.mlx, game->img.p_f);
	if (game->img.p_l)
		mlx_destroy_image(game->win.mlx, game->img.p_l);
	if (game->img.p_r)
		mlx_destroy_image(game->win.mlx, game->img.p_r);
	if (game->img.p_b)
		mlx_destroy_image(game->win.mlx, game->img.p_b);
	if (game->img.n_f)
		mlx_destroy_image(game->win.mlx, game->img.n_f);
	if (game->img.n_l)
		mlx_destroy_image(game->win.mlx, game->img.n_l);
	if (game->img.n_r)
		mlx_destroy_image(game->win.mlx, game->img.n_r);
	if (game->img.n_b)
		mlx_destroy_image(game->win.mlx, game->img.n_b);
}

int	create_img(t_game *game)
{
	game->img.flag = 1;
	game->img.len = 32;
	game->img.height = 32;
	if (create_img_pn(game) != 0)
		return (1);
	game->img.p_f = mlx_xpm_file_to_image(game->win.mlx, PF, &game->img.len, \
					&game->img.height);
	game->img.c = mlx_xpm_file_to_image(game->win.mlx, CL, &game->img.len, \
					&game->img.height);
	game->img.e = mlx_xpm_file_to_image(game->win.mlx, EX, &game->img.len, \
					&game->img.height);
	game->img.w = mlx_xpm_file_to_image(game->win.mlx, WA, &game->img.len, \
					&game->img.height);
	game->img.g = mlx_xpm_file_to_image(game->win.mlx, GR, &game->img.len, \
					&game->img.height);
	game->img.n_f = mlx_xpm_file_to_image(game->win.mlx, NF, &game->img.len, \
					&game->img.height);
	if (!game->img.p_f || !game->img.c || !game->img.e || !game->img.w
		|| !game->img.g)
	{
		ft_printf("Error uploading images, path not found\n");
		ft_close(game);
		return (1);
	}
	return (0);
}

int	put_img(char c, t_game *game)
{
	if (game->img.flag == 0)
	{
		if (create_img(game) != 0)
			return (1);
	}
	if (c == 'P')
		mlx_put_image_to_window(game->win.mlx, game->win.win, game->img.p_f, \
			game->mtx.y * 32, game->mtx.x * 32);
	else if (c == 'C')
		mlx_put_image_to_window(game->win.mlx, game->win.win, game->img.c, \
			game->mtx.y * 32, game->mtx.x * 32);
	else if (c == 'E')
		mlx_put_image_to_window(game->win.mlx, game->win.win, game->img.e, \
			game->mtx.y * 32, game->mtx.x * 32);
	else if (c == '0')
		mlx_put_image_to_window(game->win.mlx, game->win.win, game->img.g, \
			game->mtx.y * 32, game->mtx.x * 32);
	else if (c == '1')
		mlx_put_image_to_window(game->win.mlx, game->win.win, game->img.w, \
			game->mtx.y * 32, game->mtx.x * 32);
	else
		put_img_pn(c, game);
	return (0);
}
