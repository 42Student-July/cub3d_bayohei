/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:28:44 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/30 16:13:22 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	render_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < PLAYER_SIZE)
	{
		j = 0;
		while (j < PLAYER_SIZE)
		{
			game->img.data[to_coord_minimap(\
			game->player->x_draw_start + j, \
			game->player->y_draw_start + i)] = YELLOW;
			j++;
		}
		i++;
	}
}

void	render_wall(t_game *game, int x, int y)
{
	int	i;
	int	j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			game->img.data[to_coord_minimap(x + j, y + i)] = WHITE;
			j++;
		}
		i++;
	}
}

void	render_ground(t_game *game, int x, int y)
{
	int	i;
	int	j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			game->img.data[to_coord_minimap(x + j, y + i)] = 0xC0C0C0;
			j++;
		}
		i++;
	}
}

void	render_minimap(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{	
		j = 0;
		while (game->map[i][j] != END)
		{
			if (game->map[i][j] == 1)
				render_wall(game, j, i);
			else if (game->map[i][j] == 0 || game->map[i][j] == NO || \
			game->map[i][j] == SO || game->map[i][j] == EA \
			|| game->map[i][j] == WE)
				render_ground(game, j, i);
			j++;
		}
		i++;
	}
}
