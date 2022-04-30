/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:18:45 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/20 17:26:44 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_3d(t_game *g)
{
	int				i;
	t_wall3d_info	w_info;

	i = 0;
	while (i < NUM_RAYS)
	{
		calc_wall_info(g->player->ray[i], g->player->rotate_angle, &w_info);
		clear_celling(g, i, w_info.wall_top_pixel);
		while (w_info.wall_top_pixel < w_info.wall_bottom_pixel)
		{
			g->img.data[to_coord(i, w_info.wall_top_pixel)] = BLACK;
			w_info.wall_top_pixel++;
		}
		clear_floor(g, i, w_info.wall_top_pixel);
		i++;
	}
	clear_all_rays(g);
}

int	calc_offset_x(int wall_hit)
{
	return (wall_hit % TILE_SIZE * (TEXTURE_WIDTH / (double)TILE_SIZE));
}
