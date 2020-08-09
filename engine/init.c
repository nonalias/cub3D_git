#include "../cub3d.h"

void	win_init(t_game *game)
{
	game->win.width = WIN_WIDTH;
	game->win.height = WIN_HEIGHT;
}

void	game_init(t_game *game)
{
	int		i;

	i = 0;
	while (i < 300)
		game->key_check[i++] = 0;
	game->map.xlength = MAP_XLENGTH;
	game->map.ylength = MAP_YLENGTH;
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->win.width, game->win.height, "ModyHoon");
	game->tile_xsize = game->win.width / game->map.xlength;
	game->tile_ysize = game->win.height / game->map.ylength;
	game->seek_angle = 66;
	game->seek_distance = game->win.width / 3;
}

void	player_init(t_game *game)
{
	game->player.x = game->win.width / 2;
	game->player.y = game->win.height / 2;
	game->player.rot_angle = 0;
	game->player.rot_speed = 4;
	game->player.move_speed = 4;
}

void	ray_init(t_game *game)
{
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
	game->ray.nexthorztouchx = 0;
	game->ray.nexthorztouchy = 0;
	game->ray.nextverttouchx = 0;
	game->ray.nextverttouchy = 0;
}

void	init(t_game *game)
{
	win_init(game);
	game_init(game);
	player_init(game);
	ray_init(game);
	wall_init(game);
	flag_init(game);
}
