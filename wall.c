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

void	get_wall_x_y(t_game *game)
{
	double	xintercept, yintercept;
	double	xstep, ystep;
	int		foundhorzwallhit = false;
	int		israyfacingup;
	int		israyfacingdown;
	int		israyfacingright;
	int		israyfacingleft;
	double	wallhitx = 0;
	double	wallhity = 0;

	israyfacingdown = game->player.rot_angle > 0 && game->player.rot_angle < 180;  
	israyfacingup = !israyfacingdown;
	israyfacingright = game->player.rot_angle < 90 || game->player.rot_angle > 270;
	israyfacingleft = !israyfacingright;

	yintercept = floor(game->player.cur_y / game->tile_ysize) * game->tile_ysize;
	if (israyfacingdown)
		yintercept += game->tile_ysize;
	xintercept = game->player.cur_x + (yintercept - game->player.cur_y) / tan(game->player.rot_angle);

	ystep = game->tile_ysize;
	if (israyfacingup)
		ystep *= -1;

	xstep = game->tile_xsize / tan(game->player.rot_angle);
	xstep *= (israyfacingleft && xstep > 0) ? -1 : 1;
	xstep *= (israyfacingright && xstep < 0) ? -1 : 1;

	double nexthorztouchx = xintercept;
	double nexthorztouchy = yintercept;

	if (israyfacingup)
		nexthorztouchy -= 1;
	while (nexthorztouchx >= 0 && nexthorztouchx <= game->win.width && nexthorztouchy >= 0 && nexthorztouchy <= game->win.height)
	{
		if (check_wa
	}
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
