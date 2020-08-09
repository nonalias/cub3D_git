#include "../cub3d.h"

void	make_player(t_game *game)
{
	int			x;

	game->img.data[to_coord(game, game->player.x / MINIMAP_RATIO, game->player.y / MINIMAP_RATIO)] = 0xff0000;
}
