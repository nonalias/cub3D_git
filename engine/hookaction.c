/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookaction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 21:05:13 by taehkim           #+#    #+#             */
/*   Updated: 2020/09/07 14:55:18 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_matching2(t_game *game)
{
	if (game->key_check[KEY_N])
		reset_player(game);
	else if (game->key_check[KEY_1]
			&& game->player.move_speed - 0.5 > 0)
		game->player.move_speed -= 0.5;
	else if (game->key_check[KEY_2]
			&& game->player.move_speed + 0.5 < 100)
		game->player.move_speed += 0.5;
	else if (game->key_check[KEY_3]
			&& game->player.rot_speed - 0.3 > 0)
		game->player.rot_speed -= 0.3;
	else if (game->key_check[KEY_4]
			&& game->player.rot_speed + 0.3 < 25)
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
	specify_angle(&game->player.rot_angle);
	make_view(game);
	if (game->flags.debug)
	{
		//status_show(game);
		//free_process(game);
	}
	return (1);
}
