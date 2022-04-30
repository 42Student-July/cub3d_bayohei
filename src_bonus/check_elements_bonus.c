/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:00:37 by user42            #+#    #+#             */
/*   Updated: 2022/04/30 16:13:36 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
void	check_count_element2(t_check *e, char *line)
{
	if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (e->ea == true)
			print_error(BAD_ELEMENT_ERR);
		e->ea = true;
	}
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (e->f == true)
			print_error(BAD_ELEMENT_ERR);
		e->f = true;
	}
	if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (e->c == true)
			print_error(BAD_ELEMENT_ERR);
		e->c = true;
	}
	if (e->ea && e->f && e->c && e->we && e->so && e->no)
		e->ok = true;
}

void	check_count_element(t_check *e, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (e->no == true)
			print_error(BAD_ELEMENT_ERR);
		e->no = true;
	}
	if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (e->so == true)
			print_error(BAD_ELEMENT_ERR);
		e->so = true;
	}
	if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (e->we == true)
			print_error(BAD_ELEMENT_ERR);
		e->we = true;
	}
	check_count_element2(e, line);
}

bool	check_acronym(t_data *d, char *line, t_check *e)
{
	check_count_element(e, line);
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (load_texture(d, line, TEX_NO));
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (load_texture(d, line, TEX_SO));
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (load_texture(d, line, TEX_WE));
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (load_texture(d, line, TEX_EA));
	if (ft_strncmp(line, "F ", 2) == 0)
		return (parse_color(d, line, FLOOR));
	if (ft_strncmp(line, "C ", 2) == 0)
		return (parse_color(d, line, CEIL));
	return (false);
}

void	check_init(t_check *elements)
{
	elements->f = false;
	elements->c = false;
	elements->ok = false;
	elements->no = false;
	elements->so = false;
	elements->we = false;
	elements->ea = false;
	elements->cnt = 0;
}

bool	check_element(t_data *d, char **cub, size_t *i)
{
	t_check	elements;

	check_init(&elements);
	while (cub[*i] != NULL)
	{
		if (is_spaces(cub[*i]))
		{
			(*i)++;
			continue ;
		}
		if (check_acronym(d, cub[*i], &elements))
		{
			elements.cnt++;
			if (elements.cnt == ALL_ELEMNT && elements.ok)
				return (true);
		}
		else
			print_error(FILE_ERR);
		(*i)++;
	}
	return (false);
}
