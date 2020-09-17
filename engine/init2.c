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

void	sprite_init(t_game *game)
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

void	map_init(t_game *game)
{
	int		i;
	int		j;

	game->map.columns = 0;
	game->map.rows = 0;
	game->map.floor = 0;
	game->map.ceil = 0;
	game->map.had_set_position = 0;
	i = 0;
	while (i < MAX_MAP_SIZE)
	{
		j = 0;
		while (j < MAX_MAP_SIZE)
		{
			g_my_map[i][j] = 1;
			j++;
		}
		i++;
	}
}
