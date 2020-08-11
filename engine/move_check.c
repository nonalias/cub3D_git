#include "../cub3d.h"

int		move_check(t_game *game)
{
	double	angle;
	t_pos	pos;

	angle = 0;
	pos.x = game->player.x;
	pos.y = game->player.y;
	while (angle < 360)
	{
		if (check_wall(game,
					pos.x + 10 * cos(TO_RADIAN(angle)),
					pos.y + 10 * sin(TO_RADIAN(angle))))
			return (0);
		angle += 0.5;
	}
	return (1);
}
