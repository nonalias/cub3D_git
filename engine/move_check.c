/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 15:03:18 by taehkim           #+#    #+#             */
/*   Updated: 2020/09/23 15:04:00 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		move_check(t_game *game, double angle)
{
	double	i;
	double	temp;
	t_pos	new;

	i = angle - game->seek_angle / 2;
	while (i < angle + game->seek_angle / 2)
	{
		temp = i;
		if (temp >= 360)
			temp -= 360;
		else if (temp < 0)
			temp += 360;
		new.x = game->player.x +
			game->player.move_speed * cos(to_radian(temp)) * 1.5;
		new.y = game->player.y +
			game->player.move_speed * sin(to_radian(temp)) * 1.5;
		if (check_wall(game, new.x, new.y))
			return (0);
		i += 1;
	}
	return (1);
}
