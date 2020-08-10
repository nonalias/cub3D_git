#include "../cub3d.h"

void	move_a(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x + game->player.move_speed * sin(TO_RADIAN(game->player.rot_angle));
	new_y = game->player.y - game->player.move_speed * cos(TO_RADIAN(game->player.rot_angle));
	if (!check_wall(game, new_x, new_y))
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}
