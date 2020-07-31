#include "cub3d.h"

int		hook_action(t_game *game)
{
	if (game->key_check[LEFT_ARROW])
		game->player.rot_angle -= game->player.rot_speed;
	else if (game->key_check[RIGHT_ARROW])
		game->player.rot_angle += game->player.rot_speed;
	if (game->player.rot_angle > 360)
		game->player.rot_angle -= 360;
	else if (game->player.rot_angle < 360)
		game->player.rot_angle += 360;
	if (game->key_check[KEY_W] && game->key_check[KEY_A])
		move_w_a(game);
	else if (game->key_check[KEY_W] && game->key_check[KEY_D])
		move_w_d(game);
	else if (game->key_check[KEY_W])
		move_w(game);
	else if (game->key_check[KEY_S] && game->key_check[KEY_A])
		move_s_a(game);
	else if (game->key_check[KEY_S] && game->key_check[KEY_D])
		move_s_d(game);
	else if (game->key_check[KEY_S])
		move_s(game);
	else if (game->key_check[KEY_A])
		move_a(game);
	else if (game->key_check[KEY_D])
		move_d(game);
	make_view(game);
	debug_process(game);
	return (1);
}
