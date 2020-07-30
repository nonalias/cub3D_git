#include "cub3d.h"

int		key_press_callback(t_game *game)
{
	if (keycode >= 300)
		return (-1);
	game->key_check[keycode] = 1;
	if (keycode == 53)
		exit(0);
	return (0);
}
int		key_release_callback(t_game *game)
{
	if (keycode >= 300)
		return (-1);
	game->key_check[keycode] = 0;
	return (0);
}
