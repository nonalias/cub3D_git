#include "../cub3d.h"

void	make_ceil(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->win.width)
	{
		game->line.origin_x = i;
		game->line.origin_y = 0;
		game->line.target_x = i;
		game->line.target_y = game->win.height / 2;
		game->line.color = 0x50bcdf;
		make_line(game);
		i++;
	}
}
