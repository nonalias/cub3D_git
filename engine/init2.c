#include "../cub3d.h"

void	wall_init(t_game *game)
{
	game->wall.x = 0; game->wall.y = 0;
	game->wall.angle = 0;
	game->wall.distance = 0;
	game->wall.what_hit = -1;
	game->wall.cardinal = -1;
	game->wall.realheight = 0;
}

void	flag_init(t_game *game)
{
	game->flags.debug = 0;
	game->flags.save = 0;
}

t_pos	find_sprite(t_game *game)
{
	int		i;
	int		j;
	t_pos	pos;

	i = 0;
	while (i < game->map.ylength)
	{
		j = 0;
		while (j < game->map.xlength)
		{
			if (my_map[i][j] == 2)
			{
				set_pos(&pos, j, i);
				return pos;
			}
			j++;
		}
		i++;
	}
}

void	sprite_init(t_game *game)
{
	t_pos	pos;

	pos = find_sprite(game);
	game->spr.x = (int)pos.x * game->tile_xsize + game->tile_xsize / 2;
	game->spr.y = (int)pos.y * game->tile_ysize + game->tile_ysize / 2;
	game->spr.angle = 0;
	game->spr.distance = 0;
}
