#include "../cub3d.h"

void	set_sprite_horz_hit(t_game *game, double x, double y)
{
	game->spr.horz_x = x;
	game->spr.horz_y = y;
	if (game->ray.up_facing)
		game->spr.horz_y += 1;
	game->spr.horz_hit = 1;
}

void	raycasting_horz2(t_game *game)
{
	t_pos	touched;

	touched.x = game->ray.xintercept;
	touched.y = game->ray.yintercept;
	if (game->ray.up_facing)
		touched.y -= 1;
	while (touched.x >= 0
			&& touched.x <= game->common_tsize * game->map.columns
			&& touched.y >= 0
			&& touched.y <= game->common_tsize * game->map.rows)
	{
		if (check_wall(game, touched.x, touched.y))
		{
			game->ray.foundhorzwallhit = 1;
			game->ray.horzx = touched.x;
			if (game->ray.up_facing)
				touched.y += 1;
			game->ray.horzy = touched.y;
			return ;
		}
		if (check_sprite(game, touched.x, touched.y)
			&& game->spr.horz_x == -1 && game->spr.horz_y == -1)
			set_sprite_horz_hit(game, touched.x, touched.y);
		touched.x += game->ray.xstep;
		touched.y += game->ray.ystep;
	}
}

double	raycasting_horz(t_game *game)
{
	game->ray.foundhorzwallhit = 0;
	game->ray.down_facing = game->wall.angle > 0 && game->wall.angle < 180;
	game->ray.up_facing = !game->ray.down_facing;
	game->ray.left_facing = game->wall.angle > 90 && game->wall.angle < 270;
	game->ray.right_facing = !game->ray.left_facing;
	game->ray.yintercept = floor(game->player.y / game->common_tsize) * game->common_tsize;
	if (game->ray.down_facing)
		game->ray.yintercept += game->common_tsize;
	game->ray.xintercept = game->player.x + (game->ray.yintercept - game->player.y) / tan(TO_RADIAN(game->wall.angle));
	game->ray.ystep = game->common_tsize;
	if (game->ray.up_facing)
		game->ray.ystep *= -1;
	game->ray.xstep = game->common_tsize / tan(TO_RADIAN(game->wall.angle));
	game->ray.xstep *= (game->ray.left_facing && game->ray.xstep > 0) ? -1 : 1;
	game->ray.xstep *= (game->ray.right_facing && game->ray.xstep < 0) ? -1 : 1;
	raycasting_horz2(game);
	return game->ray.foundhorzwallhit
		? (hypot(game->player.x - game->ray.horzx,
					game->player.y - game->ray.horzy))
		: game->win.width * game->win.height;
}
