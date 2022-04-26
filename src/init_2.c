/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:56:29 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/26 22:50:25 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_game *game)
{
	int	i;

	i = 0;
	game->player = (t_player *)malloc(sizeof(t_player));
	if (game->player == NULL)
		exit_with_err_msg(MALLOC_ERROR);
	game->player->ray = (t_ray **)xmalloc(sizeof(t_ray *) * NUM_RAYS);
	while (i < NUM_RAYS)
	{
		game->player->ray[i] = (t_ray *)xmalloc(sizeof(t_ray));
		i++;
	}
	if (game->player->ray == NULL)
		exit_with_err_msg(MALLOC_ERROR);
	init_player_coord(game);
}

bool	is_player_position(int map_data)
{
	if (
		map_data == NO || \
		map_data == SO || \
		map_data == WE || \
		map_data == EA
	)
		return (true);
	return (false);
}

void	init_player_angle(t_game *g, int direction)
{
	g->player->direction = direction;
	if (direction == NO)
	{
		g->player->rotate_angle = 270 * (M_PI / 180);
	}
	else if (direction == SO)
	{
		g->player->rotate_angle = 90 * (M_PI / 180);
	}
	else if (direction == WE)
	{
		g->player->rotate_angle = 180 * (M_PI / 180);
	}
	else if (direction == EA)
	{
		g->player->rotate_angle = 0 * (M_PI / 180);
	}
	else
		g->player->rotate_angle = 0 * (M_PI / 180);
}

void	init_player_coord(t_game *g)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (g->map[i] != NULL)
	{	
		j = 0;
		while (g->map[i][j] != END)
		{
			if (is_player_position(g->map[i][j]))
			{
				g->player->x = j * TILE_SIZE + TILE_SIZE / 2;
				g->player->y = i * TILE_SIZE + TILE_SIZE / 2;
				g->player->x_draw_start = g->player->x - PLAYER_SIZE / 2;
				g->player->y_draw_start = g->player->y - PLAYER_SIZE / 2;
				g->player->x_draw_end = g->player->x_draw_start + PLAYER_SIZE;
				g->player->y_draw_end = g->player->y_draw_start + PLAYER_SIZE;
				init_player_angle(g, g->map[i][j]);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_color(t_game *game)
{
	game->floor_color = game->d.color[FLOOR];
	game->celling_color = game->d.color[CEIL];
}
