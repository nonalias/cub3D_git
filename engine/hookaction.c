#include "../cub3d.h"

void	key_matching2(t_game *game)
{
	if (game->key_check[KEY_1]
			&& game->player.move_speed - 0.5 > 0)
		game->player.move_speed -= 0.5;
	else if (game->key_check[KEY_2])
		game->player.move_speed += 0.5;
	else if (game->key_check[KEY_3]
			&& game->player.rot_speed - 0.3 > 0)
		game->player.rot_speed -= 0.3;
	else if (game->key_check[KEY_4])
		game->player.rot_speed += 0.3;
}

void	key_matching(t_game *game)
{
	if (game->key_check[LEFT_ARROW])
		game->player.rot_angle -= game->player.rot_speed;
	else if (game->key_check[RIGHT_ARROW])
		game->player.rot_angle += game->player.rot_speed;
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
	key_matching2(game);
}

int		hook_action(t_game *game)
{
	key_matching(game);
	if (game->player.rot_angle > 360)
		game->player.rot_angle -= 360;
	else if (game->player.rot_angle < 0)
		game->player.rot_angle += 360;
	make_view(game);
	status_show(game);
	free_process(game);
	return (1);
}
