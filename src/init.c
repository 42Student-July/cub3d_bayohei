/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 10:28:51 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/20 18:22:40 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_game *game, char *filename)
{
	init_window(game);
	read_cub_asset(game, filename);
	init_player(game);
}

void	read_cub_asset(t_game *game, char *filename)
{
	// int	fd;

	(void)game;
	(void)filename;
	// fd = open(filename, O_RDONLY);
	// if (fd == -1)
	// 	exit_with_err_msg(READ_FILE_ERROR);
	//init_map(game);
	game->map = game->d.map;
	init_img(game);
	init_color(game);
}

// TODO: fileから読み込む形式にする

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
		// xpmを読み込む、暫定で絶対パスで読み込む
	game->texture.no_img.img = mlx_xpm_file_to_image(\
	game->mlx, game->d.tex[TEX_NO], &width, &height);
	if (game->img.img == NULL)
		exit_with_err_msg(MALLOC_ERROR);
	game->texture.no_img.data = (int *)mlx_get_data_addr(\
		game->texture.no_img.img, &game->texture.no_img.bpp, \
		&game->texture.no_img.size_l, &game->texture.no_img.endian);

	game->texture.so_img.img = mlx_xpm_file_to_image(\
	game->mlx,game->d.tex[TEX_SO], &width, &height);
	if (game->img.img == NULL)
		exit_with_err_msg(MALLOC_ERROR);
	game->texture.so_img.data = (int *)mlx_get_data_addr(\
		game->texture.so_img.img, &game->texture.so_img.bpp, \
		&game->texture.so_img.size_l, &game->texture.so_img.endian);

	game->texture.ea_img.img = mlx_xpm_file_to_image(\
	game->mlx, game->d.tex[TEX_EA], &width, &height);
	if (game->img.img == NULL)
		exit_with_err_msg(MALLOC_ERROR);
	game->texture.ea_img.data = (int *)mlx_get_data_addr(\
		game->texture.ea_img.img, &game->texture.ea_img.bpp, \
	&game->texture.ea_img.size_l, &game->texture.ea_img.endian);

	game->texture.we_img.img = mlx_xpm_file_to_image(\
	game->mlx, game->d.tex[WE], &width, &height);
	if (game->img.img == NULL)
		exit_with_err_msg(MALLOC_ERROR);
	game->texture.we_img.data = (int *)mlx_get_data_addr(\
		game->texture.we_img.img, &game->texture.we_img.bpp, \
		&game->texture.we_img.size_l, &game->texture.we_img.endian);
}

void	init_img(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx,WIDTH, HEIGHT);
	if (game->img.img == NULL)
		exit_with_err_msg(MALLOC_ERROR);
	game->img.data = (int *)mlx_get_data_addr(\
		game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
	init_texture(game);
}
