#include "cub3d.h"

void	make_player(t_game *game)
{
	double		x;
	double		y;

	x = game->player.cur_x - 10;
	y = game->player.cur_y - 10;
	while (x < game->player.cur_x + 10)
	{
		//printf("x : %f\n", x);
		while (y < game->player.cur_y + 10)
		{
			game->img.data[to_coord(game, x, y)] = 0xff0000;
			y += 1;
		}
		x += 1;
	}
}
