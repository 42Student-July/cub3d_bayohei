/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:09:42 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/30 17:01:54 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>

# include "../lib/mlx/mlx.h"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define TILE_SIZE 32
# define PLAYER_SIZE 6
# define PLAYER_MOVE_PIXEL 1

# define ROWS 11
# define COLS 15
# define WIDTH COLS * TILE_SIZE
# define HEIGHT ROWS * TILE_SIZE

# define TO_COORD(X, Y) ((int)floor(Y) * WIDTH + (int)floor(X))

typedef struct s_player
{
	int	x;
	int	y;
	int	x_draw_point;
	int	y_draw_point;
	int	x_draw_end;
	int	y_draw_end;
	int	x_center;
	int	y_center;
}	t_player;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_player	*player;
	int		map[ROWS][COLS];
}	t_game;

void	move_forward(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_back(t_game *game);
void	draw_player(t_game *game);
void	find_player_coord(t_game *game);
void	reset_vision(t_game *g);
void	draw_vision(t_game *g);
int		to_coord(double x, double y);

#endif
