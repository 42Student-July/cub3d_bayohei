/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:44:03 by user42            #+#    #+#             */
/*   Updated: 2022/04/26 16:44:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
