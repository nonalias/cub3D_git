#include "../cub3d.h"

int		is_sprite(t_game *game)
{
	int		x;
	int		y;

	x = (int)(game->wall.x / game->tile_xsize);
	y = (int)(game->wall.y / game->tile_ysize);
	if (my_map[y][x] == 2)
		return (1);
	return (0);
}
