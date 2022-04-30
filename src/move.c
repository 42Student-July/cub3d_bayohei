/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:09:06 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/30 14:47:22 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_grid(t_game *g, int x, int y)
{
	g->player->x_draw_start += x;
	g->player->x_draw_end += x;
	g->player->x += x;
	g->player->y_draw_start += y;
	g->player->y_draw_end += y;
	g->player->y += y;
}

bool	is_wall_on_direction(t_game *g, double angle)
{
	int	i;
	int	j;
	int	a;
	int	b;

	a = 1;
	b = 1;
	while (a <= PLAYER_MOVE_PIXEL)
	{
		i = a * cos(g->player->rotate_angle + angle);
		j = b * sin(g->player->rotate_angle + angle);
		if (map_has_wall_at(\
			g, g->player->x_draw_start + i, g->player->y_draw_start + j))
			return (true);
		if (map_has_wall_at(\
			g, g->player->x_draw_end + i, g->player->y_draw_end + j))
			return (true);
		a++;
		b++;
	}
	return (false);
}

void	move_forward(t_game *g)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	if (is_wall_on_direction(g, 0))
		return ;
	x = (int)(PLAYER_MOVE_PIXEL * cos(g->player->rotate_angle));
	y = (int)(PLAYER_MOVE_PIXEL * sin(g->player->rotate_angle));
	while (i < PLAYER_SIZE)
	{
		g->img.data[to_coord_minimap(\
		g->player->x_draw_start + i, g->player->y_draw_end)] = BLACK;
		i++;
	}
	update_grid(g, x, y);
}

void	move_right(t_game *g)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	if (is_wall_on_direction(g, (M_PI / 2)))
		return ;
	x = (int)(PLAYER_MOVE_PIXEL * cos(g->player->rotate_angle + (M_PI / 2)));
	y = (int)(PLAYER_MOVE_PIXEL * sin(g->player->rotate_angle + (M_PI / 2)));
	while (i < PLAYER_SIZE)
	{
		g->img.data[to_coord_minimap(\
		g->player->x_draw_start + i, g->player->y_draw_end)] = BLACK;
		i++;
	}
	update_grid(g, x, y);
}

void	move_left(t_game *g)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	if (is_wall_on_direction(g, (M_PI * 3 / 2)))
		return ;
	x = PLAYER_MOVE_PIXEL * cos(g->player->rotate_angle + (M_PI * 3 / 2));
	y = PLAYER_MOVE_PIXEL * sin(g->player->rotate_angle + (M_PI * 3 / 2));
	while (i < PLAYER_SIZE)
	{
		g->img.data[to_coord_minimap(\
		g->player->x_draw_start + i, g->player->y_draw_end)] = BLACK;
		i++;
	}
	update_grid(g, x, y);
}

void	move_back(t_game *g)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	if (is_wall_on_direction(g, (M_PI)))
		return ;
	x = (int)(PLAYER_MOVE_PIXEL * cos(g->player->rotate_angle + M_PI));
	y = (int)(PLAYER_MOVE_PIXEL * sin(g->player->rotate_angle + M_PI));
	while (i < PLAYER_SIZE)
	{
		g->img.data[to_coord_minimap(\
		g->player->x_draw_start + i, g->player->y_draw_end)] = BLACK;
		i++;
	}
	update_grid(g, x, y);
}

