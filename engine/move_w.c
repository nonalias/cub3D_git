#include "../cub3d.h"

void	move_w_a(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x + game->player.move_speed * cos(TO_RADIAN(game->player.rot_angle - 45));
	new_y = game->player.y + game->player.move_speed * sin(TO_RADIAN(game->player.rot_angle - 45));
	if (!check_wall(game, new_x, new_y)
			&& new_x < game->win.width
			&& new_y < game->win.height
			&& new_x >= 0 && new_y >= 0)
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}

void	move_w_d(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x + game->player.move_speed * cos(TO_RADIAN(game->player.rot_angle + 45));
	new_y = game->player.y + game->player.move_speed * sin(TO_RADIAN(game->player.rot_angle + 45));
	if (!check_wall(game, new_x, new_y)
			&& new_x < game->win.width
			&& new_y < game->win.height
			&& new_x >= 0 && new_y >= 0)
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}

void	move_w(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x + game->player.move_speed * cos(TO_RADIAN(game->player.rot_angle));
	new_y = game->player.y + game->player.move_speed * sin(TO_RADIAN(game->player.rot_angle));
	if (!check_wall(game, new_x, new_y)
			&& new_x < game->win.width
			&& new_y < game->win.height
			&& new_x >= 0 && new_y >= 0)
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}
