/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 21:12:00 by taehkim           #+#    #+#             */
/*   Updated: 2020/09/17 21:14:36 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_sprite_config2(t_game *game)
{
	game->spr.min_angle = game->spr.center_angle
		- atan2(game->common_tsize / 2, game->spr.distance);
	game->spr.max_angle = game->spr.center_angle
		+ atan2(game->common_tsize / 2, game->spr.distance);
	if (game->spr.angle < game->spr.min_angle)
		game->spr.angle += 2 * M_PI;
	if (game->spr.angle > game->spr.max_angle)
		game->spr.angle -= 2 * M_PI;
	game->tex.tex_x = (game->spr.angle - game->spr.min_angle) /
		(game->spr.max_angle - game->spr.min_angle) * TEX_WIDTH;
	if (game->tex.tex_x < 0)
		game->tex.tex_x = 0;
	else if (game->tex.tex_x >= 64)
		game->tex.tex_x = 63;
	game->spr.dist_opt = (game->win.width / 2) /
		tan(to_radian(game->seek_angle / 2));
	game->spr.realheight = (game->common_tsize /
			game->spr.distance) * game->spr.dist_opt;
}

void	get_sprite_config(t_game *game)
{
	if (game->spr.what_hit == HORZ_HIT)
		set_pos(&game->spr.hit, game->spr.horz_x, game->spr.horz_y);
	else if (game->spr.what_hit == VERT_HIT)
		set_pos(&game->spr.hit, game->spr.vert_x, game->spr.vert_y);
	game->spr.coord_x = (int)(game->spr.hit.x / game->common_tsize);
	game->spr.coord_y = (int)(game->spr.hit.y / game->common_tsize);
	if (game->ray.left_facing && game->spr.what_hit == VERT_HIT)
		game->spr.coord_x -= 1;
	if (game->ray.up_facing && game->spr.what_hit == HORZ_HIT)
		game->spr.coord_y -= 1;
	game->spr.center_x = (game->spr.coord_x + 0.5) * game->common_tsize;
	game->spr.center_y = (game->spr.coord_y + 0.5) * game->common_tsize;
	game->spr.center_angle = atan2(game->player.y - game->spr.center_y,
			game->player.x - game->spr.center_x);
	specify_radian(&game->spr.center_angle);
	game->spr.distance = hypot(game->player.y - game->spr.center_y,
			game->player.x - game->spr.center_x);
	get_sprite_config2(game);
}

void	get_sprite_hit(t_game *game)
{
	double	dx;
	double	dy;

	game->spr.horz_dist = 1000000000;
	game->spr.vert_dist = 1000000000;
	if (game->spr.horz_hit)
	{
		game->spr.horz_dist = hypot(game->player.x - game->spr.horz_x,
			game->player.y - game->spr.horz_y);
	}
	else if (game->spr.vert_hit)
	{
		game->spr.vert_dist = hypot(game->player.x - game->spr.vert_x,
			game->player.y - game->spr.vert_y);
	}
	game->spr.what_hit = game->spr.vert_dist < game->spr.horz_dist;
	dx = game->spr.what_hit ? (game->player.x - game->spr.vert_x)
		: (game->player.x - game->spr.horz_x);
	dy = game->spr.what_hit ? (game->player.y - game->spr.vert_y)
		: (game->player.y - game->spr.horz_y);
	game->spr.angle = atan2(dy, dx);
	specify_radian(&game->spr.angle);
	get_sprite_config(game);
}

void	make_sprite_by_image(t_game *game, t_pos pos[2])
{
	double tex_start;
	int		color;

	tex_start = (TEX_HEIGHT * ((game->temp - game->spr.realheight) / 2.0)
		/ game->temp);
	game->tex.y_iter = pos[0].y;
	while (game->tex.y_iter < pos[1].y)
	{
		game->tex.tex_y = TEX_HEIGHT * (game->tex.y_iter - pos[0].y) /
			(pos[1].y - pos[0].y);
		if (game->temp > game->win.height)
			game->tex.tex_y = ((game->tex.y_iter / (double)game->win.height) *
					(game->spr.realheight / game->temp) * (double)TEX_HEIGHT)
				+ tex_start;
		color = game->tex.img[SPRITE]
			.data[game->tex.tex_y * TEX_HEIGHT + game->tex.tex_x];
		if (color)
		{
			game->img.data[to_coord(game, pos[0].x, game->tex.y_iter)]
			= shading(game->spr.distance, color);
		}
		game->tex.y_iter += 1;
	}
}

void	make_sprite(t_game *game)
{
	t_pos	pos[2];

	if (!game->spr.horz_hit && !game->spr.vert_hit)
		return ;
	get_sprite_hit(game);
	set_pos(&pos[0], ((game->ray.angle + game->seek_angle / 2) *
				game->win.width / game->seek_angle),
			game->win.height / 2 - (game->spr.realheight / 2));
	set_pos(&pos[1], pos[0].x,
			game->win.height / 2 + (game->spr.realheight / 2));
	game->temp = game->spr.realheight;
	if (game->spr.realheight >= game->win.height)
	{
		game->spr.realheight = game->win.height - 1;
		pos[0].y = 0;
		pos[1].y = game->win.height;
	}
	if (game->wall.distance < game->spr.distance)
		return ;
	make_sprite_by_image(game, pos);
}
