/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 21:07:04 by taehkim           #+#    #+#             */
/*   Updated: 2020/09/17 21:07:06 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		is_option(char c)
{
	if (c == 'R' || c == 'N' || c == 'S'
			|| c == 'W' || c == 'E' || c == 'F'
			|| c == 'C' || c == '\n')
		return (1);
	return (0);
}

void	option_parsing2(t_game *game)
{
	game->map.splited = ft_split(game->map.line, ' ');
	if (!ft_strncmp(game->map.splited[0], "R", 1))
		resolution_parse(game, game->map.splited);
	else if (!ft_strncmp(game->map.splited[0], "NO", 2))
		game->map.s[NORTH] = ft_strdup(game->map.splited[1]);
	else if (!ft_strncmp(game->map.splited[0], "SO", 2))
		game->map.s[SOUTH] = ft_strdup(game->map.splited[1]);
	else if (!ft_strncmp(game->map.splited[0], "WE", 2))
		game->map.s[WEST] = ft_strdup(game->map.splited[1]);
	else if (!ft_strncmp(game->map.splited[0], "EA", 2))
		game->map.s[EAST] = ft_strdup(game->map.splited[1]);
	else if (!ft_strncmp(game->map.splited[0], "F", 1))
		game->map.floor = str_to_color(game->map.splited[1]);
	else if (!ft_strncmp(game->map.splited[0], "C", 1))
		game->map.ceil = str_to_color(game->map.splited[1]);
	else if (!ft_strncmp(game->map.splited[0], "S", 2))
		game->map.s[SPRITE] = ft_strdup(game->map.splited[1]);
	free_splited(&game->map.splited);
}

void	option_parsing(t_game *game)
{
	int		i;
	int		code;

	i = 0;
	code = get_next_line(game->map.fd, &game->map.line);
	while (i < 8)
	{
		if (code <= 0)
			error_exit(game, FILE_ERROR, "map file is not enough to run");
		if (game->map.line[0] == ' ' || game->map.line[0] == '1'
				|| game->map.line[0] == '0')
			break ;
		if (ft_strlen(game->map.line) >= 3)
		{
			option_parsing2(game);
			i++;
		}
		free_line(&game->map.line);
		code = get_next_line(game->map.fd, &game->map.line);
	}
}
