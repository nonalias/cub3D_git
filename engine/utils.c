#include "../cub3d.h"

void	arg_parse(t_game *game, int argc, char **argv)
{
	int		i;

	if (argc == 1)
		return ;
	game->map.name = argv[1];
	i = 2;
	while (i < argc)
	{
		if (!ft_strncmp(argv[i], "--save", 6))
			game->flags.save = 1;
		else if (!ft_strncmp(argv[i], "--debug", 7))
			game->flags.debug = 1;
		i++;
	}
}

void	debug_process(t_game *game)
{
	int		x;
	int		y;

	if (game->flags.debug == 0)
		return ;
	game->debug.map_str = ft_strdup("MAP NAME : ");
	game->debug.map_str = ft_strjoin(game->debug.map_str, game->map.name);
	game->debug.x_str = ft_strdup("PLAYER POSITION (X) : ");
	game->debug.x_str = ft_strjoin(game->debug.x_str, ft_itoa((int)game->player.cur_x));
	game->debug.y_str = ft_strdup("PLAYER POSITION (Y) : ");
	game->debug.y_str = ft_strjoin(game->debug.y_str, ft_itoa((int)game->player.cur_y));
	game->debug.rot_angle_str = ft_strdup("ROTATION ANGLE : ");
	game->debug.rot_angle_str = ft_strjoin(game->debug.rot_angle_str, ft_itoa((int)game->player.rot_angle));
	x = (int)(game->win.width / 1.6);
	y = (int)(game->win.height / 20);
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, COLOR_GREEN, game->debug.map_str);
	y += 15;
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, COLOR_GREEN, game->debug.x_str);
	y += 15;
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, COLOR_GREEN, game->debug.y_str);
	y += 15;
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, COLOR_GREEN, game->debug.rot_angle_str);
}

void	free_process(t_game *game)
{
	free(game->debug.map_str);
	free(game->debug.x_str);
	free(game->debug.y_str);
	free(game->debug.rot_angle_str);
	game->debug.map_str = NULL;
	game->debug.x_str = NULL;
	game->debug.y_str = NULL;
	game->debug.rot_angle_str = NULL;
}
