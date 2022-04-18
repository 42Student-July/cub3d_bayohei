/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:16:00 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/18 16:58:39 by mhirabay         ###   ########.fr       */
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
		while (wall_top_pixel < wall_bottom_pixel)
		{
			g->img.data[to_coord(i, wall_top_pixel)] = YELLOW;
			wall_top_pixel++;
		}
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
		while (wall_top_pixel < wall_bottom_pixel)
		{
			g->img.data[to_coord(i, wall_top_pixel)] = BLACK;
			wall_top_pixel++;
		}
		i++;
	}
	clear_all_rays(g);
}

