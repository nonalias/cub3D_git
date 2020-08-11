/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_crosshair.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 21:44:56 by taehkim           #+#    #+#             */
/*   Updated: 2020/08/11 20:43:29 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	make_crosshair(t_game *game)
{
	t_pos	pos[2];
	double	centerx;
	double	centery;

	centerx = game->win.width / 2;
	centery = game->win.height / 2;
	set_pos(&pos[0], centerx - 10, centery - 1);
	set_pos(&pos[1], centerx - 4, centery + 1);
	make_rectangle(game, pos, COLOR_GREEN);
	set_pos(&pos[0], centerx + 4, centery - 1);
	set_pos(&pos[1], centerx + 10, centery + 1);
	make_rectangle(game, pos, COLOR_GREEN);
	set_pos(&pos[0], centerx - 1, centery - 10);
	set_pos(&pos[1], centerx + 1, centery - 4);
	make_rectangle(game, pos, COLOR_GREEN);
	set_pos(&pos[0], centerx - 1, centery + 4);
	set_pos(&pos[1], centerx + 1, centery + 10);
	make_rectangle(game, pos, COLOR_GREEN);
}
