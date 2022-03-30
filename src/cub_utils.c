/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:38:10 by mhirabay          #+#    #+#             */
/*   Updated: 2022/03/30 17:52:11 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	to_coord(double x, double y)
{
	long long ret;
	ret = (int)floor(y) * WIDTH + (int)floor(x);
	// printf("ret = %lld\n", ret);
	return (ret);
}
