#include "cub3d.h"

void	init(t_game *game)
{
	int		i;

	i = 0;
	while (i < 300)
		game->key_check[i++] = 0;
	game->win.width = WIN_WIDTH;
	game->win.height = WIN_HEIGHT;
	game->map_xlength = MAP_XLENGTH;
	game->map_ylength = MAP_YLENGTH;
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->win.width, game->win.height, "ModyHoon");
	game->player.cur_x = game->win.width / 2;
	game->player.cur_y = game->win.height / 2;
	game->player.rot_angle = 0;
	game->player.rot_speed = 4;
	game->player.move_speed = 1;
}
