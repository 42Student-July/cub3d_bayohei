/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:09:13 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/18 15:28:37 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_north(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	clear_3d(g);
	while (i < PLAYER_SIZE)
	{
		g->img.data[to_coord_minimap(\
		g->player->x_draw_start + i, g->player->y_draw_end)] = 0x0;
		i++;
	}
	i = 0;
	g->player->y_draw_start -= PLAYER_MOVE_PIXEL;
	g->player->y_draw_end -= PLAYER_MOVE_PIXEL;
	while (i < PLAYER_SIZE)
	{
		j = 0;
		while (j < PLAYER_SIZE)
		{
			g->img.data[to_coord_minimap(\
			g->player->x_draw_start + j, g->player->y_draw_start + i)] = YELLOW;
			j++;
		}
		i++;
	}
	g->player->y -= PLAYER_MOVE_PIXEL;
	render_vision(g);
}

void	move_west(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	clear_3d(g);
	while (i < PLAYER_SIZE)
	{
		g->img.data[to_coord_minimap(\
		g->player->x_draw_end, g->player->y_draw_start + i)] = BLACK;
		i++;
	}
	i = 0;
	g->player->x_draw_end -= PLAYER_MOVE_PIXEL;
	g->player->x_draw_start -= PLAYER_MOVE_PIXEL;
	while (i < PLAYER_SIZE)
	{
		j = 0;
		while (j < PLAYER_SIZE)
		{
			g->img.data[to_coord_minimap(\
			g->player->x_draw_start + j, g->player->y_draw_start + i)] = YELLOW;
			j++;
		}
		i++;
	}
	g->player->x -= PLAYER_MOVE_PIXEL;
	render_vision(g);
}

void	move_east(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	clear_3d(g);
	while (i < PLAYER_SIZE)
	{
		g->img.data[to_coord_minimap(\
		g->player->x_draw_start, g->player->y_draw_start + i)] = BLACK;
		i++;
	}
	i = 0;
	g->player->x_draw_start += PLAYER_MOVE_PIXEL;
	g->player->x_draw_end += PLAYER_MOVE_PIXEL;
	while (i < PLAYER_SIZE)
	{
		j = 0;
		while (j < PLAYER_SIZE)
		{
			g->img.data[to_coord_minimap(\
			g->player->x_draw_start + j, g->player->y_draw_start + i)] = YELLOW;
			j++;
		}
		i++;
	}
	g->player->x += PLAYER_MOVE_PIXEL;
	render_vision(g);
}

void	move_south(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	clear_3d(g);
	while (i < PLAYER_SIZE)
	{
		g->img.data[to_coord_minimap(\
		g->player->x_draw_start + i, g->player->y_draw_start)] = BLACK;
		i++;
	}
	i = 0;
	g->player->y_draw_start += PLAYER_MOVE_PIXEL;
	g->player->y_draw_end += PLAYER_MOVE_PIXEL;
	while (i < PLAYER_SIZE)
	{
		j = 0;
		while (j < PLAYER_SIZE)
		{
			g->img.data[to_coord_minimap(\
			g->player->x_draw_start + j, g->player->y_draw_start + i)] = YELLOW;
			j++;
		}
		i++;
	}
	g->player->y += PLAYER_MOVE_PIXEL;
	render_vision(g);
}
