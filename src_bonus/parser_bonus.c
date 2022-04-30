/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:56:25 by user42            #+#    #+#             */
/*   Updated: 2022/04/26 16:56:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	parse_file(t_data *d, char *arg)
{
	char	**parsed_cub;
	size_t	map_start;

	map_start = 0;
	parsed_cub = get_file_lines(arg);
	if (!check_element(d, parsed_cub, &map_start))
		print_error(FILE_ERR);
	if (!get_map(parsed_cub, map_start, d))
		print_error(BAD_MAP);
	free_double_ptr(&parsed_cub);
	if (!dfs_map(d))
		print_error(BAD_MAP);
}
