/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vision.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:24:43 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/30 16:17:17 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	reset_vision(t_game *g)
{
	int	i;
	i = g->player->x;
	while (i < WIDTH)
	{
		g->img.data[TO_COORD(i, g->player->y)] = 0x0;
		i++;
	}
}

void	draw_vision(t_game *g)
{
	int	i;
	int	nagasa;
	int	x1;
	int	y1;
	int	left_max_degree;

	i = g->player->x + 1;
	nagasa = 1;
	while (i < WIDTH)
	{
		g->img.data[TO_COORD(i, g->player->y)] = 0xFF0000;
		left_max_degree = -45;
		while (left_max_degree <= 45)
		{
			x1 = nagasa * cos(left_max_degree * M_PI / 180);
			y1 = nagasa * sin(left_max_degree * M_PI / 180);
			g->img.data[TO_COORD(g->player->x + x1, g->player->y + y1)] = 0xFF0000;
			left_max_degree++;
		}
		nagasa++;
		i++;
	}
}
