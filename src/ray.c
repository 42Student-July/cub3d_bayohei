/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:24:43 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/19 16:27:06 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

double	normalize_angle(double angle)
{
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

double	distance_between_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	init_ray_facing(t_ray *ray, double ray_angle)
{
	ray->angle = normalize_angle(ray->angle);
	ray->is_ray_facing_down = ray_angle > 0 && ray_angle < M_PI;
	ray->is_ray_facing_up = !(ray->is_ray_facing_down);
	ray->is_ray_facing_right = ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI;
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
	while (ray->next_vert_touch_x >= 0 && ray->next_vert_touch_x <= WIDTH \
	&& ray->next_vert_touch_y >= 0 && ray->next_vert_touch_y <= HEIGHT)
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

void	cast_ray(t_game *g, t_ray *ray)
{
	double	horz_hit_distance;
	double	vert_hit_distance;

	horz_hit_distance = DBL_MAX;
	vert_hit_distance = DBL_MAX;
	get_horz_wall_hit(g, ray);
	get_vert_wall_hit(g, ray);
	if (ray->found_horz_wallhit)
		horz_hit_distance = distance_between_points(\
		g->player->x, g->player->y, ray->horz_wall_hit_x, ray->horz_wall_hit_y);
	if (ray->found_vert_wallhit)
		vert_hit_distance = distance_between_points(\
		g->player->x, g->player->y, ray->vert_wall_hit_x, ray->vert_wall_hit_y);
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
