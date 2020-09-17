/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 20:22:18 by taehkim           #+#    #+#             */
/*   Updated: 2020/09/17 20:22:21 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	reset_player(t_game *game)
{
	game->player.x = game->win.width / 2;
	game->player.y = game->win.height / 2;
	game->player.rot_angle = 0;
}
