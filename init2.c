#include "cub3d.h"

void	wall_init(t_game *game)
{
	game->wall.x = 0;
	game->wall.y = 0;
	game->wall.angle = 0;
	game->wall.distance = 0;
	game->wall.is_x_or_y = -1;
}

void	flag_init(t_game *game)
{
	game->flags.debug = 0;
	game->flags.save = 0;
}
