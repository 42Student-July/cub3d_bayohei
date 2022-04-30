/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:44:25 by user42            #+#    #+#             */
/*   Updated: 2022/04/30 16:13:36 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

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
