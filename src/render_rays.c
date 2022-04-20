/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:36:50 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/20 18:15:22 by mhirabay         ###   ########.fr       */
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
	int		i;
	double	delta_x;
	double	delta_y;

	i = 0;
	delta_x = g->player->ray[i]->wall_hit_x - g->player->x;
	delta_y = g->player->ray[i]->wall_hit_y - g->player->y;
	while (i < NUM_RAYS)
	{
		render_line_with_color_1(
			g,
			g->player->x,
			g->player->y,
			g->player->ray[i]->wall_hit_x,
			g->player->ray[i]->wall_hit_y,
			YELLOW
		);
		free(g->player->ray[i]);
		g->player->ray[i] = NULL;
		i++;
	}
}

void	render_all_rays(t_game *g)
{
	double	rayAngle;
	int		i;
	double	delta_x;
	double	delta_y;

	i = 0;
	rayAngle = g->player->rotate_angle - (FOV_ANGLE / 2);
	delta_x = g->player->ray[i]->wall_hit_x - g->player->x;
	delta_y = g->player->ray[i]->wall_hit_y - g->player->y;
	while (i < NUM_RAYS)
	{
		render_line_with_color_1(
			g,
			g->player->x,
			g->player->y,
			g->player->ray[i]->wall_hit_x,
			g->player->ray[i]->wall_hit_y,
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
