/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:15:51 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/18 17:06:14 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	render(t_game *game)
{
	render_vision(game);
	generate_3d(game);
	render_minimap(game);
	render_vision(game);
	render_lines(game);
	render_player(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

int	close_game(t_game *game)
{
	(void)game;
	exit(0);
}

void	set_hooks(t_game *game)
{
	mlx_key_hook(game->win, &deal_key, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &close_game, game);
	mlx_loop_hook(game->mlx, &render, game);
}