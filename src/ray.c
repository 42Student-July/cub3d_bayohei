/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:24:43 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/18 17:24:03 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	find_horizontal_intersection(t_game *g, int ray_angle)
{
	// まず最初の衝突座標Aを取得する。
	int	ax;
	int	ay;
	int	xstep;
	int	ystep;

	ay = floor((g->player->y / TILE_SIZE)) * TILE_SIZE;
	ax = g->player->x + ((g->player->y - ay) / tan(ray_angle));
	// ray_angleにはdegreeではなくradを入れる
	xstep = TILE_SIZE / tan(ray_angle);
	ystep = TILE_SIZE;
}

double	normalize_angle(double angle)
{
	if (angle < 0)
	{
		// 負の数だった場合一周させる
		angle = (2 * M_PI) + angle;
	}
	return (angle);
}

int map_has_wall_at(t_game *g, double x, double y) {
	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT) {
		return true;
	}
	int mapGridIndexX = (int)floor(x / TILE_SIZE);
	int mapGridIndexY = (int)floor(y / TILE_SIZE);
	if (g->map[mapGridIndexY][mapGridIndexX] == 1)
	{
		return true;
	}
	return false;
}

double distance_between_points(float x1, float y1, float x2, float y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void	cast_ray(t_game *g, t_ray *ray)
{
	double rayAngle = normalize_angle(ray->angle);

	int isRayFacingDown = rayAngle > 0 && rayAngle < M_PI;
	int	isRayFacingUp = !isRayFacingDown;
	
	int	isRayFacingRight = rayAngle < 0.5 * M_PI || rayAngle > 1.5 * M_PI;
	int isRayFacingLeft = !isRayFacingRight;
	
	double xintercept, yintercept;
	double xstep, ystep;

	int foundHorzWallHit = false;
	double horzWallHitX = 0;
	double horzWallHitY = 0;
	int	horzWallContent = 0;
	
	yintercept = floor(g->player->y / TILE_SIZE) * TILE_SIZE;
	// rayが下方向を向いている場合、接点は+TILE_SIZE分になる
	yintercept += isRayFacingDown ? TILE_SIZE : 0;

	xintercept = g->player->x + (yintercept - g->player->y) / tan(rayAngle);
	ystep = TILE_SIZE;
	ystep *= isRayFacingUp ? -1 : 1;

	xstep = TILE_SIZE / tan(rayAngle);
	xstep *= (isRayFacingLeft && xstep > 0) ? -1 : 1;
	xstep *= (isRayFacingRight && xstep < 0) ? -1 : 1;
	double nextHorzTouchX = xintercept;
	double nextHorzTouchY = yintercept;
	
	// Increment xstep and ystep until we find a wall
	while (nextHorzTouchX >= 0 && nextHorzTouchX <= WIDTH && nextHorzTouchY >= 0 && nextHorzTouchY <= HEIGHT) {
		double xToCheck = nextHorzTouchX;
		double yToCheck = nextHorzTouchY + (isRayFacingUp ? -1 : 0);
		
		if (map_has_wall_at(g, xToCheck, yToCheck)) {
			// found a wall hit
			horzWallHitX = nextHorzTouchX;
			horzWallHitY = nextHorzTouchY;
			horzWallContent = g->map[(int)floor(yToCheck / TILE_SIZE)][(int)floor(xToCheck / TILE_SIZE)];
			foundHorzWallHit = true;
			break;
		} else {
			nextHorzTouchX += xstep;
			nextHorzTouchY += ystep;
		}
	}
	///////////////////////////////////////////
	// VERTICAL RAY-GRID INTERSECTION CODE
	///////////////////////////////////////////
	int foundVertWallHit = false;
	double vertWallHitX = 0;
	double vertWallHitY = 0;
	int vertWallContent = 0;

	// Find the x-coordinate of the closest horizontal grid intersection
	xintercept = floor(g->player->x / TILE_SIZE) * TILE_SIZE;
	xintercept += isRayFacingRight ? TILE_SIZE : 0;

	// Find the y-coordinate of the closest horizontal grid intersection
	yintercept = g->player->y + (xintercept - g->player->x) * tan(rayAngle);

	// Calculate the increment xstep and ystep
	xstep = TILE_SIZE;
	xstep *= isRayFacingLeft ? -1 : 1;

	ystep = TILE_SIZE * tan(rayAngle);
	ystep *= (isRayFacingUp && ystep > 0) ? -1 : 1;
	ystep *= (isRayFacingDown && ystep < 0) ? -1 : 1;

	double nextVertTouchX = xintercept;
	double nextVertTouchY = yintercept;

	// Increment xstep and ystep until we find a wall
	while (nextVertTouchX >= 0 && nextVertTouchX <= WIDTH && nextVertTouchY >= 0 && nextVertTouchY <= HEIGHT) {
		double xToCheck = nextVertTouchX + (isRayFacingLeft ? -1 : 0);
		double yToCheck = nextVertTouchY;
		
		if (map_has_wall_at(g, xToCheck, yToCheck)) {
			// found a wall hit
			vertWallHitX = nextVertTouchX;
			vertWallHitY = nextVertTouchY;
			vertWallContent = g->map[(int)floor(yToCheck / TILE_SIZE)][(int)floor(xToCheck / TILE_SIZE)];
			foundVertWallHit = true;
			break;
		} else {
			nextVertTouchX += xstep;
			nextVertTouchY += ystep;
		}
	}
	double horzHitDistance = foundHorzWallHit
		? distance_between_points(g->player->x, g->player->y, horzWallHitX, horzWallHitY)
		: FLT_MAX;
	float vertHitDistance = foundVertWallHit
		? distance_between_points(g->player->x, g->player->y, vertWallHitX, vertWallHitY)
		: FLT_MAX;
	if (horzHitDistance < vertHitDistance)
	{
		ray->dist = horzHitDistance;
		ray->wall_hit_x = floor(horzWallHitX);
		ray->wall_hit_y = floor(horzWallHitY);
	}
	else
	{
		ray->dist = vertHitDistance;
		ray->wall_hit_x = floor(vertWallHitX);
		ray->wall_hit_y = floor(vertWallHitY);
	}
}
