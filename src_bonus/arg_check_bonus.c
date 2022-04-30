/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:57:55 by user42            #+#    #+#             */
/*   Updated: 2022/04/30 16:13:36 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
bool	check_extension(char *arg)
{
	size_t	arg_len;

	arg_len = ft_strlen(arg);
	if (arg_len < 4 || \
	ft_memcmp(arg + arg_len - 4, ".cub", 4) != 0)
		return (false);
	return (true);
}

bool	check_exist(char *str)
{
	int		fd;
	char	buf[1];

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (false);
	if (read(fd, buf, 1) == -1)
	{
		if (errno == EISDIR)
			print_error(ARG_DIR);
		else
			print_error(READ_ERR);
	}
	close(fd);
	return (true);
}

void	arg_check(int ac, char *arg)
{
	if (ac != 2)
		print_error(USAGE);
	if (arg == NULL || arg[0] == '\0')
		print_error(ARG_ERROR_NULL);
	if (!check_extension(arg))
		print_error(EXTENSION_ERROR);
	if (!check_exist(arg))
		print_error(ACCESS_ERR);
}
