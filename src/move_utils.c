/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 08:34:58 by user42            #+#    #+#             */
/*   Updated: 2022/05/09 14:15:48 by mhirabay         ###   ########.fr       */
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

bool	check_left_player_line(t_game *g, int i, int j)
{
	int	y;

	y = g->player->y_draw_start;
	while (y < g->player->y_draw_end)
	{
		if (map_has_wall_at(g, g->player->x_draw_start + i, y + j))
			return (true);
		y++;
	}
	return (false);
}

bool	check_right_player_line(t_game *g, int i, int j)
{
	int	y;

	y = g->player->y_draw_start;
	while (y < g->player->y_draw_end)
	{
		if (map_has_wall_at(\
			g, g->player->x_draw_end + i, y + j))
			return (true);
		y++;
	}
	return (false);
}

bool	check_top_player_line(t_game *g, int i, int j)
{
	int	x;

	x = g->player->x_draw_start;
	while (x < g->player->x_draw_end)
	{
		if (map_has_wall_at(g, x + i, g->player->y_draw_start + j))
			return (true);
		x++;
	}
	return (false);
}

bool	check_bottom_player_line(t_game *g, int i, int j)
{
	int	x;

	x = g->player->x_draw_start;
	while (x < g->player->x_draw_end)
	{
		if (map_has_wall_at(g, x + i, g->player->y_draw_end + j))
			return (true);
		x++;
	}
	return (false);
}
