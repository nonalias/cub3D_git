#include "cub3d.h"

int		check_wall(t_game * game, double x, double y)
{
	double	coord_x;
	double	coord_y;

	coord_x = x / (game->win.width / game->map_xlength);
	coord_y = y / (game->win.height / game->map_ylength);
	if (map[(int)coord_x][(int)coord_y] == 1)
		return (1);
	return (0);
}
