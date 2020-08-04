#include "cub3d.h"

int		my_map2[11][11] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1},
	{1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

int		my_map[11][11] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

/*
int		mini_check_wall(t_game * game, double x, double y)
{
	double	coord_x;
	double	coord_y;

	coord_x = x / (game->win.width / game->map_xlength) / MINIMAP_RATIO;
	coord_y = y / (game->win.height / game->map_ylength) / MINIMAP_RATIO;
	if (my_map[(int)coord_y][(int)coord_x] == 1)
		return (1);
	return (0);
}
*/

double	get_wall_x_y(t_game *game)
{
	double	xintercept, yintercept;
	double	xstep, ystep;
	int		foundhorzwallhit = 0;
	int		israyfacingup;
	int		israyfacingdown;
	int		israyfacingright;
	int		israyfacingleft;
	double	horzwallhitx = 0;
	double	horzwallhity = 0;

	israyfacingdown = game->wall.angle > 0 && game->wall.angle < 180;  
	israyfacingup = !israyfacingdown;
	israyfacingright = game->wall.angle < 90 || game->wall.angle > 270;
	israyfacingleft = !israyfacingright;

	yintercept = floor(game->player.cur_y / game->tile_ysize) * game->tile_ysize;
	if (israyfacingdown)
		yintercept += game->tile_ysize;
	xintercept = game->player.cur_x + (yintercept - game->player.cur_y) / tan(TO_RADIAN(game->wall.angle));

	ystep = game->tile_ysize;
	if (israyfacingup)
		ystep *= -1;

	xstep = game->tile_xsize / tan(TO_RADIAN(game->wall.angle));
	xstep *= (israyfacingleft && xstep > 0) ? -1 : 1;
	xstep *= (israyfacingright && xstep < 0) ? -1 : 1;

	double nexthorztouchx = xintercept;
	double nexthorztouchy = yintercept;

	if (israyfacingup)
		nexthorztouchy -= 1;
	while (nexthorztouchx >= 0 && nexthorztouchx <= game->win.width && nexthorztouchy >= 0 && nexthorztouchy <= game->win.height)
	{
		if (check_wall(game, nexthorztouchx, nexthorztouchy))
		{
			foundhorzwallhit = 1;
			horzwallhitx = nexthorztouchx;
			horzwallhity = nexthorztouchy;
			break;
		}
		else
		{
			nexthorztouchx += xstep;
			nexthorztouchy += ystep;
		}
	}

	int	foundvertwallhit = 0;
	double vertwallhitx = 0;
	double vertwallhity = 0;

	xintercept = floor(game->player.cur_x / game->tile_xsize) * game->tile_xsize;
	xintercept += israyfacingright ? game->tile_xsize : 0;
	yintercept = game->player.cur_y + (xintercept - game->player.cur_x) * tan(TO_RADIAN(game->wall.angle));
	xstep = game->tile_xsize;
	xstep *= israyfacingleft ? -1 : 1;

	ystep = game->tile_ysize * tan(TO_RADIAN(game->wall.angle));
	ystep *= (israyfacingup && ystep > 0) ? -1 : 1;
	ystep *= (israyfacingdown && ystep < 0) ? -1 : 1;

	double nextverttouchx = xintercept;
	double nextverttouchy = yintercept;

	if (israyfacingleft)
		nextverttouchx -= 1;

	while (nextverttouchx >= 0 && nextverttouchx <= game->win.width && nextverttouchy >= 0 && nextverttouchy <= game->win.height)
	{
		if (check_wall(game, nextverttouchx, nextverttouchy))
		{
			foundvertwallhit = 1;
			vertwallhitx = nextverttouchx;
			vertwallhity = nextverttouchy;
			break;
		}
		else
		{
			nextverttouchx += xstep;
			nextverttouchy += ystep;
		}
	}
	double horzhitdistance = foundhorzwallhit ? TWO_POINT_DISTANCE(game->player.cur_x, game->player.cur_y, horzwallhitx, horzwallhity) : game->win.height * game->win.width;
	double verthitdistance = foundvertwallhit ? TWO_POINT_DISTANCE(game->player.cur_x, game->player.cur_y, vertwallhitx, vertwallhity) : game->win.height * game->win.width;

	game->wall.x = (horzhitdistance < verthitdistance) ? horzwallhitx : vertwallhitx;
	game->wall.y = (horzhitdistance < verthitdistance) ? horzwallhity : vertwallhity;
	return horzhitdistance < verthitdistance ? horzhitdistance : verthitdistance;
}

int		check_wall(t_game * game, double x, double y)
{
	double	coord_x;
	double	coord_y;

	coord_x = x / (game->win.width / game->map_xlength);
	coord_y = y / (game->win.height / game->map_ylength);
	if (my_map[(int)coord_y][(int)coord_x] == 1)
		return (1);
	return (0);
}
