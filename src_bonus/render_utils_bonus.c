/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:33:46 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/30 16:13:22 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	render_line(t_game *game, t_grid_dist g)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = g.x2 - g.x1;
	deltaY = g.y2 - g.y1;
	if (fabs(deltaX) > fabs(deltaY))
		step = fabs(deltaX);
	else
		step = fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(g.x2 - g.x1) > 0.01 || fabs(g.y2 - g.y1) > 0.01)
	{
		game->img.data[to_coord_minimap(g.x1, g.y1)] = 0xB3B3B3;
		g.x1 += deltaX;
		g.y1 += deltaY;
	}
}

void	render_horizontal(t_game *game)
{
	int			i;
	t_grid_dist	g;

	i = 0;
	while (i < COLS)
	{
		g.x1 = i * TILE_SIZE;
		g.y1 = 0;
		g.x2 = i * TILE_SIZE;
		g.y2 = HEIGHT;
		render_line(game, g);
		i++;
	}
	g.x1 = COLS * TILE_SIZE - 1;
	g.y1 = 0;
	g.x2 = COLS * TILE_SIZE - 1;
	g.y2 = HEIGHT;
	render_line(game, g);
}

void	render_vertical(t_game *game)
{
	int			i;
	t_grid_dist	g;

	i = 0;
	while (i < ROWS)
	{
		g.x1 = 0;
		g.y1 = i * TILE_SIZE;
		g.x2 = WIDTH;
		g.y2 = i * TILE_SIZE;
		render_line(game, g);
		i++;
	}
	g.x1 = 0;
	g.y1 = ROWS * TILE_SIZE - 1;
	g.x2 = WIDTH;
	g.y2 = ROWS * TILE_SIZE - 1;
	render_line(game, g);
}

void	render_line_with_color(t_game *g, t_grid_dist grid, int color)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = grid.x2 - grid.x1;
	deltaY = grid.y2 - grid.y1;
	if (fabs(deltaX) > fabs(deltaY))
		step = fabs(deltaX);
	else
		step = fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(grid.x2 - grid.x1) > 0.01 || fabs(grid.y2 - grid.y1) > 0.01)
	{
		g->img.data[to_coord_minimap(grid.x1, grid.y1)] = color;
		grid.x1 += deltaX;
		grid.y1 += deltaY;
	}
}
