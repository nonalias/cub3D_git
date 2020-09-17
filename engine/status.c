/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 21:01:45 by taehkim           #+#    #+#             */
/*   Updated: 2020/09/07 14:49:30 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_one_status(t_game *game, char *str, double value, t_pos *pos)
{
	char	*temp;
	char	*temp2;

	temp = ft_itoa((int)value);
	temp2 = ft_strjoin(str, temp);
	free_line(&temp);
	mlx_string_put(game->mlx_ptr, game->win_ptr, pos->x, pos->y,
		COLOR_GREEN, temp2);
	pos->y += 15;
	free_line(&temp2);
}

void	status_show(t_game *game)
{
	t_pos	pos;
	char	*temp;

	pos.x = (int)(game->win.width / 1.6);
	pos.y = (int)(game->win.height / 20);
	temp = ft_strjoin("MAP NAME : ", game->map.name);
	mlx_string_put(game->mlx_ptr, game->win_ptr, pos.x, pos.y,
			COLOR_GREEN, temp);
	free_line(&temp);
	pos.y += 15;
	put_one_status(game, "PLAYER POSITION (X) : ", game->player.x, &pos);
	put_one_status(game, "PLAYER POSITION (Y) : ", game->player.y, &pos);
	put_one_status(game, "ROTATION ANGLE : ", game->player.rot_angle, &pos);
	put_one_status(game, "MOVE SPEED (0~100) : ",
		game->player.move_speed, &pos);
	put_one_status(game, "ROTATION SPEED (0~24) : ",
		game->player.rot_speed, &pos);
}
