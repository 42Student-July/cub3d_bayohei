/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:17:16 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/18 15:28:37 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_game *game, double x1, double y1, double x2, double y2)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	// https://ichi.pro/ddasen-byoga-arugorizumu-209590219776463
	// 傾きが |m| が 1より大きいかそれ以下かを示している
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
	// どちらかが1に限りなく近い数値になる。
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		game->img.data[to_coord_minimap(x1, y1)] = 0xB3B3B3;
		x1 += deltaX;
		y1 += deltaY;
	}
}

void	draw_line_with_color(t_game *game, double x1, double y1, double x2, double y2, int color)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	// https://ichi.pro/ddasen-byoga-arugorizumu-209590219776463
	// 傾きが |m| が 1より大きいかそれ以下かを示している
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
	// どちらかが1に限りなく近い数値になる。
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		game->img.data[to_coord_minimap(x1, y1)] = color;
		x1 += deltaX;
		y1 += deltaY;
	}
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

void	draw_lines(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < COLS)
	{
		draw_line(game, i * TILE_SIZE, 0, i * TILE_SIZE, HEIGHT);
		i++;
	}
	draw_line(game, COLS * TILE_SIZE - 1, 0, COLS * TILE_SIZE - 1, HEIGHT);
	j = 0;
	while (j < ROWS)
	{
		draw_line(game, 0, j * TILE_SIZE, WIDTH, j * TILE_SIZE);
		j++;
	}
	draw_line(game, 0, ROWS * TILE_SIZE - 1, WIDTH, ROWS * TILE_SIZE - 1);
}

void	draw_wall(t_game *game, int x, int y)
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
			// TILEサイズの左上から全部1pixelずつなぞっていく
			game->img.data[to_coord_minimap(x + j, y + i)] = 0xFFFFFF;
			j++;
		}
		i++;
	}
}

void	draw_ground(t_game *game, int x, int y)
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
			// TILEサイズの左上から全部1pixelずつなぞっていく
			game->img.data[to_coord_minimap(x + j, y + i)] = 0xC0C0C0;
			j++;
		}
		i++;
	}
}

void	draw_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < PLAYER_SIZE)
	{
		j = 0;
		while (j < PLAYER_SIZE)
		{
			// TILEサイズの左上から全部1pixelずつなぞっていく
			game->img.data[to_coord_minimap(game->player->x_draw_start + j, game->player->y_draw_start + i)] = 0xFFFF00;
			j++;
		}
		i++;
	}
}

void	draw_rectangles(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < ROWS)
	{	
		j = 0;
		while (j < COLS)
		{
			if (game->map[i][j] == 1)
				draw_wall(game, j, i);
			else
				draw_ground(game, j, i);
			j++;
		}
		i++;
	}
}

int	deal_key(int key_code, t_game *game)
{
	printf("key_code = %d\n", key_code);
	if (key_code == KEY_ESC)
		exit(0);
	if (key_code == KEY_W)
		move_north(game);
	else if (key_code == KEY_A)
		move_west(game);
	else if (key_code == KEY_D)
		move_east(game);
	else if (key_code == KEY_S)
		move_south(game);
	if (key_code == KEY_LEFT_ARROW)
		look_left(game);
	else if (key_code == KEY_RIGHT_ARROW)
		look_right(game);
	return (0);
}

int	main_loop(t_game *game)
{
	cast_all_rays(game);
	generate_3d(game);
	draw_rectangles(game);
	render_vision(game);
	draw_lines(game);
	draw_player(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

int 	close_game(t_game *game)
{
	(void)game;
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	args_handling(argc, argv);
	init(&game, argv[FILE_PATH]);
	draw_player(&game);
	render_vision(&game);
	draw_rectangles(&game);
	// render_first(&game);
	mlx_key_hook(game.win, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
