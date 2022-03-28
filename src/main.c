#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "../lib/mlx/mlx.h"

#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_EXIT 17

# define KEY_ESC 53

# define TILE_SIZE 32

# define ROWS 11
# define COLS 15
# define WIDTH COLS * TILE_SIZE
# define HEIGHT ROWS * TILE_SIZE

# define TO_COORD(X, Y) ((int)floor(Y) * WIDTH + (int)floor(X))


typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	
	int		map[ROWS][COLS];
}	t_game;

void	game_init(t_game *game)
{	
	int map[ROWS][COLS] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	memcpy(game->map, map, sizeof(int) * ROWS * COLS);
}


void	draw_lines(t_game *game)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < COLS)
	{
		draw_line(
			
			
			
			
			
			
			
			
			
			
			
			
		)
	}
	
}


void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "mlx_42");
}

void	img_init(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
}


void	draw_rectangle(t_game *game, int x, int y)
{
	int i;
	int j;
	
	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0; 
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			// TILEサイズの左上から全部1pixelずつなぞっていく
			game->img.data[(y + i) * WIDTH + x + j] = 0xFFFFFF;
			j++;
		}
		i++;
	}
	
}


void	draw_rectangles(t_game *game)
{
	int	i;
	int	j;
	
	while (i < ROWS)
	{
		while (j < COLS)
		{
			if (game->map[i][j] == 1)
				draw_rectangle(game, j, i);
			j++;
		}
		i++;
	}
	
}

int	main_loop(t_game *game)
{
	draw_rectangles(game);
	draw_lines(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

int	main()
{
	t_game	game;
	
	game_init(&game);
	window_init(&game);
	img_init(&game);
	
	mlx_loop_hook(game.mlx, &main_loop, &game);
	return (0);
}
