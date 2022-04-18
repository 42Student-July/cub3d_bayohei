/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:43:09 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/18 16:43:33 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	look_left(t_game *g)
{
	clear_3d(g);
	g->player->rotate_angle -= 5 * FOV_ANGLE / (NUM_RAYS);
	cast_all_rays(g);
	render_all_rays(g);
}

void	look_right(t_game *g)
{
	clear_3d(g);
	g->player->rotate_angle += 5 * FOV_ANGLE / (NUM_RAYS);
	cast_all_rays(g);
	render_all_rays(g);
}
