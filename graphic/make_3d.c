#include "../cub3d.h"

void	check_cardinal(t_game *game)
{
	if (game->wall.what_hit == VERT_HIT)
	{
		if (game->wall.angle > 90 && game->wall.angle < 270)
			game->wall.cardinal = WEST;
		else
			game->wall.cardinal = EAST;
	}
	else if (game->wall.what_hit == HORZ_HIT)
	{
		if (game->wall.angle > 0 && game->wall.angle < 180)
			game->wall.cardinal = SOUTH;
		else
			game->wall.cardinal = NORTH;
	}
}

void	make_ceil(t_game *game, double wall_height)
{
	t_pos	pos[2];

	set_pos(&pos[0], ((game->ray.angle + game->seek_angle / 2) * game->win.width / game->seek_angle), 0);
	set_pos(&pos[1], pos[0].x, game->win.height / 2 - (wall_height / 2));
	game->line.color = 0x50bcdf;
	make_line(game, pos[0], pos[1]);
}

void	make_floor(t_game *game, double wall_height)
{
	t_pos	pos[2];

	set_pos(&pos[0], ((game->ray.angle + game->seek_angle / 2) * game->win.width / game->seek_angle), game->win.height / 2 + (wall_height / 2) - 1);
	set_pos(&pos[1], pos[0].x, game->win.height);
	game->line.color = 0xf0ecdd;
	make_line(game, pos[0], pos[1]);
}

void	make_wall_by_image(t_game *game, double wallstripheight, t_pos pos[2])
{
	int		texX;
	int		texY;
	double	y;

	//수직선에 부딪혔다면
	if (game->wall.what_hit == VERT_HIT)
		texX = (int)(fmod(game->wall.y, game->tile_ysize) / game->tile_ysize * TEX_HEIGHT);
	else
		texX = (int)(fmod(game->wall.x, game->tile_xsize) / game->tile_xsize * TEX_WIDTH);
	//텍스쳐의 x좌표는 수직선에 부딪혔을 경우 부딪힌 y좌표에 의해 결정되고, 수평선에 부딪혔을 경우 부딪힌 x좌표에 의해 결정된다.
	
	game->temp = wallstripheight;
	if (wallstripheight >= game->win.height)
	{
		wallstripheight = game->win.height - 1;
		pos[0].y = 0;
		pos[1].y = game->win.height;
	}
	// 선을 긋기 위해서 시작좌표와 끝좌표를 알아야 한다.
	y = pos[0].y;
	if (y < 0)
		y = 0;
	// 시작과 끝 : pos[0].y, pos[1].y 
	while (y < pos[1].y)
	{
		texY = TEX_HEIGHT * (y - pos[0].y) / (pos[1].y - pos[0].y);
		if (game->temp > game->win.height)
			texY =  (((y / (double)game->win.height)) * (wallstripheight / game->temp) * (double)TEX_HEIGHT) +  (TEX_HEIGHT * ((game->temp - wallstripheight) / 2.0) / game->temp);
		int color = game->tex.img[game->wall.cardinal]
			.data[texY * TEX_HEIGHT + texX];
		game->img.data[to_coord(game, pos[0].x, y)] = color;
		y += 1;
	}
}

void	make_wall(t_game *game, double wall_height)
{
	t_pos	pos[2];

	set_pos(&pos[0], ((game->ray.angle + game->seek_angle / 2) * game->win.width / game->seek_angle), game->win.height / 2 - (wall_height / 2));
	set_pos(&pos[1], pos[0].x, game->win.height / 2 + (wall_height / 2));
	check_cardinal(game);
	/*
	if (game->wall.cardinal == WEST)
		game->line.color = 0xff0000;
	if (game->wall.cardinal == EAST)
		game->line.color = 0x00ff00;
	if (game->wall.cardinal == SOUTH)
		game->line.color = 0x0000ff;
	if (game->wall.cardinal == NORTH)
		game->line.color = 0x0f0f0f;
	make_line(game, pos[0], pos[1]);
	*/
	make_wall_by_image(game, wall_height, pos);
}

//TODO: rader도 seekangle부분 수정하기
void	make_3d(t_game *game)
{
	double	distance;
	double	wallheight;
	t_pos	pos[2];

	game->ray.angle = -1 * game->seek_angle / 2;
	while (game->ray.angle < game->seek_angle / 2)
	{ 
		game->wall.angle = game->player.rot_angle + game->ray.angle;
		if (game->wall.angle < 0)
			game->wall.angle += 360;
		else if (game->wall.angle > 360)
			game->wall.angle -= 360;
		distance = get_wall_x_y(game) * cos(TO_RADIAN(game->ray.angle));
		double	distanceprojectionplane = (game->win.width / 2) / tan(M_PI / 180 * game->seek_angle / 2);
		double	wallstripheight = (game->tile_ysize / distance) * distanceprojectionplane;
		make_ceil(game, wallstripheight);
		make_floor(game, wallstripheight);
		make_wall(game, wallstripheight);
		game->ray.angle += 0.06;
	}
}
