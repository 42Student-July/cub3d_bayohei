/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:27:01 by mhirabay          #+#    #+#             */
/*   Updated: 2022/04/30 16:13:22 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	*get_data_addr(t_img *i)
{
	return ((int *)mlx_get_data_addr(i->img, &i->bpp, &i->size_l, &i->endian));
}
