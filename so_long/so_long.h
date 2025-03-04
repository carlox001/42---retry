/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cazerini <cazerini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:17:01 by cazerini          #+#    #+#             */
/*   Updated: 2025/02/23 16:21:05 by cazerini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line.h"
# include <time.h>

# define WA "./textures/wall.xpm"
# define GR "./textures/ground.xpm"
# define PF "./textures/front.xpm"
# define PL "./textures/left.xpm"
# define PR "./textures/right.xpm"
# define PB "./textures/back.xpm"
# define CL "./textures/rose.xpm"
# define EX "./textures/key.xpm"
# define NF "./textures/e_f_m.xpm"
# define NB "./textures/e_b_m.xpm"
# define NL "./textures/e_l_m.xpm"
# define NR "./textures/e_r_m.xpm"

typedef struct s_win
{
	void	*mlx;
	void	*win;
	int		moves;
	char	*str;
	char	*num;
}	t_win;

typedef struct s_imge
{
	void	*p_f;
	void	*p_b;
	void	*p_l;
	void	*p_r;
	void	*c;
	void	*e;
	void	*w;
	void	*g;
	void	*n_f;
	void	*n_b;
	void	*n_l;
	void	*n_r;
	int		len;
	int		height;
	int		flag;
}	t_imge;

typedef struct s_mtx
{
	int		len;
	int		height;
	int		x;
	int		y;
	int		p;
	int		c;
	int		e;
	int		o;
	char	**map;
	char	**dup;
	int		c_count;
	int		count;
}	t_mtx;

typedef struct s_game
{
	struct s_mtx	mtx;
	struct s_win	win;
	struct s_imge	img;
}	t_game;

int		check_map(char *file, t_game *game);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(char *str, char c);
int		check_reb(char *str);
int		open_file(char *file);
int		allocate_mtx(char *file, t_game *game);
int		create_mtx(t_game *game, char *file);
int		is_rectangle(t_game *game);
int		check_walls(t_game *game);
int		cpe_count(t_game *game);
int		check_cpe_count(t_game *game);
int		mtx_dup(t_game *game);
int		player_pos(t_game *game);
void	flood_fill(t_game *game, int x, int y);
int		final_check(t_game *game);
void	free_mtx(t_game	*game, char **mtx);

int		win_management(t_game *game);
int		key_press(int keycode, t_game *game);
int		ft_close(t_game *game);
int		put_map(t_game *game);
int		put_img(char c, t_game *game);
int		create_img(t_game *game);
void	destroy_images(t_game *game);
void	up(t_game *game);
void	down(t_game *game);
void	left(t_game *game);
void	right(t_game *game);
char	*alloc_str(int moves, t_game *game);
char	*ft_itoa(int n);
int		count_len(long n);
size_t	ft_strlcpy(char	*dst, char *src, size_t size);

void	print_game_over(void);
void	print_victory(void);
int		create_img_pn(t_game *game);
int		put_img_pn(char c, t_game *game);
int		put_str(t_game *game);
int		refresh_map(t_game *game);
void	enemies(t_game *game);
void	lets_move(t_game *game);
void	move_en(t_game *game);
void	en_up(t_game *game);
void	en_down(t_game *game);
void	en_left(t_game *game);
void	en_right(t_game *game);
int		lost(t_game *game, int x, int y);

#endif