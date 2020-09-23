/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 22:47:36 by taehkim           #+#    #+#             */
/*   Updated: 2020/09/23 15:09:38 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		to_coord(t_game *game, double x, double y)
{
	return (int)y * game->win.width + (int)x;
}

void	make_line(t_game *game, t_pos origin, t_pos target)
{
	double	dx;
	double	dy;
	double	step;

	dx = target.x - origin.x;
	dy = target.y - origin.y;
	step = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
	dx /= step;
	dy /= step;
	while (fabs(target.x - origin.x) > 1
			|| fabs(target.y - origin.y) > 1)
	{
		if (origin.x < 0 || origin.x >= game->win.width
				|| origin.y < 0 || origin.y >= game->win.height)
		{
			origin.x += dx;
			origin.y += dy;
			continue;
		}
		game->img.data[to_coord(game, origin.x, origin.y)] = game->line.color;
		origin.x += dx;
		origin.y += dy;
	}
}

void	map_print(t_game *game)
{
	int		i;
	int		j;

	printf("\n");
	i = 0;
	while (i < game->map.columns)
	{
		j = 0;
		while (j < game->map.rows)
		{
			printf("%d ", g_my_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

void	make_tile(t_game *game, int i, int j, int color)
{
	int		k;
	t_pos	pos[2];

	k = 0;
	while (k < game->common_tsize / MINIMAP_RATIO)
	{
		set_pos(&pos[0], j * game->common_tsize / MINIMAP_RATIO + k,
				i * game->common_tsize / MINIMAP_RATIO);
		set_pos(&pos[1], j * game->common_tsize / MINIMAP_RATIO + k,
				(i + 1) * game->common_tsize / MINIMAP_RATIO + 1);
		game->line.color = color;
		make_line(game, pos[0], pos[1]);
		k++;
	}
}

void	make_2d(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.columns)
		{
			if (g_my_map[i][j] == 1)
				make_tile(game, i, j, COLOR_WALL);
			else if (g_my_map[i][j] == 2)
				make_tile(game, i, j, 0xff0000);
			else
				make_tile(game, i, j, COLOR_ROAD);
			j++;
		}
		i++;
	}
}
