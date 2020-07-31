#include "cub3d.h"
/*
int		my_map[11][11] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1},
	{1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};
*/

int		to_coord(t_game *game, double x, double y)
{
	return (int)y * game->win.width + (int)x;
}

void	make_line(t_game *game)
{
	double	dx;
	double	dy;
	double	step;
	
	dx = game->line.target_x - game->line.origin_x;
	dy = game->line.target_y - game->line.origin_y;
	step = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
	dx /= step;
	dy /= step;
	while (fabs(game->line.target_x - game->line.origin_x) > 1
			|| fabs(game->line.target_y - game->line.origin_y) > 1)
	{
		if (game->line.origin_x < 0 || game->line.origin_x >= game->win.width
				|| game->line.origin_y < 0 || game->line.origin_y >= game->win.height)
		{
			game->line.origin_x += dx;
			game->line.origin_y += dy;
			continue;
		}
	//	mlx_pixel_put(game->mlx_ptr, game->win_ptr, (int)game->line.origin_x, (int)game->line.origin_y, game->line.color);
		game->img.data[to_coord(game, game->line.origin_x, game->line.origin_y)] = game->line.color;
		game->line.origin_x += dx;
		game->line.origin_y += dy;
	}
}

void	map_print(t_game *game)
{
	int		i;
	int		j;

	printf("\n");
	i = 0;
	while (i < game->map_xlength)
	{
		j = 0;
		while (j < game->map_ylength)
		{
			printf("%d ", my_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

void	make_tile(t_game *game, int i, int j, int color)
{
	int		k;
	int		u;

	k = 0;
	//map_print(game);
	while (k < game->tile_xsize)
	{
		game->line.origin_x = j * game->tile_xsize + k;
		game->line.target_x = j * game->tile_xsize + k;
		game->line.origin_y = i * game->tile_ysize;
		game->line.target_y = (i + 1)* game->tile_ysize + 1;
		game->line.color = color;
		make_line(game);
		k++;
	}
}

void	make_2d(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map_xlength)
	{
		j = 0;
		while (j < game->map_ylength)
		{
			if (my_map[i][j] == 1)
				make_tile(game, i, j, COLOR_WALL);
			else
				make_tile(game, i, j, COLOR_ROAD);
			j++;
		}
		i++;
	}
}