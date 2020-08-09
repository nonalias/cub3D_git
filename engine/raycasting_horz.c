#include "../cub3d.h"

void	raycasting_horz2(t_game *game)
{
	game->ray.nexthorztouchx = game->ray.xintercept;
	game->ray.nexthorztouchy = game->ray.yintercept;
	if (game->ray.up_facing)
		game->ray.nexthorztouchy -= 1;
	while (game->ray.nexthorztouchx >= 0
			&& game->ray.nexthorztouchx <= game->win.width
			&& game->ray.nexthorztouchy >= 0
			&& game->ray.nexthorztouchy <= game->win.height)
	{
		if (check_wall(game, game->ray.nexthorztouchx, game->ray.nexthorztouchy))
		{
			game->ray.foundhorzwallhit = 1;
			game->ray.horzx = game->ray.nexthorztouchx;
			if (game->ray.up_facing)
				game->ray.nexthorztouchy += 1;
			game->ray.horzy = game->ray.nexthorztouchy;
			break;
		}
		else
		{
			game->ray.nexthorztouchx += game->ray.xstep;
			game->ray.nexthorztouchy += game->ray.ystep;
		}
	}
}

double	raycasting_horz(t_game *game)
{
	game->ray.foundhorzwallhit = 0;
	game->ray.down_facing = game->wall.angle > 0 && game->wall.angle < 180;
	game->ray.up_facing = !game->ray.down_facing;
	game->ray.left_facing = game->wall.angle > 90 && game->wall.angle < 270;
	game->ray.right_facing = !game->ray.left_facing;
	game->ray.yintercept = floor(game->player.y / game->tile_ysize) * game->tile_ysize;
	if (game->ray.down_facing)
		game->ray.yintercept += game->tile_ysize;
	game->ray.xintercept = game->player.x + (game->ray.yintercept - game->player.y) / tan(TO_RADIAN(game->wall.angle));
	game->ray.ystep = game->tile_ysize;
	if (game->ray.up_facing)
		game->ray.ystep *= -1;
	game->ray.xstep = game->tile_ysize / tan(TO_RADIAN(game->wall.angle));
	game->ray.xstep *= (game->ray.left_facing && game->ray.xstep > 0) ? -1 : 1;
	game->ray.xstep *= (game->ray.right_facing && game->ray.xstep < 0) ? -1 : 1;
	raycasting_horz2(game);
	return game->ray.foundhorzwallhit
		? (TWO_POINT_DISTANCE(game->player.x,
							game->player.y,
							game->ray.horzx,
							game->ray.horzy))
		: game->win.width * game->win.height;
}
