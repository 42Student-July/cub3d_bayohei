/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:05:01 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/27 18:16:35 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_horz_wall_hit(t_game *g, t_ray *ray)
{
	double	x_to_check;
	double	y_to_check;
	double	col_max;
	double	row_max;

	col_max = g->d.col * TILE_SIZE;
	row_max = g->d.row * TILE_SIZE;
	get_horz_step_and_intercept(g, ray);
	while (ray->next_horz_touch_x >= 0 && ray->next_horz_touch_x <= col_max \
		&& ray->next_horz_touch_y >= 0 && ray->next_horz_touch_y <= row_max)
	{
		x_to_check = ray->next_horz_touch_x;
		y_to_check = ray->next_horz_touch_y;
		if (ray->is_ray_facing_up)
			y_to_check += -1;
		if (map_has_wall_at(g, x_to_check, y_to_check))
		{
			ray->horz_wall_hit_x = ray->next_horz_touch_x;
			ray->horz_wall_hit_y = ray->next_horz_touch_y;
			ray->found_horz_wallhit = true;
			break ;
		}
		ray->next_horz_touch_x += ray->xstep;
		ray->next_horz_touch_y += ray->ystep;
	}
}

void	get_vert_wall_hit(t_game *g, t_ray *ray)
{
	double	x_to_check;
	double	y_to_check;
	double	col_max;
	double	row_max;

	col_max = g->d.col * TILE_SIZE;
	row_max = g->d.row * TILE_SIZE;
	get_vert_step_and_intercept(g, ray);
	while (ray->next_vert_touch_x >= 0 && ray->next_vert_touch_x <= col_max \
	&& ray->next_vert_touch_y >= 0 && ray->next_vert_touch_y <= row_max)
	{
		x_to_check = ray->next_vert_touch_x;
		if (ray->is_ray_facing_left)
			x_to_check += -1;
		y_to_check = ray->next_vert_touch_y;
		if (map_has_wall_at(g, x_to_check, y_to_check))
		{
			ray->vert_wall_hit_x = ray->next_vert_touch_x;
			ray->vert_wall_hit_y = ray->next_vert_touch_y;
			ray->found_vert_wallhit = true;
			break ;
		}
		ray->next_vert_touch_x += ray->xstep;
		ray->next_vert_touch_y += ray->ystep;
	}
}
