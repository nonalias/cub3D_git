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

/*
void	shopping_draw(t_game *game, double wallheight)
{
}
*/

void	make_ceil(t_game *game, double i, double wall_height)
{
	t_pos	pos[2];

	set_pos(&pos[0], ((i + game->seek_angle / 2) * game->win.width / game->seek_angle), 0);
	set_pos(&pos[1], pos[0].x, game->win.height / 2 - (wall_height / 2));
	game->line.color = 0x50bcdf;
	make_line(game, pos[0], pos[1]);
}

void	make_floor(t_game *game, double i, double wall_height)
{
	t_pos	pos[2];

	set_pos(&pos[0], ((i + game->seek_angle / 2) * game->win.width / game->seek_angle), game->win.height / 2 + (wall_height / 2) - 1);
	set_pos(&pos[1], pos[0].x, game->win.height);
	game->line.color = 0xf0ecdd;
	make_line(game, pos[0], pos[1]);
}

void	make_wall(t_game *game, double i, double wall_height)
{
	t_pos	pos[2];

	set_pos(&pos[0], ((i + game->seek_angle / 2) * game->win.width / game->seek_angle), game->win.height / 2 - (wall_height / 2));
	set_pos(&pos[1], pos[0].x, game->win.height / 2 + (wall_height / 2));
	check_cardinal(game);
	if (game->wall.cardinal == WEST)
		game->line.color = 0xff0000;
	if (game->wall.cardinal == EAST)
		game->line.color = 0x00ff00;
	if (game->wall.cardinal == SOUTH)
		game->line.color = 0x0000ff;
	if (game->wall.cardinal == NORTH)
		game->line.color = 0x0f0f0f;
	make_line(game, pos[0], pos[1]);
	//shopping_draw(game, wallstripheight);
}

//TODO: rader도 seekangle부분 수정하기
void	make_3d(t_game *game)
{
	double	distance;
	double	wallheight;
	double	i;
	t_pos	pos[2];

	i = game->seek_angle / 2 * -1;
	while (i < game->seek_angle / 2)
	{ 
		game->wall.angle = game->player.rot_angle + i;
		if (game->wall.angle < 0)
			game->wall.angle += 360;
		else if (game->wall.angle > 360)
			game->wall.angle -= 360;
		distance = get_wall_x_y(game) * cos(TO_RADIAN(i));
		double	distanceprojectionplane = (game->win.width / 2) / tan(M_PI / 180 * game->seek_angle / 2);
		double	wallstripheight = (game->tile_ysize / distance) * distanceprojectionplane;
		make_ceil(game, i, wallstripheight);
		make_floor(game, i, wallstripheight);
		make_wall(game, i, wallstripheight);
		i += 0.06;
	}
}
