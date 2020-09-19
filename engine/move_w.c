/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_w.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 20:20:49 by taehkim           #+#    #+#             */
/*   Updated: 2020/09/17 20:20:55 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_w_a(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x + game->player.move_speed
		* cos(to_radian(game->player.rot_angle - 45));
	new_y = game->player.y + game->player.move_speed
		* sin(to_radian(game->player.rot_angle - 45));
	if (move_check(game, game->player.rot_angle - 45)
			&& !check_sprite(game, new_x, new_y)
			&& new_x < game->common_tsize * game->map.columns
			&& new_y < game->common_tsize * game->map.rows
			&& new_x >= 0 && new_y >= 0)
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}

void	move_w_d(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x + game->player.move_speed
		* cos(to_radian(game->player.rot_angle + 45));
	new_y = game->player.y + game->player.move_speed
		* sin(to_radian(game->player.rot_angle + 45));
	if (move_check(game, game->player.rot_angle + 45)
			&& !check_sprite(game, new_x, new_y)
			&& new_x < game->common_tsize * game->map.columns
			&& new_y < game->common_tsize * game->map.rows
			&& new_x >= 0 && new_y >= 0)
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}



void	move_w(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x + game->player.move_speed
		* cos(to_radian(game->player.rot_angle));
	new_y = game->player.y + game->player.move_speed
		* sin(to_radian(game->player.rot_angle));
	if (!check_sprite(game, new_x, new_y)
			&& new_x < game->common_tsize * game->map.columns
			&& new_y < game->common_tsize * game->map.rows
			&& new_x >= 0 && new_y >= 0 && move_check(game, game->player.rot_angle))
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}
