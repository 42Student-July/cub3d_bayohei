/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:07:53 by wyohei            #+#    #+#             */
/*   Updated: 2022/04/13 02:32:33 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
size_t	ft_len(const char	*s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_join(char const	*s1, char const	*s2)
{
	char	*str;
	size_t	total;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	total = ft_len(s1) + ft_len(s2);
	str = (char *)xmalloc(total + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_sub(char const	*s, size_t	start, size_t	len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	str = (char *)xmalloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0' && i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	*ft_chr(const char	*s, int	c)
{
	char	charr;
	size_t	i;

	i = 0;
	charr = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == charr)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*no_newline(char	**save)
{
	char	*line;

	if (**save == '\0')
		return (NULL);
	line = ft_sub(*save, 0, ft_len(*save));
	if (line == NULL)
		return (NULL);
	return (line);
}
