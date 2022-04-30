/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_color_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:47:47 by user42            #+#    #+#             */
/*   Updated: 2022/04/30 16:13:36 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
int	color_atoi(char *str)
{
	int		ret;
	size_t	i;

	if (ft_strlen(str) > 3)
		print_error(BAD_RBG);
	if (str[0] == '0' && str[1] != '\0')
		print_error(BAD_RBG);
	i = 0;
	ret = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			print_error(BAD_RBG);
		ret = ret * 10 + str[i] - '0';
		if (ret > 255)
			print_error(BAD_RBG);
		i++;
	}
	return (ret);
}

int	fusion_color(int *colors)
{
	int	color;

	color = 0;
	color += colors[2] << 16;
	color += colors[1] << 8;
	color += colors[0];
	return (color);
}

size_t	count_comma(char *str)
{
	size_t	cnt;
	size_t	i;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			cnt++;
		i++;
	}
	return (cnt);
}

bool	parse_color(t_data *d, char *line, int c_f)
{
	char	**sp;
	char	**pars_RGB;
	char	*str;
	int		colors[3];
	int		i;

	sp = split_and_check_size(line, 2, ' ');
	str = del_newline(sp[1]);
	if (count_comma(str) != 2)
		print_error(BAD_ELEMENT_ERR);
	pars_RGB = split_and_check_size(str, 3, ',');
	free_double_ptr(&sp);
	free(str);
	i = -1;
	while (pars_RGB[++i] != NULL)
		colors[i] = color_atoi(pars_RGB[i]);
	d->color[c_f] = fusion_color(colors);
	free_double_ptr(&pars_RGB);
	return (true);
}
