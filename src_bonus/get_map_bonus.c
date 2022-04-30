/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:12:51 by user42            #+#    #+#             */
/*   Updated: 2022/04/26 16:43:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
int	char_to_int(char c)
{
	int	ret;

	ret = 0;
	if (c == '1')
		ret = WALL;
	else if (c == '0')
		ret = FLR;
	else if (c == 'N')
		ret = NORTH;
	else if (c == 'S')
		ret = SOUTH;
	else if (c == 'W')
		ret = WEST;
	else if (c == 'E')
		ret = EAST;
	else if (c == ' ')
		ret = WHITESPASE;
	return (ret);
}

int	*charline_to_intline(char *line, size_t size)
{
	int		*ret;
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	ret = (int *)xmalloc(sizeof(int) * (size + 1));
	ret[size] = END;
	while (line[i] != '\0')
	{
		if (line[i] == TAB)
		{
			ret[j] = TAB;
			ret[++j] = TAB;
			ret[++j] = TAB;
			ret[++j] = TAB;
			i++;
			j++;
			continue ;
		}
		ret[j] = char_to_int(line[i]);
		i++;
		j++;
	}
	return (ret);
}

size_t	line_size(char *line)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	while (line[i] != '\0')
	{
		if (line[i] == TAB)
			size += 4;
		else
			size++;
		i++;
	}
	return (size);
}

bool	store_map(char **cub, size_t i, t_data *d)
{
	size_t	j;
	size_t	start;
	size_t	size;
	char	*line;

	if (!check_map_contents(cub, i, d))
		return (false);
	start = d->map_start;
	j = 0;
	d->map = (int **)xmalloc(sizeof(int *) * (d->row + 1));
	d->map[d->row] = NULL;
	while (cub[start] != NULL)
	{
		line = del_newline(cub[start]);
		size = line_size(line);
		d->map[j] = charline_to_intline(line, size);
		free(line);
		start++;
		j++;
	}
	return (true);
}

bool	get_map(char **cub, size_t i, t_data *d)
{
	i++;
	if (cub[i] == NULL)
		print_error(NO_MAP);
	while (cub[i] != NULL)
	{
		if (!is_spaces(cub[i]))
			break ;
		i++;
	}
	if (cub[i] != NULL)
		return (store_map(cub, i, d));
	else
		return (false);
}
