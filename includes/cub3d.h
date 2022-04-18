/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:09:42 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/19 00:01:36 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <fcntl.h>
# include <float.h>

# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "error_msg.h"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT_ARROW 65361
# define KEY_RIGHT_ARROW 65363

# define YELLOW 0xFFFF00
# define BLACK 0x0
# define WHITE 0xFFFFFF

# define TILE_SIZE 32
# define PLAYER_SIZE 6
# define PLAYER_MOVE_PIXEL 1
# define PLAYER_LOOK_DEGREE 1

# define MINIMAP_SCALE 0.5
# define ROWS 11 
# define COLS 15
# define WIDTH COLS * TILE_SIZE
# define HEIGHT ROWS * TILE_SIZE
# define FOV_ANGLE (60 * (M_PI / 180))
# define NUM_RAYS WIDTH
# define TO_COORD(X, Y) ((int)floor(Y) * WIDTH + (int)floor(X))
# define FILE_PATH 1

typedef struct s_ray
{
	double	wall_hit_x;
	double	wall_hit_y;
	double	dist;
	double	angle;
	bool	is_ray_facing_down;
	bool	is_ray_facing_up;
	bool	is_ray_facing_right;
	bool	is_ray_facing_left;
	double	xintercept;
	double	yintercept;
	double	xstep;
	double	ystep;
	double	next_horz_touch_x;
	double	next_horz_touch_y;
	double	horz_wall_hit_x;
	double	horz_wall_hit_y;
	bool	found_horz_wallhit;
	double	next_vert_touch_x;
	double	next_vert_touch_y;
	double	vert_wall_hit_x;
	double	vert_wall_hit_y;
	bool	found_vert_wallhit;
}	t_ray;

typedef struct s_player
{
	int		x;
	int		y;
	int		x_draw_start;
	int		y_draw_start;
	int		x_draw_end;
	int		y_draw_end;
	int		fov_min;
	int		fov_max;
	double	rotate_angle;
	bool	*is_collide;
	t_ray	**ray;
}	t_player;

typedef struct s_config
{
	double	fov_angle;
	int		width;
	int		height;
}	t_config;

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
	t_config	*config;
	int		map[ROWS][COLS];
}	t_game;

void	move_north(t_game *game);
void	move_west(t_game *game);
void	move_east(t_game *game);
void	move_south(t_game *game);

void	init_player_coord(t_game *game);
void	render_line(t_game *game, double x1, double y1, double x2, double y2);
void	render_line_with_color(t_game *game, double x1, double y1, double x2, double y2, int color);
void	print_wall(t_game *g);
int		main_loop(t_game *game);

// init.c
void	init(t_game *game, char *filename);
void	init_map(t_game *game);
void	init_window(t_game *game);
void	init_img(t_game *game);
void	init_player(t_game *game);
void	init_player_coord(t_game *g);
void	read_cub_asset(t_game *game, char *filename);

// render.c
void	generate_3d(t_game *g);
void	clear_3d(t_game *g);
int		render(t_game *game);
void	render_minimap(t_game *game);
void	render_lines(t_game *game);
void	render_wall(t_game *game, int x, int y);
void	render_ground(t_game *game, int x, int y);
void	render_player(t_game *game);
void	render_all_rays(t_game *g);

// vision.c
void	reset_vision(t_game *g);
void	render_vision(t_game *g);
void	look_left(t_game *g);
void	look_right(t_game *g);
void	reset_all_rays(t_game *g);
void	clear_all_rays(t_game *g);
void	cast_all_rays(t_game *g);
void	cast_ray(t_game *g, t_ray *ray);

// cub_utils.c
int		to_coord_minimap(double x, double y);
int		to_coord(double x, double y);

// error_handling.c
void	exit_with_err_msg(char *msg);

// args_handling.c
bool	args_handling(int argc, char *argv[]);

// look.c
void	look_left(t_game *g);
void	look_right(t_game *g);

// hooks.c
void	set_hooks(t_game *game);


#endif
