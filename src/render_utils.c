/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:33:46 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/20 18:14:05 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_line(t_game *game, double x1, double y1, double x2, double y2)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	if (fabs(deltaX) > fabs(deltaY))
		step = fabs(deltaX);
	else
		step = fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		game->img.data[to_coord_minimap(x1, y1)] = 0xB3B3B3;
		x1 += deltaX;
		y1 += deltaY;
	}
}

void	render_line_with_color(\
	t_game *g, double delta_x, double delta_y, int color)
{
	double	step;
	double	x1;
	double	y1;

	x1 = g->player->x;
	y1 = g->player->y;
	if (fabs(delta_x) > fabs(delta_y))
		step = fabs(delta_x);
	else
		step = fabs(delta_y);
	delta_x /= step;
	delta_y /= step;
	while (fabs(delta_x) > 0.01 || fabs(delta_y) > 0.01)
	{
		g->img.data[to_coord_minimap(g->player->x, g->player->y)] = color;
		x1 += delta_x;
		y1 += delta_y;
	}
}

void	render_line_with_color_1(t_game *game, double x1, double y1, double x2, double y2, int color)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	if (fabs(deltaX) > fabs(deltaY))
		step = fabs(deltaX);
	else
		step = fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		game->img.data[to_coord_minimap(x1, y1)] = color;
		x1 += deltaX;
		y1 += deltaY;
	}
}
