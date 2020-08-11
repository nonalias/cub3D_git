#include "../cub3d.h"

void	reset_player(t_game *game)
{
	game->player.x = game->win.width / 2;
	game->player.y = game->win.height / 2;
	game->player.rot_angle = 0;
}
