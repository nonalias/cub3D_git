#include "cub3d.h"

double	raycasting_horz(t_game *game)
{
	double	nexthorztouchx;
	double	nexthorztouchy;

	game->ray.foundhorzwallhit = 0;
	game->ray.down_facing = game->wall.angle > 0 && game->wall.angle < 180;
	game->ray.up_facing = !game->ray.down_facing;
	game->ray.left_facing = game->wall.angle > 90 && game->wall.angle < 270;
	game->ray.right_facing = !game->ray.left_facing;

	game->ray.yintercept = floor(game->player.cur_y / game->tile_ysize) * game->tile_ysize;
	if (game->ray.down_facing)
		game->ray.yintercept += game->tile_ysize;
	game->ray.xintercept = game->player.cur_x + (game->ray.yintercept - game->player.cur_y) / tan(TO_RADIAN(game->wall.angle));

	game->ray.ystep = game->tile_ysize;
	if (game->ray.up_facing)
		game->ray.ystep *= -1;

	game->ray.xstep = game->tile_ysize / tan(TO_RADIAN(game->wall.angle));
	game->ray.xstep *= (game->ray.left_facing && game->ray.xstep > 0) ? -1 : 1;
	game->ray.xstep *= (game->ray.right_facing && game->ray.xstep < 0) ? -1 : 1;

	nexthorztouchx = game->ray.xintercept;
	nexthorztouchy = game->ray.yintercept;

	if (game->ray.up_facing)
		nexthorztouchy -= 1;
	while (nexthorztouchx >= 0 && nexthorztouchx <= game->win.width && nexthorztouchy >= 0 && nexthorztouchy <= game->win.height)
	{
		if (check_wall(game, nexthorztouchx, nexthorztouchy))
		{
			game->ray.foundhorzwallhit = 1;
			game->ray.horzx = nexthorztouchx;
			if (game->ray.up_facing)
				nexthorztouchy += 1;
			game->ray.horzy = nexthorztouchy;
			break;
		}
		else
		{
			nexthorztouchx += game->ray.xstep;
			nexthorztouchy += game->ray.ystep;
		}
	}
	return game->ray.foundhorzwallhit ? (TWO_POINT_DISTANCE(game->player.cur_x, game->player.cur_y, game->ray.horzx, game->ray.horzy)) : game->win.width * game->win.height;
}
