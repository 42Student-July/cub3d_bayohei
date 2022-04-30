/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:09:06 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/30 14:41:48 by mhirabay         ###   ########.fr       */
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

bool	calc_x_and_y(t_game *g)
{
	int	i;
	int	j;
	int	a;
	int	b;

	a = 1;
	b = 1;
	while (a <= PLAYER_MOVE_PIXEL)
	{
		i = a * cos(g->player->rotate_angle);
		j = b * sin(g->player->rotate_angle);
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
	if (calc_x_and_y(g))
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
	x = (int)(PLAYER_MOVE_PIXEL * cos(g->player->rotate_angle + (M_PI / 2)));
	y = (int)(PLAYER_MOVE_PIXEL * sin(g->player->rotate_angle + (M_PI / 2)));
	if (map_has_wall_at(\
	g, g->player->x_draw_start + x, g->player->y_draw_start + y))
		return ;
	if (map_has_wall_at(\
	g, g->player->x_draw_end + x, g->player->y_draw_end + y))
		return ;
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
	x = PLAYER_MOVE_PIXEL * cos(g->player->rotate_angle + (M_PI * 3 / 2));
	y = PLAYER_MOVE_PIXEL * sin(g->player->rotate_angle + (M_PI * 3 / 2));
	if (map_has_wall_at(\
	g, g->player->x_draw_start + x, g->player->y_draw_start + y))
		return ;
	if (map_has_wall_at(\
	g, g->player->x_draw_end + x, g->player->y_draw_end + y))
		return ;
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
	x = (int)(PLAYER_MOVE_PIXEL * cos(g->player->rotate_angle + M_PI));
	y = (int)(PLAYER_MOVE_PIXEL * sin(g->player->rotate_angle + M_PI));
	if (map_has_wall_at(\
	g, g->player->x_draw_start + x, g->player->y_draw_start + y))
		return ;
	if (map_has_wall_at(\
	g, g->player->x_draw_end + x, g->player->y_draw_end + y))
		return ;
	while (i < PLAYER_SIZE)
	{
		g->img.data[to_coord_minimap(\
		g->player->x_draw_start + i, g->player->y_draw_end)] = BLACK;
		i++;
	}
	update_grid(g, x, y);
}

