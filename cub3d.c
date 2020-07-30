#include "cub3d.h"

int		main(void)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	init(game);
	mlx_hook(game->win_ptr, KEY_PRESSED, 0, &key_press_callback, game);
	mlx_hook(game->win_ptr, KEY_RELEASED, 0, &key_release_callback, game);
	mlx_loop_hook(game->mlx_ptr, &hook_action, game);
	mlx_loop(game->mlx_ptr);
}
