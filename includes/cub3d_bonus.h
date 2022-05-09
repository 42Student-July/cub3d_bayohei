/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:09:42 by mhirabay          #+#    #+#             */
/*   Updated: 2022/05/09 14:16:06 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <fcntl.h>
# include <float.h>
# include "parser_bonus.h"
# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "error_msg_bonus.h"
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
# define GREEN 0x007F33
# define SKY_BLUE 0x66CCFF

# define TILE_SIZE 32
# define PLAYER_SIZE 6
# define PLAYER_MOVE_PIXEL 5
# define PLAYER_LOOK_DEGREE 1
# define TEXTURE_HEIGHT 50
# define TEXTURE_WIDTH 50

# define NO 2
# define SO 3
# define WE 4
# define EA 5

# define MINIMAP_SCALE 0.2
# define ROWS 11 
# define COLS 15
# define WIDTH 480
# define HEIGHT 352
# define ANGLE 60
# define NUM_RAYS WIDTH
# define FILE_PATH 1

# define NO_PATH "./asset/texture/NO.xpm"
# define SO_PATH "./asset/texture/SO.xpm"
# define EA_PATH "./asset/texture/EA.xpm"
# define WE_PATH "./asset/texture/WE.xpm"

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
	int		direction;
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

typedef struct s_texture
{
	t_img	no_img;
	t_img	so_img;
	t_img	we_img;
	t_img	ea_img;
}	t_texture;

typedef struct s_wall3d_info
{
	int		wall_top_pixel;
	int		wall_bottom_pixel;
	double	projected_wall_height;
}	t_wall3d_info;

typedef struct s_grid_dist
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
}	t_grid_dist;

typedef struct s_game
{
	double		fov_angle;
	void		*mlx;
	void		*win;
	t_img		img;
	t_player	*player;
	t_config	*config;
	t_texture	texture;
	int			floor_color;
	int			celling_color;
	int			**map;
	t_data		d;
}	t_game;

// move.c
void	move_forward(t_game *g);
void	move_right(t_game *g);
void	move_left(t_game *g);
void	move_back(t_game *g);
void	update_grid(t_game *g, int x, int y);
bool	check_left_player_line(t_game *g, int i, int j);
bool	check_right_player_line(t_game *g, int i, int j);
bool	check_top_player_line(t_game *g, int i, int j);
bool	check_bottom_player_line(t_game *g, int i, int j);

// move_direction.c
void	move_north(t_game *game);
void	move_west(t_game *game);
void	move_east(t_game *game);
void	move_south(t_game *game);

void	init_player_coord(t_game *game);
void	render_line_with_color(t_game *g, t_grid_dist grid, int color);
void	print_wall(t_game *g);
int		main_loop(t_game *game);

// init.c
void	init(t_game *game);
void	init_map(t_game *game);
void	init_window(t_game *game);
void	init_img(t_game *game);
void	init_player(t_game *game);
void	init_player_coord(t_game *g);
void	read_cub_asset(t_game *game);

// init_2.c
void	init_color(t_game *game);

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
void	render_horizontal(t_game *game);
void	render_vertical(t_game *game);

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
int		to_coord_tex(double x, double y);
double	normalize_angle(double angle);

// error_handling.c
void	exit_with_err_msg(char *msg);

// args_handling.c
bool	args_handling(int argc, char *argv[]);

// look.c
void	look_left(t_game *g);
void	look_right(t_game *g);

// hooks.c
void	set_hooks(t_game *game);

// render_3d_utils.c
void	render_lines(t_game *game);
void	render_celling(t_game *g, int x, int wall_top_pixel);
void	render_floor(t_game *g, int x, int wall_bottom_pixel);
void	clear_celling(t_game *g, int x, int wall_top_pixel);
void	clear_floor(t_game *g, int x, int wall_bottom_pixel);
void	calc_wall_info(t_ray *ray, double p_angle, t_wall3d_info *wall_info);

// render_3d_utils_2.c
void	clear_3d(t_game *g);
int		calc_offset_x(int wall_hit);

// ray_utils.c
double	normalize_angle(double angle);
int		map_has_wall_at(t_game *g, double x, double y);
void	init_ray_facing(t_ray *ray, double ray_angle);
void	get_horz_step_and_intercept(t_game *g, t_ray *ray);
void	get_horz_wall_hit(t_game *g, t_ray *ray);
void	get_vert_wall_hit(t_game *g, t_ray *ray);
void	get_horz_step_and_intercept(t_game *g, t_ray *ray);
void	get_vert_step_and_intercept(t_game *g, t_ray *ray);
int		*get_data_addr(t_img *i);

#endif
