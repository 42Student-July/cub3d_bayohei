/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:36:50 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/30 06:10:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_all_rays(t_game *g)
{
	double	ray_angle;
	int		i;

	i = 0;
	ray_angle = g->player->rotate_angle - (g->fov_angle / 2);
	while (i < NUM_RAYS)
	{
		g->player->ray[i]->angle = ray_angle;
		cast_ray(g, g->player->ray[i]);
		ray_angle += g->fov_angle / (NUM_RAYS);
		i++;
	}
}

void	clear_all_rays(t_game *g)
{
	int			i;
	t_grid_dist	grid;

	i = 0;
	while (i < NUM_RAYS)
	{
		grid.x1 = g->player->x;
		grid.y1 = g->player->y;
		grid.x2 = g->player->ray[i]->wall_hit_x;
		grid.y2 = g->player->ray[i]->wall_hit_y;
		render_line_with_color(
			g,
			grid,
			BLACK
			);
		i++;
	}
}

void	render_all_rays(t_game *g)
{
	int			i;
	t_grid_dist	grid;

	i = 0;
	while (i < NUM_RAYS)
	{
		grid.x1 = g->player->x;
		grid.y1 = g->player->y;
		grid.x2 = g->player->ray[i]->wall_hit_x;
		grid.y2 = g->player->ray[i]->wall_hit_y;
		render_line_with_color(
			g,
			grid,
			YELLOW
			);
		i++;
	}
}

void	render_vision(t_game *g)
{
	cast_all_rays(g);
	render_all_rays(g);
}
