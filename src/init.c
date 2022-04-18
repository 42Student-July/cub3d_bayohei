/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 10:28:51 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/18 11:50:47 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_game *game, char *filename)
{
	window_init(game);
	read_cub_asset(game, filename);
}

void	read_cub_asset(t_game *game, char *filename)
{
	// int	fd;

	(void)game;
	(void)filename;
	// fd = open(filename, O_RDONLY);
	// if (fd == -1)
	// 	exit_with_err_msg(READ_FILE_ERROR);
	map_init(game);
	img_init(game);
}

// TODO: fileから読み込む形式にする
void	map_init(t_game *game)
{	
	int map[ROWS][COLS] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	memcpy(game->map, map, sizeof(int) * ROWS * COLS);
	// ここにmap関係のvalidationを実装する
	// mapはintの二次元配列 playerのN, E, S, Wは2, 3, 4, 5とする
}

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		exit_with_err_msg(MALLOC_ERROR);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3d");
	if (game->win == NULL)
		exit_with_err_msg(MALLOC_ERROR);
}

void	img_init(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->img.img == NULL)
		exit_with_err_msg(MALLOC_ERROR);
	game->img.data = (int *)mlx_get_data_addr(\
		game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
}
