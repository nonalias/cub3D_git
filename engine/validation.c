#include "../cub3d.h"

int		is_map_valid(t_game *game)
{
}

int		is_option_valid(t_game *game)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (game->map.s[i] == NULL)
			return (0);
		i++;
	}
	if (game->map.ceil == 0 || game->map.floor == 0)
		return (0);
	return (1);
}

void	validation(t_game *game)
{
	if (!is_option_valid(game))
		error_exit(game, OPTION_ERROR, "option error");
	//if (!is_map_valid(game))
		//error_exit(game, MAP_ERROR);
}
