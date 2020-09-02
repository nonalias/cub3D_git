#include "../cub3d.h"

void	resolution_parse(t_game *game, char **splited)
{
	game->win.width = ft_atoi(splited[1]);
	game->win.height = ft_atoi(splited[2]);
}

void	free_splited(char ***splited)
{
	int		i;

	i = 0;
	while ((*splited)[i])
	{
		if ((*splited)[i])
			free((*splited)[i]);
		(*splited)[i] = NULL;
		i++;
	}
	if (*splited)
		free(*splited);
	*splited = NULL;
}

void	free_line(char **line)
{
	if (*line)
		free(*line);
	*line = NULL;
}

int		is_option(char c)
{
	if (c == 'R' || c == 'N' || c == 'S'
			|| c == 'W' || c == 'E' || c == 'F'
			|| c == 'C' || c == '\n')
		return (1);
	return (0);
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

void	option_parsing2(t_game *game)
{
	game->map.splited = ft_split(game->map.line, ' ');
	if (!ft_strncmp(game->map.splited[0], "R", 1))
		resolution_parse(game, game->map.splited);
	else if (!ft_strncmp(game->map.splited[0], "NO", 2))
		game->map.north = ft_strdup(game->map.splited[1]);
	else if (!ft_strncmp(game->map.splited[0], "SO", 2))
		game->map.south = ft_strdup(game->map.splited[1]);
	else if (!ft_strncmp(game->map.splited[0], "WE", 2))
		game->map.west = ft_strdup(game->map.splited[1]);
	else if (!ft_strncmp(game->map.splited[0], "EA", 2))
		game->map.east = ft_strdup(game->map.splited[1]);
	else if (!ft_strncmp(game->map.splited[0], "F", 1))
		game->map.floor = str_to_color(game->map.splited[1]);
	else if (!ft_strncmp(game->map.splited[0], "C", 1))
		game->map.ceil = str_to_color(game->map.splited[1]);
	else if (!ft_strncmp(game->map.splited[0], "S", 2))
		game->map.sprite = ft_strdup(game->map.splited[1]);
	free_splited(&game->map.splited);
}

void	option_parsing(t_game *game)
{
	int		i;

	i = 0;
	get_next_line(game->map.fd, &game->map.line);
	while (i < 8)
	{
		if (ft_strlen(game->map.line) >= 3)
		{
			option_parsing2(game);
			i++;
		}
		free_line(&game->map.line);
		get_next_line(game->map.fd, &game->map.line);
	}
}

void	one_line_to_map(t_game *game, int row)
{
	int		i;

	i = 0;
	while (i < game->map.columns)
	{
		if (game->map.line[i] == ' ')
			my_map[row][i] = 1;
		else
			my_map[row][i] = game->map.line[i] - '0';
		i++;
	}
}

void	show_map(t_game *game)
{
	int		i;
	int		j;

	printf("-----mapstart-----\n");
	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.columns)
		{
			printf("%d", my_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("-----mapend-----\n");
}

void	map_parsing(t_game *game)
{
	int		i;
	int		temp;

	i = 0;
	while (1)
	{
		while (ft_strlen(game->map.line) < 3)
		{
			free_line(&game->map.line);
			temp = get_next_line(game->map.fd, &game->map.line);
			if (temp <= 0)
				break ;
		}
		if ((temp = ft_strlen(game->map.line)) >= 3)
		{
			game->map.columns = temp;
			one_line_to_map(game, i);
			i++;
		}
		if ((get_next_line(game->map.fd, &game->map.line) <= 0))
			break ;
	}
	game->map.rows = i;
}

void	parse(t_game *game)
{
	game->map.fd = open(game->map.name, O_RDONLY);
	if (game->map.fd < 0)
		error_exit(MAP_ERROR);
	option_parsing(game);
	map_parsing(game);
	show_map(game);
}
