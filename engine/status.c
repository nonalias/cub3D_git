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

void	status_show(t_game *game)
{
	int		x;
	int		y;

	game->debug.map_str = ft_strjoin("MAP NAME : ", game->map.name);
	game->debug.x_str = ft_strjoin("PLAYER POSITION (X) : ", ft_itoa((int)game->player.x));
	game->debug.y_str = ft_strjoin("PLAYER POSITION (Y) : ", ft_itoa((int)game->player.y));
	game->debug.rot_angle_str = ft_strjoin("ROTATION ANGLE : ", ft_itoa((int)game->player.rot_angle));
	game->debug.move_speed_str = ft_strjoin("MOVE SPEED (0~100) : ", ft_itoa((int)game->player.move_speed));
	game->debug.rot_speed_str = ft_strjoin("ROTATION SPEED (0~24) : ", ft_itoa((int)game->player.rot_speed));
	x = (int)(game->win.width / 1.6);
	y = (int)(game->win.height / 20);
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, COLOR_GREEN, game->debug.map_str);
	y += 15;
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, COLOR_GREEN, game->debug.x_str);
	y += 15;
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, COLOR_GREEN, game->debug.y_str);
	y += 15;
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, COLOR_GREEN, game->debug.rot_angle_str);
	y += 15;
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, COLOR_GREEN, game->debug.move_speed_str);
	y += 15;
	mlx_string_put(game->mlx_ptr, game->win_ptr, x, y, COLOR_GREEN, game->debug.rot_speed_str);

}

void	free_process(t_game *game)
{
	free(game->debug.map_str);
	free(game->debug.x_str);
	free(game->debug.y_str);
	free(game->debug.rot_angle_str);
	free(game->debug.move_speed_str);
	free(game->debug.rot_speed_str);
	game->debug.map_str = NULL;
	game->debug.x_str = NULL;
	game->debug.y_str = NULL;
	game->debug.rot_angle_str = NULL;
	game->debug.move_speed_str = NULL;
	game->debug.rot_speed_str = NULL;
}
