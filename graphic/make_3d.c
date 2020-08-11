/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 18:25:11 by taehkim           #+#    #+#             */
/*   Updated: 2020/08/11 18:54:18 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_cardinal(t_game *game)
{
	if (game->wall.what_hit == VERT_HIT)
	{
		if (game->wall.angle > 90 && game->wall.angle < 270)
			game->wall.cardinal = WEST;
		else
			game->wall.cardinal = EAST;
	}
	else if (game->wall.what_hit == HORZ_HIT)
	{
		if (game->wall.angle > 0 && game->wall.angle < 180)
			game->wall.cardinal = SOUTH;
		else
			game->wall.cardinal = NORTH;
	}
}

void	make_ceil(t_game *game)
{
	t_pos	pos[2];

	set_pos(&pos[0], ((game->ray.angle + game->seek_angle / 2) *
				game->win.width / game->seek_angle),
			0);
	set_pos(&pos[1], pos[0].x,
			game->win.height / 2 - (game->wall.realheight / 2));
	game->line.color = 0x50bcdf;
	make_line(game, pos[0], pos[1]);
}

void	make_floor(t_game *game)
{
	t_pos	pos[2];

	set_pos(&pos[0], ((game->ray.angle + game->seek_angle / 2) *
				game->win.width / game->seek_angle),
			game->win.height / 2 + (game->wall.realheight / 2) - 1);
	set_pos(&pos[1], pos[0].x, game->win.height);
	game->line.color = 0xf0ecdd;
	make_line(game, pos[0], pos[1]);
}

/*
int		get_tex_x(t_game *game)
{
	if (game->wall.what_hit == VERT_HIT)
		tex_x = (int)(fmod(game->wall.y, game->tile_ysize) /
				game->tile_ysize * TEX_HEIGHT);
	else
		tex_x = (int)(fmod(game->wall.x, game->tile_xsize) /
				game->tile_xsize * TEX_WIDTH);
}
*/

/*
int		get_tex_y(t_game *game)
{
	tex_y = TEX_HEIGHT * (y - pos[0].y) / (pos[1].y - pos[0].y);
	if (game->temp > game->win.height)
		tex_y =  (((y / (double)game->win.height)) * (game->wall.realheight / game->temp) * (double)TEX_HEIGHT) +  (TEX_HEIGHT * ((game->temp - game->wall.realheight) / 2.0) / game->temp);
}
*/

void	make_wall_by_image(t_game *game, t_pos pos[2])
{
	int		tex_x;
	int		tex_y;
	int		color;
	double	y;

	//tex_x = get_tex_x(game);
	if (game->wall.what_hit == VERT_HIT)
		tex_x = (int)(fmod(game->wall.y, game->tile_ysize) /
				game->tile_ysize * TEX_HEIGHT);
	else
		tex_x = (int)(fmod(game->wall.x, game->tile_xsize) /
				game->tile_xsize * TEX_WIDTH);

	game->temp = game->wall.realheight;
	if (game->wall.realheight >= game->win.height)
	{
		game->wall.realheight = game->win.height - 1;
		pos[0].y = 0;
		pos[1].y = game->win.height;
	}
	y = pos[0].y;
	if (y < 0)
		y = 0;
	while (y < pos[1].y)
	{
	tex_y = TEX_HEIGHT * (y - pos[0].y) / (pos[1].y - pos[0].y);
	if (game->temp > game->win.height)
		tex_y =  (((y / (double)game->win.height)) * (game->wall.realheight / game->temp) * (double)TEX_HEIGHT) +  (TEX_HEIGHT * ((game->temp - game->wall.realheight) / 2.0) / game->temp);

		//tex_y = get_tex_y(game);
		color = game->tex.img[game->wall.cardinal]
			.data[tex_y * TEX_HEIGHT + tex_x];
		game->img.data[to_coord(game, pos[0].x, y)] = color;
		y += 1;
	}
}

void	make_wall(t_game *game)
{
	t_pos	pos[2];

	set_pos(&pos[0], ((game->ray.angle + game->seek_angle / 2) * game->win.width / game->seek_angle), game->win.height / 2 - (game->wall.realheight / 2));
	set_pos(&pos[1], pos[0].x, game->win.height / 2 + (game->wall.realheight / 2));
	check_cardinal(game);
	make_wall_by_image(game, pos);
}

//TODO: rader도 seekangle부분 수정하기
void	make_3d(t_game *game)
{
	double	wallheight;
	t_pos	pos[2];

	game->ray.angle = -1 * game->seek_angle / 2;
	while (game->ray.angle < game->seek_angle / 2)
	{ 
		game->wall.angle = game->player.rot_angle + game->ray.angle;
		if (game->wall.angle < 0)
			game->wall.angle += 360;
		else if (game->wall.angle > 360)
			game->wall.angle -= 360;
		game->wall.distance = get_wall_x_y(game) * cos(TO_RADIAN(game->ray.angle));
		double	distanceprojectionplane = (game->win.width / 2) / tan(TO_RADIAN(game->seek_angle / 2));
		game->wall.realheight = (game->tile_ysize / game->wall.distance) * distanceprojectionplane;
		make_ceil(game);
		make_floor(game);
		make_wall(game);
		game->ray.angle += 0.06;
	}
}
