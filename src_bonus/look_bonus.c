/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:43:09 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/30 16:13:22 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	look_left(t_game *g)
{
	g->player->rotate_angle -= 30 * g->fov_angle / (NUM_RAYS);
}

void	look_right(t_game *g)
{
	g->player->rotate_angle += 30 * g->fov_angle / (NUM_RAYS);
}
