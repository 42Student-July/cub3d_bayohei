/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:16:00 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/18 10:15:14 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	generate_3d(t_game *g)
{
	int		i;
	double	perp_dist;
	double	dist_project_plane;
	double	projected_wall_height;
	// int		wall_strip_height;
	int		wall_top_pixel;
	int		wall_bottom_pixel;
	i = 0;
	dist_project_plane = ((WIDTH) / 2) / tan(FOV_ANGLE / 2);
	while (i < NUM_RAYS)
	{
		perp_dist = g->player->ray[i]->dist * cos(g->player->ray[i]->angle - g->player->rotate_angle);
		projected_wall_height = ((TILE_SIZE) / perp_dist) * dist_project_plane;
		// 描画位置特定 真ん中からprojectedのwallの半分を引いたやつ
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
	// int		wall_strip_height;
	int		wall_top_pixel;
	int		wall_bottom_pixel;
	i = 0;
	dist_project_plane = ((WIDTH) / 2) / tan(FOV_ANGLE / 2);
	while (i < NUM_RAYS)
	{
		perp_dist = g->player->ray[i]->dist * cos(g->player->ray[i]->angle - g->player->rotate_angle);
		projected_wall_height = ((TILE_SIZE) / perp_dist) * dist_project_plane;
		// 描画位置特定 真ん中からprojectedのwallの半分を引いたやつ
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
	clear_vision(g);
}
