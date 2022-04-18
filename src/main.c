/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:17:16 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/18 15:30:12 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_line(t_game *game, double x1, double y1, double x2, double y2)
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
	render_rectangles(game);
	render_vision(game);
	render_lines(game);
	render_player(game);
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
	render_player(&game);
	render_vision(&game);
	render_rectangles(&game);
	// render_first(&game);
	mlx_key_hook(game.win, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close_game, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
