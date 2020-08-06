#include "cub3d.h"

void	flag_process(t_game *game)
{
	//save_process(game);
}

int		valid_check(t_game *game)
{
	game->map.fd = open(game->map.name, O_RDONLY);
	printf("fd : %d\n", game->map.fd);
}

int		main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	init(game);
	arg_parse(game, argc, argv);
	//if (!valid_check(game))
		//return (1);
	valid_check(game);
	//flag_process(game);
	mlx_hook(game->win_ptr, KEY_PRESSED, 0, &key_press_callback, game);
	mlx_hook(game->win_ptr, KEY_RELEASED, 0, &key_release_callback, game);
	mlx_loop_hook(game->mlx_ptr, &hook_action, game);
	mlx_loop(game->mlx_ptr);
}
