/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_util_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:44:03 by user42            #+#    #+#             */
/*   Updated: 2022/04/30 16:13:36 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

void	*xmalloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (ret == NULL)
		print_error(MALLOC_ERR);
	return (ret);
}

char	*ft_xstrdup(char *str)
{
	char	*s;

	s = ft_strdup(str);
	if (s == NULL)
		print_error(MALLOC_ERR);
	return (s);
}
