/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:15:51 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/30 16:13:36 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "parser_bonus.h"

int	deal_key(int key_code, t_game *game)
{
	printf("key_code = %d\n", key_code);
	if (key_code == KEY_ESC)
		exit(0);
	if (key_code == KEY_W)
		move_forward(game);
	else if (key_code == KEY_A)
		move_left(game);
	else if (key_code == KEY_D)
		move_right(game);
	else if (key_code == KEY_S)
		move_back(game);
	if (key_code == KEY_LEFT_ARROW)
		look_left(game);
	else if (key_code == KEY_RIGHT_ARROW)
		look_right(game);
	return (0);
}

int	deal_key_1(int key_code, t_game *game)
{
	printf("key_code = %d\n", key_code);
	(void)game;
	return (0);
}

int	render(t_game *game)
{
	render_vision(game);
	generate_3d(game);
	render_minimap(game);
	render_vision(game);
	render_player(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

int	close_game(t_game *game)
{
	clear_all_rays(game);
	exit(0);
}

void	set_hooks(t_game *game)
{
	mlx_hook(game->win, 2, (1L << 0), &deal_key, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &close_game, game);
	mlx_loop_hook(game->mlx, &render, game);
}
