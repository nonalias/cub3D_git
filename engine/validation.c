#include "../cub3d.h"



int		is_map_valid(t_game *game)
{
}

void	validation(t_game *game)
{
	if (!is_map_valid(game))
		error_exit(MAP_ERROR);
}
