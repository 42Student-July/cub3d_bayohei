/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:56:29 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/19 15:50:39 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_game *game)
{
	game->player = (t_player *)malloc(sizeof(t_player));
	if (game->player == NULL)
		exit_with_err_msg(MALLOC_ERROR);
	game->player->ray = (t_ray **)malloc(sizeof(t_ray *) * NUM_RAYS);
	if (game->player->ray == NULL)
		exit_with_err_msg(MALLOC_ERROR);
	init_player_coord(game);
}

void	init_player_coord(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < ROWS)
	{	
		j = 0;
		while (j < COLS)
		{
			if (g->map[i][j] == 2)
			{
				g->player->x = j * TILE_SIZE - TILE_SIZE / 2;
				g->player->y = i * TILE_SIZE - TILE_SIZE / 2;
				g->player->x_draw_start = g->player->x - PLAYER_SIZE / 2;
				g->player->y_draw_start = g->player->y - PLAYER_SIZE / 2;
				g->player->x_draw_end = g->player->x_draw_start + PLAYER_SIZE;
				g->player->y_draw_end = g->player->y_draw_start + PLAYER_SIZE;
				g->player->rotate_angle = 0;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_color(t_game *game)
{
	game->floor_color = GREEN;
	game->celling_color = SKY_BLUE;
}
