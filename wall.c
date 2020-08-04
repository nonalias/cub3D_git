#include "cub3d.h"

int		my_map[11][11] = {
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

int		my_map2[11][11] = {
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
	double	distance_x;
	double	distance_y;

	distance_y = raycasting_y(game);
	distance_x = raycasting_x(game);
	game->wall.x = distance_x < distance_y ? game->ray.vertx : game->ray.horzx;
	game->wall.y = distance_x < distance_y ? game->ray.verty : game->ray.horzy;
	game->wall.is_x_or_y = distance_x < distance_y;
	return distance_x < distance_y ? distance_x : distance_y;
}

int		check_wall(t_game * game, double x, double y)
{
	double	coord_x;
	double	coord_y;

	coord_x = x / game->tile_xsize;
	coord_y = y / game->tile_ysize;
	if (my_map[(int)(coord_y)][(int)(coord_x)] == 1)
		return (1);
	return (0);
}
