#include "../cub3d.h"

int		check_sprite(t_game *game, double x, double y)
{
	int		coord_x;
	int		coord_y;

	coord_x = floor(x / game->tile_xsize);
	coord_y = floor(y / game->tile_ysize);
	if (coord_x < 0)
		coord_x = 0;
	if (coord_y < 0)
		coord_y = 0;
	if (coord_x > game->map.columns - 1)
		coord_x = game->map.columns - 1;
	if (coord_y > game->map.rows - 1)
		coord_y = game->map.rows - 1;
	if (my_map[coord_y][coord_x] == 2)
		return (1);
	return (0);
}

void	get_sprite_config(t_game *game)
{
	if (game->spr.what_hit == HORZ_HIT)
		set_pos(&game->spr.hit, game->spr.horz_x, game->spr.horz_y);
	else if (game->spr.what_hit == VERT_HIT)
		set_pos(&game->spr.hit, game->spr.vert_x, game->spr.vert_y);
	game->spr.coord_x = (int)(game->spr.hit.x / game->tile_xsize);
	game->spr.coord_y = (int)(game->spr.hit.y / game->tile_ysize);
	if (game->ray.left_facing && game->spr.what_hit == VERT_HIT)
		game->spr.coord_x -= 1;
	if (game->ray.up_facing && game->spr.what_hit == HORZ_HIT)
		game->spr.coord_y -= 1;
	game->spr.center_x = (game->spr.coord_x + 0.5) * game->tile_xsize;
	game->spr.center_y = (game->spr.coord_y + 0.5) * game->tile_ysize;
	game->spr.center_angle = atan2(game->player.y - game->spr.center_y,
			game->player.x - game->spr.center_x);
	game->spr.distance = hypot(game->player.y - game->spr.center_y,
			game->player.x - game->spr.center_x);
	//printf("center.x : %f, center.y : %f\n", game->spr.center_x, game->spr.center_y);
	if (game->spr.center_angle == 0)
	printf("%f\n", game->spr.center_angle);
	game->spr.min_angle = game->spr.center_angle - atan2(game->tile_xsize / 2, game->spr.distance);
	game->spr.max_angle = game->spr.center_angle + atan2(game->tile_xsize / 2, game->spr.distance);
	if (game->spr.min_angle > M_PI)
		game->spr.min_angle -= 2 * M_PI;
	if (game->spr.min_angle < -M_PI)
		game->spr.min_angle += 2 * M_PI;
	if (game->spr.max_angle > M_PI)
		game->spr.max_angle -= 2 * M_PI;
	if (game->spr.max_angle < -M_PI)
		game->spr.max_angle += 2 * M_PI;
	game->tex.tex_x = (game->spr.angle - game->spr.min_angle) /
		(game->spr.max_angle - game->spr.min_angle) * TEX_WIDTH;
	game->spr.dist_opt = (game->win.width / 2) /
		tan(TO_RADIAN(game->seek_angle / 2));
	game->spr.realheight = (game->tile_ysize /
			game->spr.distance) * game->spr.dist_opt;
}

// 여기서 distance와 왼쪽 끝 앵글, 오른쪽 끝 앵글을 정해주면 될듯
void	get_sprite_hit(t_game *game)
{
	double	dx;
	double	dy;

	game->spr.horz_dist = game->spr.horz_hit ? hypot(game->player.x - game->spr.horz_x,
			game->player.y - game->spr.horz_y) : 1000000000; 
	game->spr.vert_dist = game->spr.vert_hit ? hypot(game->player.x - game->spr.vert_x,
			game->player.y - game->spr.vert_y) : 1000000000; 
	game->spr.what_hit = game->spr.vert_dist < game->spr.horz_dist;
	dx = game->spr.what_hit ? game->player.x - game->spr.vert_x
		: game->player.x - game->spr.horz_x;
	dy = game->spr.what_hit ? game->player.y - game->spr.vert_y
		: game->player.y - game->spr.horz_y;
	game->spr.angle = atan2(dy, dx);
	get_sprite_config(game);
}

void	make_sprite_by_image(t_game *game, t_pos pos[2])
{
	double tex_start;

	tex_start = (TEX_HEIGHT * ((game->temp - game->spr.realheight) / 2.0) / game->temp);
	game->tex.y_iter = pos[0].y;
	while (game->tex.y_iter < pos[1].y)
	{
		game->tex.tex_y = TEX_HEIGHT * (game->tex.y_iter - pos[0].y) /
			(pos[1].y - pos[0].y);
		if (game->temp > game->win.height)
			game->tex.tex_y = ((game->tex.y_iter / (double)game->win.height) *
					(game->spr.realheight / game->temp) * (double)TEX_HEIGHT)
				+ tex_start;
		int color = game->tex.img[SPRITE]
			.data[game->tex.tex_y * TEX_HEIGHT + game->tex.tex_x];
		game->img.data[to_coord(game, pos[0].x, game->tex.y_iter)] = color;
		//color ? game->img.data[to_coord(game, pos[0].x, game->tex.y_iter)] = color : 0;
		game->tex.y_iter += 1;
	}
}

// 필요한 것 : ray를 쐈을 때 스프라이트이면 
// 그 스프라이트의 중심좌표와 
// 중심사이의 거리와
// 현재 각도에서 스프라이트의 왼쪽 끝 사이의 각도와
// 현재 각도에서 스프라이트의 오른쪽 끝 사이의 각도가 필요

void	make_sprite(t_game *game)
{
	t_pos	pos[2];

	if (!game->spr.horz_hit && !game->spr.vert_hit)
		return ;
	get_sprite_hit(game);
	set_pos(&pos[0], ((game->ray.angle + game->seek_angle / 2) *
				game->win.width / game->seek_angle),
			game->win.height / 2 - (game->spr.realheight / 2));
	set_pos(&pos[1], pos[0].x,
			game->win.height / 2 + (game->spr.realheight / 2));
	game->temp = game->spr.realheight;
	if (game->spr.realheight >= game->win.height)
	{
		game->spr.realheight = game->win.height - 1;
		pos[0].y = 0;
		pos[1].y = game->win.height;
	}
	if (game->wall.distance < game->spr.distance)
		return ;
	make_sprite_by_image(game, pos);
}
