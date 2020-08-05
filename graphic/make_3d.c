#include "../cub3d.h"

/*
int		get_wall_distance(t_game *game)
{
	double	dx; double	dy;
	double	step;
dx = game->line.target_x - game->line.origin_x; dy = game->line.target_y - game->line.origin_y;
	step = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
	dx /= step;
	dy /= step;
	while (fabs(game->line.target_x - game->line.origin_x) > 1
			|| fabs(game->line.target_y - game->line.origin_y) > 1)
	{ 
		if (check_wall(game, game->line.origin_x, game->line.origin_y))
		{ dx = game->player.cur_x - game->line.origin_x;
			dy = game->player.cur_y - game->line.origin_y;
			return sqrt(dx * dx + dy * dy);
		}
		if (game->line.origin_x < 0 || game->line.origin_x >= game->win.width
				|| game->line.origin_y < 0 || game->line.origin_y >= game->win.height)
		{
			game->line.origin_x += dx;
			game->line.origin_y += dy;
			continue;
		}
		game->line.origin_x += dx;
		game->line.origin_y += dy;
	}
}
*/

double	get_remain(double distance, int operator)
{
	while (distance - operator > 0)
		distance -= operator;
	return (distance);
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
		//distance -= get_remain(distance, 4);
		// if 24672 no show  (distance infinite)
		/*
		if (distance < 0 || distance > game->seek_distance)
		{
			i += 0.1;
			continue;
		}
		*/
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
		if (game->wall.is_x_or_y == X_SIDE)
		{
			if (game->wall.angle > 90 && game->wall.angle < 270)
			{
				game->line.color = 0xe96187; //ㅃㅏㄹ강
			}
			else
			{
				game->line.color = 0xa0d995; // 초록
			}
		}
		else if (game->wall.is_x_or_y == Y_SIDE)
		{
			if (game->wall.angle > 0 && game->wall.angle < 180)
			{
				game->line.color = 0x0a1172; //네이비
			}
			else
				game->line.color = 0xdcd9f8; //연분
		}
		/*
		if (distance < game->seek_distance / 8 * 1)
			game->line.color = 0xdadada;
		else if (distance < game->seek_distance / 8 * 2)
			game->line.color = 0xdadada - 0x141414; // 20
		else if (distance < game->seek_distance / 8 * 3)
			game->line.color = 0xdadada - 0x282828; // 40
		else if (distance < game->seek_distance / 8 * 4)
			game->line.color = 0xdadada  - 0x3c3c3c; // 60
		else if (distance < game->seek_distance / 8 * 5)
			game->line.color = 0xdadada - 0x505050;
		else if (distance < game->seek_distance / 8 * 6)
			game->line.color = 0xdadada - 0x646464;
		else if (distance < game->seek_distance / 8 * 7)
			game->line.color = 0xdadada - 0x787878;
		else if (distance < game->seek_distance / 8 * 8)
			game->line.color = 0xdadada - 0x8c8c8c;
		else
			game->line.color = 0xdadada - 0xa0a0a0;
			*/
		make_line(game);
		i += 0.06;
	}
}
