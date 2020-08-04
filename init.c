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
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->win.width, game->win.height, "ModyHoon");
	game->player.cur_x = game->win.width / 2;
	game->player.cur_y = game->win.height / 2;
	game->player.rot_angle = 0;
	game->player.rot_speed = 4;
	game->player.move_speed = 4;
	game->tile_xsize = game->win.width / game->map_xlength;
	game->tile_ysize = game->win.height / game->map_ylength;
	game->seek_angle = 66;
	game->seek_distance = game->win.width / 3;
	game->flags.debug = 0;
	game->flags.save = 0;
	game->wall.x = 0;
	game->wall.y = 0;
	game->wall.angle = 0;
	game->wall.distance = 0;
	game->wall.is_x_or_y = -1;
	
	game->ray.vertx = 0;
	game->ray.verty = 0;
	game->ray.horzx = 0;
	game->ray.horzy = 0;
	game->ray.xintercept = 0;
	game->ray.yintercept = 0;
	game->ray.xstep = 0;
	game->ray.ystep = 0;
	game->ray.foundhorzwallhit = 0;
	game->ray.foundvertwallhit = 0;
	game->ray.up_facing = 0;
	game->ray.down_facing = 0;
	game->ray.left_facing = 0;
	game->ray.right_facing = 0;
}
