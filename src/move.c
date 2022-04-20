/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:09:06 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/20 15:15:31 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_game *g)
{
	if (g->player->direction == NO)
		move_north(g);
	else if (g->player->direction == SO)
		move_south(g);
	else if (g->player->direction == WE)
		move_west(g);
	else if (g->player->direction == EA)
		move_east(g);
}

void	move_right(t_game *g)
{
	if (g->player->direction == NO)
		move_east(g);
	else if (g->player->direction == SO)
		move_west(g);
	else if (g->player->direction == WE)
		move_north(g);
	else if (g->player->direction == EA)
		move_south(g);
}

void	move_left(t_game *g)
{
	if (g->player->direction == NO)
		move_west(g);
	else if (g->player->direction == SO)
		move_east(g);
	else if (g->player->direction == WE)
		move_south(g);
	else if (g->player->direction == EA)
		move_north(g);
}

void	move_back(t_game *g)
{
	if (g->player->direction == NO)
		move_south(g);
	else if (g->player->direction == SO)
		move_north(g);
	else if (g->player->direction == WE)
		move_east(g);
	else if (g->player->direction == EA)
		move_west(g);
}
