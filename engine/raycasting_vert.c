#include "../cub3d.h"

void	raycasting_vert2(t_game *game)
{
	game->ray.nextverttouchx = game->ray.xintercept;
	game->ray.nextverttouchy = game->ray.yintercept;
	if (game->ray.left_facing)
		game->ray.nextverttouchx -= 1;
	while (game->ray.nextverttouchx >= 0
			&& game->ray.nextverttouchx <= game->win.width
			&& game->ray.nextverttouchy >= 0
			&& game->ray.nextverttouchy <= game->win.height)
	{
		if (check_wall(game, game->ray.nextverttouchx, game->ray.nextverttouchy))
		{
			game->ray.foundvertwallhit = 1;
			if (game->ray.left_facing)
				game->ray.nextverttouchx += 1;
			game->ray.vertx = game->ray.nextverttouchx;
			game->ray.verty = game->ray.nextverttouchy;
			break;
		}
		else
		{
			game->ray.nextverttouchx += game->ray.xstep;
			game->ray.nextverttouchy += game->ray.ystep;
		}
	}
}

double	raycasting_vert(t_game *game)
{
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
	raycasting_vert2(game);
	return game->ray.foundvertwallhit
		? (TWO_POINT_DISTANCE(game->player.cur_x,
					game->player.cur_y,
					game->ray.vertx,
					game->ray.verty))
		: game->win.width * game->win.height;
}
