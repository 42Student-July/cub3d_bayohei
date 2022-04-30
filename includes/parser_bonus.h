/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:01:13 by user42            #+#    #+#             */
/*   Updated: 2022/04/30 16:03:13 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_BONUS_H
# define PARSER_BONUS_H
# include "../lib/libft/libft.h"
# include "../lib/gnl/get_next_line.h"
# include <fcntl.h>
# include <errno.h> 
# include "stdbool.h"
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0
# define USAGE "usage  :./cub3d map_data"
# define ARG_ERROR_NULL "arg is null"
# define EXTENSION_ERROR "map name must be .cub"
# define ARG_DIR "arg is dir"
# define ACCESS_ERR "can not access"
# define READ_ERR "can not read"
# define OPEN_ERR "can not open"
# define MALLOC_ERR "malloc err"
# define FILE_ERR "File information is incorrect"
# define MLX_ERR "MLX ERR"
# define BAD_ELEMENT_ERR "bad element"
# define BAD_RBG "bad RBG"
# define NO_MAP "No map exists"
# define BAD_MAP "bad map"
# define P_ERR "too many players or no player"
# define CLOOR1 0
# define CLOOR2 1
# define CLOOR3 2
# define TEX_NO 0
# define TEX_SO 1
# define TEX_WE 2
# define TEX_EA 3
# define ALL_ELEMNT 6
# define CEIL 0
# define FLOOR 1

# define TAB 9
# define WHITESPASE 8
# define WALL 1
# define FLR 0
# define NORTH 2
# define SOUTH 3
# define WEST 4
# define EAST 5
# define END 999
# define OK 6

# define MAX_SIZE 100

typedef struct s_check
{
	bool	no;
	bool	so;
	bool	we;
	bool	ea;
	bool	f;
	bool	c;
	bool	ok;
	int		cnt;
}	t_check;

typedef struct s_data
{
	int		color[2];
	char	*tex[4];
	size_t	map_start;
	size_t	col;
	size_t	row;
	int		**map;
}	t_data;

void	print_error(char *err);
void	arg_check(int ac, char *av);
void	parse_file(t_data *d, char *arg);
void	free_null(char **str);
size_t	get_file_size(char *arg);
void	*xmalloc(size_t size);
void	free_double_ptr(char ***str);
size_t	double_ptr_size(char **str);
char	*ft_xstrdup(char *str);
bool	check_exist(char *str);
bool	parse_color(t_data *d, char *line, int c_f);
bool	is_spaces(char *str);
char	**split_and_check_size(char *line, size_t size, char c);
char	*del_newline(char *s);
bool	load_texture(t_data *d, char *line, int tex);
char	**get_file_lines(char *arg);
void	free_double_ptr_int(int ***index);
void	dfs2(int h, int w, int **memo, bool *check);
size_t	array_len(int *arr);
bool	dfs_map(t_data *d);
bool	check_element(t_data *d, char **cub, size_t *i);
bool	check_map_contents(char **cub, size_t i, t_data *d);
bool	get_map(char **cub, size_t i, t_data *d);
#endif
