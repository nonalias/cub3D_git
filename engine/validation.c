/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 20:22:00 by taehkim           #+#    #+#             */
/*   Updated: 2020/09/18 22:46:51 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		set_map_position(t_game *game, int row, int column)
{
	if (game->map.had_set_position == 1)
		return (0);
	game->map.had_set_position = 1;
	game->player.x = (column + 0.5) * game->common_tsize;
	game->player.y = (row + 0.5) * game->common_tsize;
	if (g_my_map[row][column] == 'E')
		game->player.rot_angle = 0;
	else if (g_my_map[row][column] == 'S')
		game->player.rot_angle = 90;
	else if (g_my_map[row][column] == 'W')
		game->player.rot_angle = 180;
	else if (g_my_map[row][column] == 'N')
		game->player.rot_angle = 270;
	g_my_map[row][column] = 0;
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
			if (!is_map_element(g_my_map[i][j]))
				error_exit(game, MAP_ERROR,
				"map can be 'spaces, 1, 0, or player position'");
			if (is_map_position(g_my_map[i][j]))
				if (!set_map_position(game, i, j))
					error_exit(game, MAP_ERROR,
					"you must write single position");
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
		if (g_my_map[i][0] != 1 || g_my_map[i][game->map.columns - 1] != 1)
			error_exit(game, MAP_ERROR,
					"Only 1 should be on the edge of the map.");
		i++;
	}
	i = 0;
	while (i < game->map.columns)
	{
		if (g_my_map[0][i] != 1 || g_my_map[game->map.rows - 1][i] != 1)
			error_exit(game, MAP_ERROR,
					"Only 1 should be on the edge of the map.");
		i++;
	}
	return (is_map_element_valid(game));
}

char	*ft_subrstr(char *str, int size)
{
	int		length;
	char	*output;

	if (!str)
		return (NULL);
	length = ft_strlen(str);
	output = malloc(sizeof(char) * (size + 1));
	output[size] = '\0';
	while (str[length - 1] && size)
	{
		output[size - 1] = str[length - 1];
		length--;
		size--;
	}
	return (output);
}

void	validation(t_game *game)
{
	char	*temp;

	temp = ft_subrstr(game->map.name, 4);
	if (ft_strncmp(temp, ".cub", 4))
		error_exit(game, MAP_ERROR, "map is not '.cub' file");
	if (temp)
		free(temp);
	if (!is_option_valid(game))
		error_exit(game, OPTION_ERROR, "option error");
	if (!is_map_valid(game))
		error_exit(game, MAP_ERROR, "Player location does not exist");
}
