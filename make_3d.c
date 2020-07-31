#include "cub3d.h"

int		get_wall_distance(t_game *game)
{
	double	dx;
	double	dy;
	double	step;
dx = game->line.target_x - game->line.origin_x;
	dy = game->line.target_y - game->line.origin_y;
	step = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
	dx /= step;
	dy /= step;
	while (fabs(game->line.target_x - game->line.origin_x) > 1
			|| fabs(game->line.target_y - game->line.origin_y) > 1)
	{ if (check_wall(game, game->line.origin_x, game->line.origin_y))
		{
			dx = game->player.cur_x - game->line.origin_x;
			dy = game->player.cur_y - game->line.origin_y;
			return sqrt(dx * dx + dy * dy);
		}
		if (game->line.origin_x < 0 || game->line.origin_x >= game->win.width
				|| game->line.origin_y < 0 || game->line.origin_y >= game->win.height)
		{
			game->line.origin_x += dx;
			game->line.origin_y += dy;
			continue;
		}
		game->line.origin_x += dx;
		game->line.origin_y += dy;
	}
}

//TODO: rader도 seekangle부분 수정하기
void	make_3d(t_game *game)
{
	double	distance;
	double	wallheight;
	double	i;

	i = game->seek_angle / 2 * -1;
	while (i < game->seek_angle / 2)
	{ 
		game->line.origin_x = game->player.cur_x;
		game->line.origin_y = game->player.cur_y;
		game->line.target_x = game->player.cur_x + game->seek_distance * cos(M_PI / 180 * (game->player.rot_angle + i));
		game->line.target_y = game->player.cur_y + game->seek_distance * sin(M_PI / 180 * (game->player.rot_angle + i));
		distance = get_wall_distance(game);
		// if 24672 no show  (distance infinite)
		if (distance < 0 || distance > game->seek_distance)
		{
			i += 0.1;
			continue;
		}
		game->line.origin_x = ((i + game->seek_angle / 2) * game->win.width / game->seek_angle);
		game->line.origin_y = distance * 1.3;
		game->line.target_x = game->line.origin_x;
		game->line.target_y = game->win.width - distance * 1.3;
		if (distance < 200)
			game->line.color = 0xaaaaaa;
		else
			game->line.color = 0xaaaaaa - 0x0a0a0a;
		make_line(game);
		i += 0.1;
	}
}
