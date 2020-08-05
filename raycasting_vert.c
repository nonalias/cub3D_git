#include "cub3d.h"

double	raycasting_vert(t_game *game)
{
	double nextverttouchx;
	double nextverttouchy;

	game->ray.foundvertwallhit = 0;
	game->ray.down_facing = game->wall.angle > 0 && game->wall.angle < 180;
	game->ray.up_facing = !game->ray.down_facing;
	game->ray.right_facing = game->wall.angle < 90 || game->wall.angle > 270;
	game->ray.left_facing = !game->ray.right_facing;

	game->ray.xintercept = floor(game->player.cur_x / game->tile_xsize) * game->tile_xsize;
	game->ray.xintercept += game->ray.right_facing ? game->tile_xsize : 0;
	game->ray.yintercept = game->player.cur_y + (game->ray.xintercept - game->player.cur_x) * tan(TO_RADIAN(game->wall.angle));
	game->ray.xstep = game->tile_xsize;
	game->ray.xstep *= game->ray.left_facing ? -1 : 1;

	game->ray.ystep = game->tile_xsize * tan(TO_RADIAN(game->wall.angle));
	game->ray.ystep *= (game->ray.up_facing && game->ray.ystep > 0) ? -1 : 1;
	game->ray.ystep *= (game->ray.down_facing && game->ray.ystep < 0) ? -1 : 1;

	nextverttouchx = game->ray.xintercept;
	nextverttouchy = game->ray.yintercept;

	if (game->ray.left_facing)
		nextverttouchx -= 1;

	while (nextverttouchx >= 0 && nextverttouchx <= game->win.width && nextverttouchy >= 0 && nextverttouchy <= game->win.height)
	{
		if (check_wall(game, nextverttouchx, nextverttouchy))
		{
			game->ray.foundvertwallhit = 1;
			if (game->ray.left_facing)
				nextverttouchx += 1;
			game->ray.vertx = nextverttouchx;
			game->ray.verty = nextverttouchy;
			break;
		}
		else
		{
			nextverttouchx += game->ray.xstep;
			nextverttouchy += game->ray.ystep;
		}
	}
	return game->ray.foundvertwallhit ? (TWO_POINT_DISTANCE(game->player.cur_x, game->player.cur_y, game->ray.vertx, game->ray.verty)) : game->win.width * game->win.height;
}
