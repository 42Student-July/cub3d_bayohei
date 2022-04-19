/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:16:00 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/19 17:33:44 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_lines(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < COLS)
	{
		render_line(game, i * TILE_SIZE, 0, i * TILE_SIZE, HEIGHT);
		i++;
	}
	render_line(game, COLS * TILE_SIZE - 1, 0, COLS * TILE_SIZE - 1, HEIGHT);
	j = 0;
	while (j < ROWS)
	{
		render_line(game, 0, j * TILE_SIZE, WIDTH, j * TILE_SIZE);
		j++;
	}
	render_line(game, 0, ROWS * TILE_SIZE - 1, WIDTH, ROWS * TILE_SIZE - 1);
}

void	render_celling(t_game *g, int x, int wall_top_pixel)
{
	int	i;

	i = 0;
	while (i < wall_top_pixel)
	{
		g->img.data[to_coord(x, i)] = g->celling_color;
		i++;
	}
}

void	render_floor(t_game *g, int x, int wall_bottom_pixel)
{
	while (wall_bottom_pixel < HEIGHT)
	{
		g->img.data[to_coord(x, wall_bottom_pixel)] = g->floor_color;
		wall_bottom_pixel++;
	}
}

void	clear_celling(t_game *g, int x, int wall_top_pixel)
{
	int	i;

	i = 0;
	while (i < wall_top_pixel)
	{
		g->img.data[to_coord(x, i)] = BLACK;
		i++;
	}
}

void	clear_floor(t_game *g, int x, int wall_bottom_pixel)
{
	while (wall_bottom_pixel < HEIGHT)
	{
		g->img.data[to_coord(x, wall_bottom_pixel)] = BLACK;
		wall_bottom_pixel++;
	}
}

int	get_tex_type(t_ray *ray)
{
	if (ray->found_vert_wallhit)
	{
		if (ray->is_ray_facing_left)
			return (EA);
		else
			return (WE);
	}
	else
	{
		if (ray->is_ray_facing_up)
			return (SO);
		else
			return (NO);
	}
}

int	get_tex_color(t_game *g, int tex_type, int x, int y)
{
	// return (YELLOW);
	if (tex_type == NO)
	{
		return (g->texture.no_img.data[to_coord_tex(x, y)]);
	}
	else if (tex_type == SO)
	{
		return (g->texture.so_img.data[to_coord_tex(x, y)]);
	}
	else if (tex_type == EA)
	{
		return (g->texture.ea_img.data[to_coord_tex(x, y)]);
	}
	else if (tex_type == WE)
	{
		return (g->texture.we_img.data[to_coord_tex(x, y)]);
	}
	return (YELLOW);
	// return (BLACK);
}


void	render_3dwall(t_game *g, int i, int wall_top_pixel, int wall_bottom_pixel, int projected_wall_height)
{
	int	tex_type;
	int	texture_offset_x;
	int	texture_offset_y;
	int	y;
	int	color;

	tex_type = get_tex_type(g->player->ray[i]);
	if (tex_type == NO)
	{
		texture_offset_x = ((int)g->player->ray[i]->horz_wall_hit_x) % TILE_SIZE * (TEXTURE_WIDTH / (double)TILE_SIZE);
	}
	else if (tex_type == SO)
	{
		texture_offset_x = ((int)g->player->ray[i]->horz_wall_hit_x) % TILE_SIZE * (TEXTURE_WIDTH / (double)TILE_SIZE);
	}
	else if (tex_type == EA)
	{
		texture_offset_x = ((int)g->player->ray[i]->vert_wall_hit_y) % TILE_SIZE * (TEXTURE_WIDTH / (double)TILE_SIZE);
	}
	else if (tex_type == WE)
	{
		texture_offset_x = ((int)g->player->ray[i]->vert_wall_hit_y % TILE_SIZE) * (TEXTURE_WIDTH / (double)TILE_SIZE);
	}
	y = wall_top_pixel;
	while (y < wall_bottom_pixel)
	{
		// (void)projected_wall_height;
		// texture_offset_y = (y - wall_top_pixel);
		texture_offset_y = (y - wall_top_pixel) * (50 / (double)projected_wall_height);
		color = get_tex_color(g, tex_type, texture_offset_x, texture_offset_y);
		g->img.data[to_coord(i, y)] = color;
		y++;
	}
}


void	generate_3d(t_game *g)
{
	int		i;
	double	perp_dist;
	double	dist_project_plane;
	double	projected_wall_height;
	int		wall_top_pixel;
	int		wall_bottom_pixel;

	i = 0;
	dist_project_plane = ((WIDTH) / 2) / tan(FOV_ANGLE / 2);
	while (i < NUM_RAYS)
	{
		perp_dist = g->player->ray[i]->dist * cos(g->player->ray[i]->angle - g->player->rotate_angle);
		projected_wall_height = ((TILE_SIZE) / perp_dist) * dist_project_plane;
		wall_top_pixel = (HEIGHT / 2) - (projected_wall_height / 2);
		if (wall_top_pixel < 0)
			wall_top_pixel = 0;
		wall_bottom_pixel = (HEIGHT / 2) + (projected_wall_height / 2);
		if (wall_bottom_pixel > HEIGHT)
			wall_bottom_pixel = HEIGHT;
		render_celling(g, i, wall_top_pixel);
		render_3dwall(g, i, wall_top_pixel, wall_bottom_pixel, projected_wall_height);
		render_floor(g, i, wall_bottom_pixel);
		i++;
	}
}

void	clear_3d(t_game *g)
{
	int		i;
	double	perp_dist;
	double	dist_project_plane;
	double	projected_wall_height;
	int		wall_top_pixel;
	int		wall_bottom_pixel;

	i = 0;
	dist_project_plane = ((WIDTH) / 2) / tan(FOV_ANGLE / 2);
	while (i < NUM_RAYS)
	{
		perp_dist = g->player->ray[i]->dist * cos(g->player->ray[i]->angle - g->player->rotate_angle);
		projected_wall_height = ((TILE_SIZE) / perp_dist) * dist_project_plane;
		wall_top_pixel = (HEIGHT / 2) - (projected_wall_height / 2);
		if (wall_top_pixel < 0)
			wall_top_pixel = 0;
		wall_bottom_pixel = (HEIGHT / 2) + (projected_wall_height / 2);
		if (wall_bottom_pixel > HEIGHT)
			wall_bottom_pixel = HEIGHT;
		clear_celling(g, i, wall_top_pixel);
		while (wall_top_pixel < wall_bottom_pixel)
		{
			g->img.data[to_coord(i, wall_top_pixel)] = BLACK;
			wall_top_pixel++;
		}
		clear_floor(g, i, wall_top_pixel);
		i++;
	}
	clear_all_rays(g);
}

