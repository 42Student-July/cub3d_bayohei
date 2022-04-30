/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_util2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:54:33 by user42            #+#    #+#             */
/*   Updated: 2022/04/30 16:13:36 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

size_t	double_ptr_size(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

bool	is_spaces(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') \
		|| (str[i] == '\v') || (str[i] == '\r') || (str[i] == '\f'))
			i++;
		else
			return (false);
	}
	return (true);
}

size_t	array_len(int *arr)
{
	size_t	i;

	i = 0;
	while (arr[i] != END)
		i++;
	return (i);
}
