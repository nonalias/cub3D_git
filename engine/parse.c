/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 20:22:12 by taehkim           #+#    #+#             */
/*   Updated: 2020/09/17 20:22:13 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	resolution_parse(t_game *game, char **splited)
{
	game->win.width = ft_atoi(splited[1]);
	game->win.height = ft_atoi(splited[2]);
	if (game->win.width > 1920)
		game->win.width = 1920;
	else if (game->win.width < 500)
		game->win.width = 500;
	if (game->win.height > 1080)
		game->win.height = 1080;
	else if (game->win.height < 500)
		game->win.height = 500;
}

int		str_to_color(char *str)
{
	char	**splited;
	int		color;

	color = 0;
	splited = ft_split(str, ',');
	color += ft_atoi(splited[0]);
	color = color << 8;
	color += ft_atoi(splited[1]);
	color = color << 8;
	color += ft_atoi(splited[2]);
	free_splited(&splited);
	return (color);
}

void	one_line_to_map(t_game *game, int row, int columns)
{
	int		i;

	i = 0;
	while (i < columns)
	{
		if (is_map_position(game->map.line[i]))
			g_my_map[row][i] = game->map.line[i];
		else if (game->map.line[i] == ' ')
			g_my_map[row][i] = 1;
		else
			g_my_map[row][i] = game->map.line[i] - '0';
		i++;
	}
	free_line(&game->map.line);
}

void	map_parsing(t_game *game)
{
	int		i;
	int		temp;

	while (ft_strlen(game->map.line) < 3)
	{
		free_line(&game->map.line);
		if (get_next_line(game->map.fd, &game->map.line) <= 0)
			break ;
	}
	i = 0;
	game->map.columns = 0;
	while ((temp = ft_strlen(game->map.line)) >= 3)
	{
		if (game->map.columns < temp)
			game->map.columns = temp;
		one_line_to_map(game, i, temp);
		if ((get_next_line(game->map.fd, &game->map.line) <= 0))
		{
			i++;
			break ;
		}
		i++;
	}
	game->map.rows = i;
}

void	parse(t_game *game)
{
	map_init(game);
	game->map.fd = open(game->map.name, O_RDONLY);
	if (game->map.fd < 0)
		error_exit(game, MAP_ERROR, "couldn't open map");
	option_parsing(game);
	map_parsing(game);
	if (game->map.rows < 3 || game->map.columns < 3)
		error_exit(game, MAP_ERROR, "map must be over 3 x 3 matrix");
	show_map(game);
}
