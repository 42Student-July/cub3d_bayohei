/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:43:09 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/30 06:43:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	look_left(t_game *g)
{
	g->player->rotate_angle -= 30 * g->fov_angle / (NUM_RAYS);
}

void	look_right(t_game *g)
{
	g->player->rotate_angle += 30 * g->fov_angle / (NUM_RAYS);
}
