#include "cub3d.h"

void	move_d(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.cur_x - game->player.move_speed * sin(TO_RADIAN(game->player.rot_angle));
	new_y = game->player.cur_y + game->player.move_speed * cos(TO_RADIAN(game->player.rot_angle));
	if (!check_wall(game, new_x, new_y))
	{
		game->player.cur_x = new_x;
		game->player.cur_y = new_y;
	}
}
