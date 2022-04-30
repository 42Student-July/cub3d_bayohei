/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:24:43 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/30 16:13:22 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

void	calc_dist(t_game *g, t_ray *ray, double *horz_dist, double *vert_dist)
{
	*horz_dist = DBL_MAX;
	*vert_dist = DBL_MAX;
	if (ray->found_horz_wallhit)
		*horz_dist = calc_distance_horz(g, ray);
	if (ray->found_vert_wallhit)
		*vert_dist = calc_distance_vert(g, ray);
}

void	cast_ray(t_game *g, t_ray *ray)
{
	double	horz_hit_distance;
	double	vert_hit_distance;

	init_ray_facing(ray, ray->angle);
	get_horz_wall_hit(g, ray);
	get_vert_wall_hit(g, ray);
	calc_dist(g, ray, &horz_hit_distance, &vert_hit_distance);
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
