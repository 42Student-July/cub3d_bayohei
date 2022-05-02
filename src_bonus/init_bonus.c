/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 10:28:51 by mhirabay          #+#    #+#             */
/*   Updated: 2022/05/02 15:46:22 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_game *game)
{
	game->fov_angle = (ANGLE * (M_PI / 180));
	init_window(game);
	read_cub_asset(game);
	init_player(game);
}

void	read_cub_asset(t_game *game)
{
	game->map = game->d.map;
	init_img(game);
	init_color(game);
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		exit_with_err_msg(MALLOC_ERROR);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3d");
	if (game->win == NULL)
		exit_with_err_msg(MALLOC_ERROR);
}

void	init_texture(t_game *game)
{
	int	height;
	int	width;

	height = TEXTURE_HEIGHT;
	width = TEXTURE_WIDTH;
	game->texture.no_img.img = mlx_xpm_file_to_image(\
	game->mlx, game->d.tex[TEX_NO], &width, &height);
	if (game->texture.no_img.img == NULL)
		exit_with_err_msg(MALLOC_ERROR);
	game->texture.no_img.data = get_data_addr(&game->texture.no_img);
	game->texture.so_img.img = mlx_xpm_file_to_image(\
	game->mlx, game->d.tex[TEX_SO], &width, &height);
	if (game->texture.so_img.img == NULL)
		exit_with_err_msg(MALLOC_ERROR);
	game->texture.so_img.data = get_data_addr(&game->texture.so_img);
	game->texture.ea_img.img = mlx_xpm_file_to_image(\
	game->mlx, game->d.tex[TEX_EA], &width, &height);
	if (game->texture.ea_img.img == NULL)
		exit_with_err_msg(MALLOC_ERROR);
	game->texture.ea_img.data = get_data_addr(&game->texture.ea_img);
	game->texture.we_img.img = mlx_xpm_file_to_image(\
	game->mlx, game->d.tex[TEX_WE], &width, &height);
	if (game->texture.we_img.img == NULL)
		exit_with_err_msg(MALLOC_ERROR);
	game->texture.we_img.data = get_data_addr(&game->texture.we_img);
}

void	init_img(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->img.img == NULL)
		exit_with_err_msg(MALLOC_ERROR);
	game->img.data = (int *)mlx_get_data_addr(\
		game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
	init_texture(game);
}
