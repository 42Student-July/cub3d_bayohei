/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:51:05 by user42            #+#    #+#             */
/*   Updated: 2022/04/26 16:54:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

size_t	get_file_size(char *arg)
{
	char	*buf;
	int		fd;
	size_t	size;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		print_error(OPEN_ERR);
	size = 0;
	while (true)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			break ;
		free_null(&buf);
		size++;
	}
	free_null(&buf);
	close(fd);
	return (size);
}

char	**get_file_lines(char *arg)
{
	char	**ret;
	size_t	size;
	size_t	i;
	int		fd;

	size = get_file_size(arg);
	ret = (char **)xmalloc(sizeof(char *) * (size + 1));
	ret[size] = NULL;
	i = 0;
	fd = open(arg, O_RDONLY);
	while (i < size)
	{
		ret[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (ret);
}

char	**split_and_check_size(char *line, size_t size, char c)
{
	char	**sp;

	sp = ft_split(line, c);
	if (sp == NULL)
		print_error(MALLOC_ERR);
	if (double_ptr_size(sp) != size)
	{
		free_double_ptr(&sp);
		print_error(BAD_ELEMENT_ERR);
	}
	return (sp);
}

char	*del_newline(char *s)
{
	char	*ret;
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			break ;
		i++;
	}
	ret = ft_substr(s, 0, i);
	if (ret == NULL)
		print_error(MALLOC_ERR);
	return (ret);
}
