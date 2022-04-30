/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 08:34:58 by user42            #+#    #+#             */
/*   Updated: 2022/04/30 16:13:22 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
void	update_grid(t_game *g, int x, int y)
{
	g->player->x_draw_start += x;
	g->player->x_draw_end += x;
	g->player->x += x;
	g->player->y_draw_start += y;
	g->player->y_draw_end += y;
	g->player->y += y;
}
