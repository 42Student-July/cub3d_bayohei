/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:08:01 by wyohei            #+#    #+#             */
/*   Updated: 2022/04/25 15:33:47 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdio.h>
# include "../../includes/parser.h"
# define BUFFER_SIZE 42

size_t	ft_len(const char *s);
char	*ft_sub(char const *s, size_t start, size_t len);
char	*ft_join(char const *s1, char const *s2);
char	*ft_chr(const char *s, int c);
char	*get_next_line(int fd);
char	*no_newline(char **save);
#endif
