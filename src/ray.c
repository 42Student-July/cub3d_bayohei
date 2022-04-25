/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:24:43 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/25 21:26:43 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_vert_step_and_intercept(t_game *g, t_ray *ray)
{
	ray->found_vert_wallhit = false;
	ray->vert_wall_hit_x = 0;
	ray->vert_wall_hit_y = 0;
	ray->xintercept = floor(g->player->x / TILE_SIZE) * TILE_SIZE;
	if (ray->is_ray_facing_right)
		ray->xintercept += TILE_SIZE;
	ray->yintercept = g->player->y + \
	(ray->xintercept - g->player->x) * tan(ray->angle);
	ray->xstep = TILE_SIZE;
	if (ray->is_ray_facing_left)
		ray->xstep *= -1;
	ray->ystep = TILE_SIZE * tan(ray->angle);
	if (ray->is_ray_facing_up && ray->ystep > 0)
		ray->ystep *= -1;
	if (ray->is_ray_facing_down && ray->ystep < 0)
		ray->ystep *= -1;
	ray->next_vert_touch_x = ray->xintercept;
	ray->next_vert_touch_y = ray->yintercept;
}

void	get_vert_wall_hit(t_game *g, t_ray *ray)
{
	double	x_to_check;
	double	y_to_check;

	get_vert_step_and_intercept(g, ray);
	while (ray->next_vert_touch_x >= 0 && ray->next_vert_touch_x <= g->d.col * TILE_SIZE \
	&& ray->next_vert_touch_y >= 0 && ray->next_vert_touch_y <= g->d.col * TILE_SIZE)
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
		else
		{
			ray->next_vert_touch_x += ray->xstep;
			ray->next_vert_touch_y += ray->ystep;
		}
	}
}

double	calc_distance_horz(t_game *g, t_ray *ray)
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;

	x1 = g->player->x;
	y1 = g->player->y;
	x2 = ray->horz_wall_hit_x;
	y2 = ray->horz_wall_hit_y;
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

double	calc_distance_vert(t_game *g, t_ray *ray)
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;

	x1 = g->player->x;
	y1 = g->player->y;
	x2 = ray->vert_wall_hit_x;
	y2 = ray->vert_wall_hit_y;
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	cast_ray(t_game *g, t_ray *ray)
{
	double	horz_hit_distance;
	double	vert_hit_distance;

	horz_hit_distance = DBL_MAX;
	vert_hit_distance = DBL_MAX;
	get_horz_wall_hit(g, ray);
	get_vert_wall_hit(g, ray);
	if (ray->found_horz_wallhit)
		horz_hit_distance = calc_distance_horz(g, ray);
	if (ray->found_vert_wallhit)
		vert_hit_distance = calc_distance_vert(g, ray);
	if (horz_hit_distance < vert_hit_distance)
	{
		ray->dist = horz_hit_distance;
		ray->found_vert_wallhit = false;
		ray->wall_hit_x = floor(ray->horz_wall_hit_x);
		ray->wall_hit_y = floor(ray->horz_wall_hit_y);
	}
	else
	{
		ray->dist = vert_hit_distance;
		ray->found_horz_wallhit = false;
		ray->wall_hit_x = floor(ray->vert_wall_hit_x);
		ray->wall_hit_y = floor(ray->vert_wall_hit_y);
	}
}
