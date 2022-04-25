/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:07:57 by wyohei            #+#    #+#             */
/*   Updated: 2022/04/13 02:33:00 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static void	brainless_free(char	**str)
{
	free(*str);
	*str = NULL;
}

static size_t	check_n(char	*s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

static char	*get_line(char	*save_chr, char	**save)
{
	char	*tmp;
	char	*line;

	line = ft_sub(*save, 0, check_n(*save) + 1);
	if (line == NULL)
		return (NULL);
	tmp = ft_sub(*save, check_n(*save) + 1, ft_len(save_chr + 1));
	if (tmp == NULL)
	{
		brainless_free(&line);
		return (NULL);
	}
	brainless_free(save);
	*save = tmp;
	return (line);
}

static char	*join_line(int	fd, int	*read_size, char	**save, char	**buf)
{
	char	*save_chr;
	char	*tmp;

	*read_size = 1;
	while (*read_size > 0)
	{
		save_chr = ft_chr(*save, '\n');
		if (save_chr != NULL)
			return (get_line(save_chr, save));
		else
		{
			*read_size = read(fd, *buf, BUFFER_SIZE);
			if (*read_size == -1)
				return (NULL);
			(*buf)[*read_size] = '\0';
			tmp = ft_join(*save, *buf);
			if (tmp == NULL)
				return (NULL);
			brainless_free(save);
			*save = tmp;
		}
	}
	return (no_newline(save));
}

char	*get_next_line(int	fd)
{
	static char	*save;
	char		*buf;
	char		*line;
	int			read_size;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)xmalloc((size_t)BUFFER_SIZE + 1);
	if (save == NULL)
		save = ft_sub("", 0, 0);
	if (buf == NULL || save == NULL)
	{
		brainless_free(&save);
		brainless_free(&buf);
		return (NULL);
	}
	line = join_line(fd, &read_size, &save, &buf);
	brainless_free(&buf);
	if (line == NULL || read_size == -1 || read_size == 0)
	{
		brainless_free(&save);
		if (read_size == -1 || line == NULL)
			return (NULL);
	}
	return (line);
}
