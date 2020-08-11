/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 18:25:11 by taehkim           #+#    #+#             */
/*   Updated: 2020/08/11 21:35:51 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	make_wall_by_image2(t_game *game, t_pos pos[2])
{
	int		color;
	double	tex_start;

	tex_start = (TEX_HEIGHT * ((game->temp - game->wall.realheight) / 2.0) /
			game->temp);
	while (game->tex.y_iter < pos[1].y)
	{
		game->tex.tex_y = TEX_HEIGHT * (game->tex.y_iter - pos[0].y) /
			(pos[1].y - pos[0].y);
		if (game->temp > game->win.height)
			game->tex.tex_y =  ((game->tex.y_iter / (double)game->win.height) *
					(game->wall.realheight / game->temp) * (double)TEX_HEIGHT)
				+ tex_start;
		color = game->tex.img[game->wall.cardinal]
			.data[game->tex.tex_y * TEX_HEIGHT + game->tex.tex_x];
		game->img.data[to_coord(game, pos[0].x, game->tex.y_iter)] = color;
		game->tex.y_iter += 1;
	}
}

void	make_wall_by_image(t_game *game, t_pos pos[2])
{
	if (game->wall.what_hit == VERT_HIT)
		game->tex.tex_x = (int)(fmod(game->wall.y, game->tile_ysize) /
				game->tile_ysize * TEX_HEIGHT);
	else
		game->tex.tex_x = (int)(fmod(game->wall.x, game->tile_xsize) /
				game->tile_xsize * TEX_WIDTH);
	game->temp = game->wall.realheight;
	if (game->wall.realheight >= game->win.height)
	{
		game->wall.realheight = game->win.height - 1;
		pos[0].y = 0;
		pos[1].y = game->win.height;
	}
	game->tex.y_iter = pos[0].y;
	if (game->tex.y_iter < 0)
		game->tex.y_iter = 0;
	make_wall_by_image2(game, pos);
}

void	make_wall(t_game *game)
{
	t_pos	pos[2];

	set_pos(&pos[0], ((game->ray.angle + game->seek_angle / 2) *
				game->win.width / game->seek_angle),
			game->win.height / 2 - (game->wall.realheight / 2));
	set_pos(&pos[1], pos[0].x,
			game->win.height / 2 + (game->wall.realheight / 2));
	check_cardinal(game);
	make_wall_by_image(game, pos);
}

//TODO: rader도 seekangle부분 수정하기
void	make_3d(t_game *game)
{
	double	wallheight;
	double	dist_opt;
	t_pos	pos[2];

	game->ray.angle = -1 * game->seek_angle / 2;
	while (game->ray.angle < game->seek_angle / 2)
	{ 
		game->wall.angle = game->player.rot_angle + game->ray.angle;
		if (game->wall.angle < 0)
			game->wall.angle += 360;
		else if (game->wall.angle > 360)
			game->wall.angle -= 360;
		game->wall.distance = get_wall_x_y(game) *
			cos(TO_RADIAN(game->ray.angle));
		dist_opt = (game->win.width / 2) /
			tan(TO_RADIAN(game->seek_angle / 2));
		game->wall.realheight = (game->tile_ysize /
				game->wall.distance) * dist_opt;
		make_ceil(game);
		make_floor(game);
		make_wall(game);
		game->ray.angle += 0.06;
	}
}
