#include "cub3d.h"

void	arg_parse(t_game *game, int argc, char **argv)
{
	int		i;

	if (argc == 1)
		return ;
	game->map_name = argv[1];
	i = 2;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if (ft_strncmp(argv[i], "--save", 6))
				game->flags.save = 1;
			else if (ft_strncmp(argv[i], "--debug", 7))
				game->flags.debug = 1;
		}
		i++;
	}
}

void	debug_process(t_game *game)
{
	int		x;
	int		y;

	game->debug.map_str = ft_strdup("MAP NAME : ");
	game->debug.map_str = ft_strjoin(game->debug.map_str, game->map_name);
	game->debug.x_str = ft_strdup("PLAYER POSITION (X) : ");
	game->debug.x_str = ft_strjoin(game->debug.x_str, ft_itoa((int)game->player.cur_x));
	game->debug.y_str = ft_strdup("PLAYER POSITION (Y) : ");
	game->debug.y_str = ft_strjoin(game->debug.y_str, ft_itoa((int)game->player.cur_y));
	game->debug.rot_angle_str = ft_strdup("ROTATION ANGLE : ");
	game->debug.rot_angle_str = ft_strjoin(game->debug.rot_angle_str, ft_itoa((int)game->player.rot_angle));
	x = (int)(game->win.width / 20);
	y = (int)(game->win.height / 20);
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, COLOR_GREEN, game->debug.map_str);
	y += 15;
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, COLOR_GREEN, game->debug.x_str);
	y += 15;
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, COLOR_GREEN, game->debug.y_str);
	y += 15;
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, COLOR_GREEN, game->debug.rot_angle_str);
}

void	flag_process(t_game *game)
{
	//save_process(game);
}

int		main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	arg_parse(game, argc, argv);
	init(game);
	//flag_process(game);
	mlx_hook(game->win_ptr, KEY_PRESSED, 0, &key_press_callback, game);
	mlx_hook(game->win_ptr, KEY_RELEASED, 0, &key_release_callback, game);
	mlx_loop_hook(game->mlx_ptr, &hook_action, game);
	mlx_loop(game->mlx_ptr);
}
