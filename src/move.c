/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:09:13 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/06 17:20:51 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_game *g)
{
	int i;
	int j;

	i = 0;
	clear_all_rays(g);
	g->player->y_draw_end -= PLAYER_MOVE_PIXEL;
	while (i < PLAYER_SIZE)
	{
		// TILEサイズの左上から全部1pixelずつなぞっていく
		g->img.data[(g->player->y_draw_end) * WIDTH + g->player->x_draw_point + i] = 0x0;
		i++;
	}
	i = 0;
	g->player->y_draw_point -= PLAYER_MOVE_PIXEL;
	printf("game->player->y_draw_point = %d\n", g->player->y_draw_point);
	while (i < PLAYER_SIZE)
	{
		j = 0;
		while (j < PLAYER_SIZE)
		{
			g->img.data[(g->player->y_draw_point + i) * WIDTH + g->player->x_draw_point + j] = 0xFF0000;
			j++;
		}
		i++;
	}
	g->player->y -= PLAYER_MOVE_PIXEL;
	draw_vision(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
}

void	move_left(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	clear_all_rays(g);
	g->player->x_draw_end -= PLAYER_MOVE_PIXEL;
	while (i < PLAYER_SIZE)
	{
		g->img.data[(g->player->y_draw_point + i) * WIDTH + g->player->x_draw_end] = 0x0;
		i++;
	}
	i = 0;
	g->player->x_draw_point -= PLAYER_MOVE_PIXEL;
	while (i < PLAYER_SIZE)
	{
		j = 0;
		while (j < PLAYER_SIZE)
		{
			g->img.data[(g->player->y_draw_point + i) * WIDTH + g->player->x_draw_point + j] = 0xFF0000;
			j++;
		}
		i++;
	}
	g->player->x -= PLAYER_MOVE_PIXEL;
	draw_vision(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
}

void	move_right(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	clear_all_rays(g);
	while (i < PLAYER_SIZE)
	{
		g->img.data[(g->player->y_draw_point + i) * WIDTH + g->player->x_draw_point] = 0x0;
		i++;
	}
	g->player->x_draw_point += PLAYER_MOVE_PIXEL;
	i = 0;
	g->player->x_draw_end += PLAYER_MOVE_PIXEL;
	while (i < PLAYER_SIZE)
	{
		j = 0;
		while (j < PLAYER_SIZE)
		{
			g->img.data[(g->player->y_draw_point + i) * WIDTH + g->player->x_draw_point + j] = 0xFF0000;
			j++;
		}
		i++;
	}
	g->player->x += PLAYER_MOVE_PIXEL;
	draw_vision(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
}

void	move_back(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	clear_all_rays(g);
	while (i < PLAYER_SIZE)
	{
		g->img.data[(g->player->y_draw_point) * WIDTH + g->player->x_draw_point + i] = 0x0;
		i++;
	}
	g->player->y_draw_point += PLAYER_MOVE_PIXEL;
	i = 0;
	g->player->y_draw_end += PLAYER_MOVE_PIXEL;
	while (i < PLAYER_SIZE)
	{
		j = 0;
		while (j < PLAYER_SIZE)
		{
			g->img.data[(g->player->y_draw_point + i) * WIDTH + g->player->x_draw_point + j] = 0xFF0000;
			j++;
		}
		i++;
	}
	g->player->y += PLAYER_MOVE_PIXEL;
	draw_vision(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
}
