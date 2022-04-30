/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:17:16 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/30 16:13:36 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "parser_bonus.h"

int	main(int argc, char *argv[])
{
	t_data	d;
	t_game	game;

	arg_check(argc, argv[1]);
	parse_file(&d, argv[1]);
	game.d = d;
	init(&game);
	render(&game);
	set_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
