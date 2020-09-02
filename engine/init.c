#include "../cub3d.h"

void	game_init(t_game *game)
{
	int		i;

	i = 0;
	while (i < 300)
		game->key_check[i++] = 0;
	//game->map.columns = MAP_COLUMNS;
	//game->map.rows = MAP_ROWS;
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->win.width, game->win.height, "ModyHoon");
	game->tile_xsize = game->win.width / game->map.columns;
	game->tile_ysize = game->win.height / game->map.rows;
	game->seek_angle = 66;
	game->seek_distance = game->win.width / 3;
	game->ray_term = (1000 * 0.065) / game->win.width;
}

void	player_init(t_game *game)
{
	game->player.x = 9 * game->tile_xsize;
	game->player.y = 2 * game->tile_ysize;
	game->player.rot_angle = 180;
	game->player.move_speed = 10;
	game->player.rot_speed = 6;
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
	game->ray.angle = 0;
}



void	init(t_game *game)
{
	game_init(game);
	player_init(game);
	ray_init(game);
	wall_init(game);
	flag_init(game);
	sprite_init(game);
}
