#include "../cub3d.h"

void	wall_init(t_game *game)
{
	game->wall.x = 0;
	game->wall.y = 0;
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

void	cart_init(t_game *game)
{
	int		i;
	int		j;

	game->tex.cart = malloc(sizeof(int *) * game->win.height);
	i = 0;
	while (i < game->win.height)
	{
		game->tex.cart[i] = malloc(sizeof(int) * game->win.width);
		i++;
	}
	i = 0;
	while (i < game->win.height)
	{
		j = 0;
		while (j < game->win.width)
		{
			game->tex.cart[i][j] = 0x000000;
			j++;
		}
		i++;
	}
}
