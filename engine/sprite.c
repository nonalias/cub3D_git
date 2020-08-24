#include "../cub3d.h"

int		is_sprite(t_game *game)
{
	int		x;
	int		y;

	x = (int)(game->wall.x / game->tile_xsize);
	y = (int)(game->wall.y / game->tile_ysize);
	if (my_map[y][x] == 2)
		return (1);
	return (0);
}

void	get_sprite_angle(t_game *game)
{
	double	dx = game->player.x - game->spr.x;
	double	dy = game->player.y - game->spr.y;

	game->spr.angle = TO_DEGREE(atan2(dy, dx));
	//game->spr.angle = 90 - game->spr.angle;
	if (game->spr.angle < 180)
		game->spr.angle += 180;
	game->spr.distance = TWO_POINT_DISTANCE(
			game->player.x,
			game->player.y,
			game->spr.x,
			game->spr.y);
	printf("game->spr.angle : %f\n", game->spr.angle);
	printf("game->spr.distance : %f\n", game->spr.distance);
	/*
	double start = game->player.rot_angle - game->spr.angle;
	double end = game->player.rot_angle + game->spr.angle;
	if (start < 0)
		start += 360;
	if (end > 360)
		end -= 360;
	printf("start : %f\n", start);
	printf("end : %f\n", end);
	*/
}

void	make_sprite_by_image(t_game *game)
{
}

void	make_sprite(t_game *game)
{
	double	raystart;
	double	rayend;

	get_sprite_angle(game);
	raystart = game->player.rot_angle - game->seek_angle / 2;
	rayend = game->player.rot_angle + game->seek_angle / 2;
	/*
	if (raystart < 0)
		raystart += 360;
	if (rayend > 360)
		rayend -= 360;
		*/
	//if (raystart < game->spr.angle && rayend > game->spr.angle)
		//make_sprite_by_image(game);
}
