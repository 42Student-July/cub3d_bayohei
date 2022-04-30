/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:13:30 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/30 16:13:22 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	render_lines(t_game *game)
{
	render_horizontal(game);
	render_vertical(game);
}

void	render_celling(t_game *g, int x, int wall_top_pixel)
{
	int	i;

	i = 0;
	while (i < wall_top_pixel)
	{
		g->img.data[to_coord(x, i)] = g->celling_color;
		i++;
	}
}

void	render_floor(t_game *g, int x, int wall_bottom_pixel)
{
	while (wall_bottom_pixel < HEIGHT)
	{
		g->img.data[to_coord(x, wall_bottom_pixel)] = g->floor_color;
		wall_bottom_pixel++;
	}
}

void	clear_celling(t_game *g, int x, int wall_top_pixel)
{
	int	i;

	i = 0;
	while (i < wall_top_pixel)
	{
		g->img.data[to_coord(x, i)] = BLACK;
		i++;
	}
}

void	clear_floor(t_game *g, int x, int wall_bottom_pixel)
{
	while (wall_bottom_pixel < HEIGHT)
	{
		g->img.data[to_coord(x, wall_bottom_pixel)] = BLACK;
		wall_bottom_pixel++;
	}
}
