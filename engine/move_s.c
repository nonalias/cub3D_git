#include "../cub3d.h"

void	move_s_a(t_game *game)
{
	double	new_x;
	double	new_y;
	double	wall_check_x;
	double	wall_check_y;

	new_x = game->player.x - game->player.move_speed * cos(TO_RADIAN((game->player.rot_angle + 45)));
	new_y = game->player.y - game->player.move_speed * sin(TO_RADIAN((game->player.rot_angle + 45)));
	wall_check_x = game->player.x - WALL_BOUNDARY * cos(TO_RADIAN((game->player.rot_angle + 45)));
	wall_check_y = game->player.y - WALL_BOUNDARY * sin(TO_RADIAN((game->player.rot_angle + 45)));
	if (!check_wall(game, wall_check_x, wall_check_y))
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}

void	move_s_d(t_game *game)
{
	double	new_x;
	double	new_y;
	double	wall_check_x;
	double	wall_check_y;

	new_x = game->player.x - game->player.move_speed * cos(TO_RADIAN((game->player.rot_angle - 45)));
	new_y = game->player.y - game->player.move_speed * sin(TO_RADIAN((game->player.rot_angle - 45)));
	wall_check_x = game->player.x - WALL_BOUNDARY * cos(TO_RADIAN((game->player.rot_angle - 45)));
	wall_check_y = game->player.y - WALL_BOUNDARY * sin(TO_RADIAN((game->player.rot_angle - 45)));
	if (!check_wall(game, wall_check_x, wall_check_y))
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}

void	move_s(t_game *game)
{
	double	new_x;
	double	new_y;
	double	wall_check_x;
	double	wall_check_y;

	new_x = game->player.x - game->player.move_speed * cos(TO_RADIAN((game->player.rot_angle)));
	new_y = game->player.y - game->player.move_speed * sin(TO_RADIAN((game->player.rot_angle)));
	wall_check_x = game->player.x - WALL_BOUNDARY * cos(TO_RADIAN((game->player.rot_angle)));
	wall_check_y = game->player.y - WALL_BOUNDARY * sin(TO_RADIAN((game->player.rot_angle)));
	if (!check_wall(game, wall_check_x, wall_check_y))
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}
