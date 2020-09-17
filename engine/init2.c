/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 20:20:10 by taehkim           #+#    #+#             */
/*   Updated: 2020/09/17 20:20:14 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	wall_init(t_game *game)
{
	game->wall.x = 0;
	game->wall.y = 0;
	game->wall.angle = 0;
	game->wall.distance = 0;
	game->wall.what_hit = -1;
	game->wall.cardinal = -1;
	game->wall.realheight = 0;
}

t_pos	find_sprite(t_game *game)
{
	int		i;
	int		j;
	t_pos	pos;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.columns)
		{
			if (g_my_map[i][j] == 2)
			{
				set_pos(&pos, j, i);
				return (pos);
			}
			j++;
		}
		i++;
	}
}

void	sprite_init(t_game *game)
{
	t_pos	pos;

	pos = find_sprite(game);
	game->spr.center_x = (int)pos.x * game->tile_xsize + game->tile_xsize / 2;
	game->spr.center_y = (int)pos.y * game->tile_ysize + game->tile_ysize / 2;
	game->spr.angle = 0;
}

void	sprite_reinit(t_game *game)
{
	game->spr.horz_x = -1;
	game->spr.horz_y = -1;
	game->spr.vert_x = -1;
	game->spr.vert_y = -1;
	game->spr.vert_hit = 0;
	game->spr.horz_hit = 0;
	game->spr.what_hit = -1;
	game->spr.angle = 0;
	game->spr.vert_dist = -1;
	game->spr.horz_dist = -1;
}
