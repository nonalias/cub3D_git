#include "../cub3d.h"

void	check_cardinal(t_game *game)
{
	if (game->wall.is_x_or_y == X_SIDE)
	{
		if (game->wall.angle > 90 && game->wall.angle < 270)
			game->wall.cardinal = WEST;
		else
			game->wall.cardinal = EAST;
	}
	else if (game->wall.is_x_or_y == Y_SIDE)
	{
		if (game->wall.angle > 0 && game->wall.angle < 180)
			game->wall.cardinal = SOUTH;
		else
			game->wall.cardinal = NORTH;
	}
}

void	shopping_draw(t_game *game, double lineheight)
{
	int	drawstart = game->line.origin_y;
	int	drawend = game->line.target_y;
	int	texnum = game->wall.cardinal;
	/*
	double	wallX = game->wall.x;
	wallX -= floor(wallX);

	int texX = (int)(wallX * (double)TEX_WIDTH);
	texX = TEX_WIDTH - texX - 1;

	double step = 1.0 * TEX_HEIGHT / lineheight;
	double texPos = (drawstart - game->win.height / 2 + lineheight / 2) * step;
	//printf("texPos : %f\n", texPos);
	*/
	double y = drawstart;
	if (drawend > game->win.height)
		drawend = game->win.height;
	if (y < 0)
		y = 0;
	int texX = (int)(game->wall.x * TEX_WIDTH / game->win.width);
	while (y < drawend)
	{
		//int texY = (int)texPos & (TEX_HEIGHT - 1);
		// height : wally = texheight : texY
		// wally * texwidith / height
		int texY = (int)((y - drawstart) * TEX_HEIGHT / (drawend - drawstart));
		//texPos += step;
		//printf("texnum : %d\n", texnum);
		int color = game->tex.texture[texnum][TEX_HEIGHT * texY + texX];
		// 어둡게 하는 코드
		if (game->wall.is_x_or_y == X_SIDE)
			color = (color >> 1) & 8355711;
		game->img.data[to_coord(game, game->line.origin_x, y)] = color;
		y += 1;
	}
}

//TODO: rader도 seekangle부분 수정하기
void	make_3d(t_game *game)
{
	double	distance;
	double	wallheight;
	double	i;

	i = game->seek_angle / 2 * -1;
	while (i < game->seek_angle / 2)
	{ 
		game->line.origin_x = game->player.cur_x;
		game->line.origin_y = game->player.cur_y;
		double	razer_angle = game->player.rot_angle + i;
		game->line.target_x = game->player.cur_x + game->seek_distance * cos(TO_RADIAN(razer_angle));
		game->line.target_y = game->player.cur_y + game->seek_distance * sin(TO_RADIAN(razer_angle));
		game->wall.angle = razer_angle;
		if (game->wall.angle < 0)
			game->wall.angle += 360;
		else if (game->wall.angle > 360)
			game->wall.angle -= 360;
		distance = get_wall_x_y(game) * cos(TO_RADIAN(i));
		double	distanceprojectionplane = (game->win.width / 2) / tan(M_PI / 180 * game->seek_angle / 2);
		double	wallstripheight = (game->tile_ysize / distance) * distanceprojectionplane;
		game->line.origin_x = ((i + game->seek_angle / 2) * game->win.width / game->seek_angle);
		game->line.origin_y = 0;
		game->line.target_x = game->line.origin_x;
		game->line.target_y = game->win.height / 2 - (wallstripheight / 2);
		game->line.color = 0x50bcdf;
		make_line(game);

		game->line.origin_x = ((i + game->seek_angle / 2) * game->win.width / game->seek_angle);
		game->line.origin_y = game->win.height / 2 + (wallstripheight / 2) - 1;
		game->line.target_x = game->line.origin_x;
		game->line.target_y = game->win.height;
		game->line.color = 0xf0ecdd;
		make_line(game);

		game->line.origin_x = ((i + game->seek_angle / 2) * game->win.width / game->seek_angle);
		game->line.origin_y = game->win.height / 2 - (wallstripheight / 2);
		game->line.target_x = game->line.origin_x;
		game->line.target_y = game->win.height / 2 + (wallstripheight / 2);
		//game->line.color = 0xaaaaaa - 0x010101 * (int)(0xaaaaaa / game->seek_distance * distance);
		check_cardinal(game);
		shopping_draw(game, wallstripheight);
		//make_line(game);
		i += 0.06;
	}
}
