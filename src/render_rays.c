/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:36:50 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/20 22:50:20 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_all_rays(t_game *g)
{
	double	rayAngle;
	int		i;

	i = 0;
	rayAngle = g->player->rotate_angle - (FOV_ANGLE / 2);
	while (i < NUM_RAYS)
	{
		g->player->ray[i] = (t_ray *)malloc(sizeof(t_ray));
		g->player->ray[i]->angle = rayAngle;
		cast_ray(g, g->player->ray[i]);
		rayAngle += FOV_ANGLE / (NUM_RAYS);
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
		free(g->player->ray[i]);
		g->player->ray[i] = NULL;
		i++;
	}
}

void	render_all_rays(t_game *g)
{
	double		rayAngle;
	int			i;
	t_grid_dist	grid;

	i = 0;
	rayAngle = g->player->rotate_angle - (FOV_ANGLE / 2);
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
