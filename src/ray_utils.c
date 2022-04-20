/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:46:31 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/20 17:47:16 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	normalize_angle(double angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
	{
		angle = (2 * M_PI) + angle;
	}
	return (angle);
}

int	map_has_wall_at(t_game *g, double x, double y)
{
	int	map_grid_index_x;
	int	map_grid_index_y;

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return (true);
	map_grid_index_x = (int)floor(x / TILE_SIZE);
	map_grid_index_y = (int)floor(y / TILE_SIZE);
	if (g->map[map_grid_index_y][map_grid_index_x] == 1)
		return (true);
	return (false);
}

void	init_ray_facing(t_ray *ray, double ray_angle)
{
	ray->angle = normalize_angle(ray_angle);
	ray->is_ray_facing_down = ray->angle > 0 && ray->angle < M_PI;
	ray->is_ray_facing_up = !(ray->is_ray_facing_down);
	ray->is_ray_facing_right = ray->angle < 0.5 * M_PI \
	|| ray->angle > 1.5 * M_PI;
	ray->is_ray_facing_left = !(ray->is_ray_facing_right);
}

void	get_horz_step_and_intercept(t_game *g, t_ray *ray)
{
	ray->found_horz_wallhit = false;
	ray->yintercept = floor(g->player->y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_ray_facing_down)
		ray->yintercept += TILE_SIZE;
	ray->xintercept = g->player->x + \
	(ray->yintercept - g->player->y) / tan(ray->angle);
	ray->ystep = TILE_SIZE;
	if (ray->is_ray_facing_up)
		ray->ystep *= -1;
	ray->xstep = TILE_SIZE / tan(ray->angle);
	if (ray->is_ray_facing_left && ray->xstep > 0)
		ray->xstep *= -1;
	if (ray->is_ray_facing_right && ray->xstep < 0)
		ray->xstep *= -1;
	ray->next_horz_touch_x = ray->xintercept;
	ray->next_horz_touch_y = ray->yintercept;
	ray->horz_wall_hit_x = 0;
	ray->horz_wall_hit_y = 0;
}

void	get_horz_wall_hit(t_game *g, t_ray *ray)
{
	double	x_to_check;
	double	y_to_check;

	init_ray_facing(ray, ray->angle);
	get_horz_step_and_intercept(g, ray);
	while (ray->next_horz_touch_x >= 0 && ray->next_horz_touch_x <= WIDTH \
		&& ray->next_horz_touch_y >= 0 && ray->next_horz_touch_y <= HEIGHT)
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
		else
		{
			ray->next_horz_touch_x += ray->xstep;
			ray->next_horz_touch_y += ray->ystep;
		}
	}
}
