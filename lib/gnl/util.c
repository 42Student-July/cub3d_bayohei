/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 09:32:06 by user42            #+#    #+#             */
/*   Updated: 2022/04/30 09:36:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	print_error(char *err)
{
	printf("Error\n");
	printf("%s\n", err);
	exit(EXIT_FAILURE);
}

void	*xmalloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (ret == NULL)
		print_error("malloc err");
	return (ret);
}
