#include "cub3d.h"

void	make_rader_line(t_game *game)
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
	{
		if (check_wall(game, game->line.origin_x, game->line.origin_y))
			break ;
		if (game->line.origin_x < 0 || game->line.origin_x >= game->win.width
				|| game->line.origin_y < 0 || game->line.origin_y >= game->win.height)
		{
			game->line.origin_x += dx;
			game->line.origin_y += dy;
			continue;
		}
		game->img.data[to_coord(game, game->line.origin_x, game->line.origin_y)] = game->line.color;
		game->line.origin_x += dx;
		game->line.origin_y += dy;
	}
}

void	make_rader(t_game *game)
{
	double		i;

	i = game->seek_angle / 2 * -1;
	while (i < game->seek_angle / 2)
	{
		game->line.origin_x = game->player.cur_x;
		game->line.origin_y = game->player.cur_y;
		game->line.target_x = game->player.cur_x + game->seek_distance * cos(M_PI / 180 * (game->player.rot_angle + i));
		game->line.target_y = game->player.cur_y + game->seek_distance * sin(M_PI / 180 * (game->player.rot_angle + i));
		game->line.color = 0x0000a1;
		make_rader_line(game);
		i += 0.05;
	}
}
