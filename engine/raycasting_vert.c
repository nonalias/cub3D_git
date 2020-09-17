#include "../cub3d.h"

void	set_sprite_vert_hit(t_game *game, double x, double y)
{
	game->spr.vert_x = x;
	if (game->ray.left_facing)
		game->spr.vert_x += 1;
	game->spr.vert_y = y;
	game->spr.vert_hit = 1;
}

void	raycasting_vert2(t_game *game)
{
	t_pos	touched;

	touched.x = game->ray.xintercept;
	touched.y = game->ray.yintercept;
	if (game->ray.left_facing)
		touched.x -= 1;
	while (touched.x >= 0
			&& touched.x <= game->common_tsize * game->map.columns
			&& touched.y >= 0
			&& touched.y <= game->common_tsize * game->map.rows)
	{
		if (check_wall(game, touched.x, touched.y))
		{
			game->ray.foundvertwallhit = 1;
			if (game->ray.left_facing)
				touched.x += 1;
			game->ray.vertx = touched.x;
			game->ray.verty = touched.y;
			return ;
		}
		if (check_sprite(game, touched.x, touched.y)
				&& game->spr.vert_x == -1 && game->spr.vert_y == -1)
			set_sprite_vert_hit(game, touched.x, touched.y);
		touched.x += game->ray.xstep;
		touched.y += game->ray.ystep;
	}
}

double	raycasting_vert(t_game *game)
{
	game->ray.foundvertwallhit = 0;
	game->ray.down_facing = game->wall.angle > 0 && game->wall.angle < 180;
	game->ray.up_facing = !game->ray.down_facing;
	game->ray.right_facing = game->wall.angle < 90 || game->wall.angle > 270;
	game->ray.left_facing = !game->ray.right_facing;
	game->ray.xintercept = floor(game->player.x / game->common_tsize) * game->common_tsize;
	game->ray.xintercept += game->ray.right_facing ? game->common_tsize : 0;
	game->ray.yintercept = game->player.y + (game->ray.xintercept - game->player.x) * tan(to_radian(game->wall.angle));
	game->ray.xstep = game->common_tsize;
	game->ray.xstep *= game->ray.left_facing ? -1 : 1;
	game->ray.ystep = game->common_tsize * tan(to_radian(game->wall.angle));
	game->ray.ystep *= (game->ray.up_facing && game->ray.ystep > 0) ? -1 : 1;
	game->ray.ystep *= (game->ray.down_facing && game->ray.ystep < 0) ? -1 : 1;
	raycasting_vert2(game);
	return game->ray.foundvertwallhit
		? (hypot(game->player.x - game->ray.vertx,
					game->player.y - game->ray.verty))
		: game->win.width * game->win.height;
}
