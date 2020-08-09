#include "../cub3d.h"

void	make_player(t_game *game)
{
	int			x;

	game->img.data[to_coord(game, game->player.cur_x / MINIMAP_RATIO, game->player.cur_y / MINIMAP_RATIO)] = 0xff0000;
}
