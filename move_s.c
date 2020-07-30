#include "cub3d.h"

void	move_s_a(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.cur_x - game->player.move_speed * cos(M_PI / 180 * (game->player.rot_angle + 45));
	new_y = game->player.cur_y - game->player.move_speed * csin(M_PI / 180 * (game->player.rot_angle + 45));
	if (!checkwall(new_x, new_y))
	{
		game->player.cur_x = new_x;
		game->player.cur_y = new_y;
	}
}

void	move_s_d(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.cur_x - game->player.move_speed * cos(M_PI / 180 * (game->player.rot_angle - 45));
	new_y = game->player.cur_y - game->player.move_speed * csin(M_PI / 180 * (game->player.rot_angle - 45));
	if (!checkwall(new_x, new_y))
	{
		game->player.cur_x = new_x;
		game->player.cur_y = new_y;
	}
}

void	move_s(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.cur_x - game->player.move_speed * cos(M_PI / 180 * (game->player.rot_angle));
	new_y = game->player.cur_y - game->player.move_speed * csin(M_PI / 180 * (game->player.rot_angle));
	if (!checkwall(new_x, new_y))
	{
		game->player.cur_x = new_x;
		game->player.cur_y = new_y;
	}
}
