/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:38:10 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/30 16:13:22 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	to_coord_minimap(double x, double y)
{
	long long	ret;
	long long	x_conv;
	long long	y_conv;

	x_conv = floor(x * MINIMAP_SCALE);
	y_conv = floor(y * MINIMAP_SCALE);
	ret = y_conv * WIDTH + x_conv;
	return (ret);
}

int	to_coord(double x, double y)
{
	long long	ret;
	long long	x_conv;
	long long	y_conv;

	x_conv = floor(x);
	y_conv = floor(y);
	ret = y_conv * WIDTH + x_conv;
	return (ret);
}

int	to_coord_tex(double x, double y)
{
	long long	ret;
	long long	x_conv;
	long long	y_conv;

	x_conv = floor(x);
	y_conv = floor(y);
	ret = y_conv * TEXTURE_WIDTH + x_conv;
	return (ret);
}
