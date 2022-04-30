/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:46:55 by user42            #+#    #+#             */
/*   Updated: 2022/04/30 16:14:01 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "cub3d_bonus.h"
#include "error_msg_bonus.h"
bool	is_map_char(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '1' || str[i] == '0' || str[i] == 'N' || str[i] == 'S' || \
		str[i] == 'E' || str[i] == 'W' || str[i] == ' ')
			i++;
		else
			return (false);
	}
	return (true);
}

bool	check_map_size(size_t col, size_t i, size_t row, t_data *d)
{
	if (col > MAX_SIZE || row > MAX_SIZE)
		return (false);
	d->map_start = i;
	d->col = col;
	d->row = row;
	if (d->col * TILE_SIZE * MINIMAP_SCALE > WIDTH / 2)
		exit_with_err_msg(TOO_BIG_MAP);
	if (d->row * TILE_SIZE * MINIMAP_SCALE > HEIGHT / 2)
		exit_with_err_msg(TOO_BIG_MAP);
	return (true);
}

size_t	player_count(char *line)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'W' || line[i] == 'E' || \
			line[i] == 'N' || line[i] == 'S')
			count++;
		i++;
	}
	return (count);
}

bool	check_map_contents(char **cub, size_t i, t_data *d)
{
	size_t	p_cnt;
	size_t	row;
	size_t	max_col;
	char	*line;

	row = 0;
	max_col = 0;
	p_cnt = 0;
	while (cub[i + row] != NULL)
	{
		line = del_newline(cub[i + row]);
		if (!is_map_char(line))
		{
			free(line);
			return (false);
		}
		if (max_col < ft_strlen(line))
			max_col = ft_strlen(line);
		p_cnt += player_count(line);
		free(line);
		row++;
	}
	if (p_cnt != 1)
		print_error(P_ERR);
	return (check_map_size(max_col, i, row, d));
}
