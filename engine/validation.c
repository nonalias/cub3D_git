#include "../cub3d.h"

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

int		is_map_element(char c)
{
	if (c == 1 || c == 0 || c == ' '
			|| c == 'N' || c == 'S' || c == 'W'
			|| c == 'E' || c == 2)
		return (1);
	return (0);
}

int		is_map_position(char c)
{
	if (c == 'N' || c == 'S' || c == 'W'
			|| c == 'E')
		return (1);
	return (0);
}

int		set_map_position(t_game *game, int row, int column)
{
	if (game->map.had_set_position == 1)
		return (0);
	game->map.had_set_position = 1;
	game->player.x = column * game->tile_xsize;
	game->player.y = row * game->tile_ysize;
	if (my_map[row][column] == 'E')
		game->player.rot_angle = 0;
	else if (my_map[row][column] == 'S')
		game->player.rot_angle = 90;
	else if (my_map[row][column] == 'W')
		game->player.rot_angle = 180;
	else if (my_map[row][column] == 'N')
		game->player.rot_angle = 270;
	my_map[row][column] = 0;
	return (1);
}

int		is_map_element_valid(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.columns)
		{
			if (!is_map_element(my_map[i][j]))
				return (0);
			if (is_map_position(my_map[i][j]))
				if (!set_map_position(game, i, j))
					return (0);
			j++;
		}
		i++;
	}
	return (game->map.had_set_position);
}

int		is_map_valid(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->map.rows)
	{
		if (!my_map[i][0] || !my_map[i][game->map.columns - 1])
			return (0);
		i++;
	}
	i = 0;
	while (i < game->map.columns)
	{
		if (!my_map[0][i] || !my_map[game->map.rows - 1][i])
			return (0);
		i++;
	}
	return (is_map_element_valid(game));
}

void	validation(t_game *game)
{
	if (!is_option_valid(game))
		error_exit(game, OPTION_ERROR, "option error");
	if (!is_map_valid(game))
		error_exit(game, MAP_ERROR, "map error");
}
