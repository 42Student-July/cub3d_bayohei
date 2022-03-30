/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:24:43 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/30 22:18:48 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	reset_vision(t_game *g)
{
	int		i;
	int		length;
	double	x1;
	double	y1;
	int		left_max_degree;
	int		ret;

	i = g->player->x + 1;
	length = 1;
	while (i < WIDTH)
	{
		g->img.data[TO_COORD(i, g->player->y)] = 0x0;
		left_max_degree = -45;
		while (left_max_degree <= 45)
		{
			x1 = length * cos(left_max_degree * M_PI / 180);
			y1 = length * sin(left_max_degree * M_PI / 180);
			ret = to_coord(g->player->x + x1, g->player->y + y1);
			g->img.data[ret] = 0x0;
			left_max_degree++;
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
	int		left_max_degree;
	int		ret;

	i = g->player->x + 1;
	length = 1;
	while (i < WIDTH)
	{
		g->img.data[TO_COORD(i, g->player->y)] = 0xFF0000;
		left_max_degree = -45;
		while (left_max_degree <= 45)
		{
			x1 = length * cos(left_max_degree * M_PI / 180);
			y1 = length * sin(left_max_degree * M_PI / 180);
			ret = to_coord(g->player->x + x1, g->player->y + y1);
			g->img.data[ret] = 0xFF0000;
			left_max_degree++;
		}
		length++;
		i++;
	}
}
