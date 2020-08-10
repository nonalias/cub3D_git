#include "../cub3d.h"

void	make_rectangle(t_game *game, t_pos pos[2], int color)
{
	double	movex;

	while (pos[0].y < pos[1].y)
	{
		movex = pos[0].x;
		while (movex < pos[1].x)
		{
			game->img.data[to_coord(game, movex, pos[0].y)] = color;
			movex += 1;
		}
		pos[0].y += 1;
	}
}
