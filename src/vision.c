/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:24:43 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/31 17:39:06 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	reset_vision(t_game *g)
{
	int		i;
	int		length;
	double	x1;
	double	y1;
	int		fov_min;
	int		ret;

	i = 0;
	while (i < FOV_MAX_DEGREE - FOV_MIN_DEGREE + 1)
	{
		g->player->is_collide[i] = false;
		i++;
	}
	i = g->player->x + 1;
	length = 1;
	while (i < WIDTH)
	{
		g->img.data[TO_COORD(i, g->player->y)] = 0x0;
		fov_min = g->player->fov_min;
		while (fov_min <= g->player->fov_max)
		{
			x1 = length * cos(fov_min * M_PI / 180);
			y1 = length * sin(fov_min * M_PI / 180);
			ret = to_coord(g->player->x + x1, g->player->y + y1);
			if (ret < 0 || ret >= get_max_coord_size())
			{
				fov_min++;
				continue ;
			}
			g->img.data[ret] = 0x0;
			fov_min++;
		}
		length++;
		i++;
	}
}

void	draw_vision(t_game *g)
{
	int		i;
	int		length;
	double	x1;
	double	y1;
	int		fov_min;
	int		ret;

	i = g->player->x + 1;
	length = 1;
	while (i < WIDTH)
	{
		// g->img.data[TO_COORD(i, g->player->y)] = 0xFF0000;
		fov_min = g->player->fov_min;
		while (fov_min <= g->player->fov_max)
		{
			if (g->player->is_collide[fov_min - g->player->fov_min])
			{
				fov_min++;
				continue ;
			}
			x1 = length * cos(fov_min * M_PI / 180);
			y1 = length * sin(fov_min * M_PI / 180);
			ret = to_coord(g->player->x + x1, g->player->y + y1);
			if (ret == 0 || ret >= get_max_coord_size())
			{
				fov_min++;
				continue ;
			}
			if (g->img.data[ret] == 0xFFFFFF)
			{
				g->player->is_collide[fov_min - g->player->fov_min] = true;
				fov_min++;
				continue ;
			}
			g->img.data[ret] = 0xFF0000;
			fov_min++;
		}
		length++;
		i++;
	}
}

void	look_left(t_game *g)
{
	reset_vision(g);
	g->player->fov_min -= PLAYER_LOOK_DEGREE;
	g->player->fov_max -= PLAYER_LOOK_DEGREE;
	draw_vision(g);
}

void	look_right(t_game *g)
{
	reset_vision(g);
	g->player->fov_min += PLAYER_LOOK_DEGREE;
	g->player->fov_max += PLAYER_LOOK_DEGREE;
	draw_vision(g);
}
