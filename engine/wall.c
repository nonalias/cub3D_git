#include "../cub3d.h"

int		my_map[11][15] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

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

double	get_wall_x_y(t_game *game)
{
	double	distance_x;
	double	distance_y;

	distance_y = raycasting_horz(game);
	distance_x = raycasting_vert(game);
	game->wall.x = distance_x < distance_y ? game->ray.vertx : game->ray.horzx;
	game->wall.y = distance_x < distance_y ? game->ray.verty : game->ray.horzy;
	game->wall.what_hit = distance_x < distance_y;
	return distance_x < distance_y ? distance_x : distance_y;
}

int		check_wall(t_game * game, double x, double y)
{
	int		coord_x;
	int		coord_y;

	coord_x = floor(x / game->tile_xsize);
	coord_y = floor(y / game->tile_ysize);
	if (coord_x < 0)
		coord_x = 0;
	if (coord_y < 0)
		coord_y = 0;
	if (coord_x > game->map.xlength - 1)
		coord_x = game->map.xlength - 1;
	if (coord_y > game->map.ylength - 1)
		coord_y = game->map.ylength - 1;
	if (my_map[coord_y][coord_x] == 1)
		return (1);
	return (0);
}
