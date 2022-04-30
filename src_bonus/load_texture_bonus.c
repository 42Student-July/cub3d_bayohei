/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:44:25 by user42            #+#    #+#             */
/*   Updated: 2022/04/26 16:45:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	load_texture(t_data *d, char *line, int tex)
{
	char	*str;
	char	**sp;

	sp = split_and_check_size(line, 2, ' ');
	str = del_newline(sp[1]);
	if (!check_exist(str))
		print_error(BAD_ELEMENT_ERR);
	d->tex[tex] = ft_xstrdup(str);
	free(str);
	free_double_ptr(&sp);
	return (true);
}
