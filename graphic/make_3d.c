/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 23:03:42 by taehkim           #+#    #+#             */
/*   Updated: 2020/09/18 23:23:52 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	make_wall_by_image2(t_game *game, t_pos pos[2])
{
	int		color;
	double	tex_start;

	tex_start = ((game->temp - game->wall.realheight) / 2.0) /
			game->temp * TEX_HEIGHT;
	while (game->tex.y_iter < pos[1].y)
	{
		game->tex.tex_y = (game->tex.y_iter - pos[0].y) /
			(pos[1].y - pos[0].y) * TEX_HEIGHT;
		if (game->temp > game->win.height)
			game->tex.tex_y = ((game->tex.y_iter / (double)game->win.height) *
					(game->wall.realheight / game->temp) * (double)TEX_HEIGHT)
				+ tex_start;
		color = game->tex.img[game->wall.cardinal]
			.data[game->tex.tex_y * TEX_HEIGHT + game->tex.tex_x];
		game->img.data[to_coord(game, pos[0].x, game->tex.y_iter)] =
			shading(game->wall.distance, color);
		game->tex.y_iter += 1;
	}
}

void	make_wall_by_image(t_game *game, t_pos pos[2])
{
	if (game->wall.what_hit == VERT_HIT)
		game->tex.tex_x = (int)(fmod(game->wall.y, game->common_tsize) /
				game->common_tsize * TEX_HEIGHT);
	else
		game->tex.tex_x = (int)(fmod(game->wall.x, game->common_tsize) /
				game->common_tsize * TEX_WIDTH);
	if (game->wall.cardinal == WEST)
		game->tex.tex_x = TEX_HEIGHT - game->tex.tex_x;
	if (game->wall.cardinal == SOUTH)
		game->tex.tex_x = TEX_WIDTH - game->tex.tex_x;
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

	set_pos(&pos[0], (game->ray.angle + game->seek_angle / 2) *
			game->win.width / game->seek_angle,
			(game->win.height / 2 - (game->wall.realheight / 2)));
	set_pos(&pos[1], pos[0].x,
			game->win.height / 2 + (game->wall.realheight / 2));
	check_cardinal(game);
	make_wall_by_image(game, pos);
}

void	make_3d(t_game *game)
{
	double	dist_opt;

	game->ray.angle = -1 * game->seek_angle / 2;
	while (game->ray.angle < game->seek_angle / 2)
	{
		sprite_init(game);
		game->wall.angle = game->player.rot_angle + game->ray.angle;
		specify_angle(&game->wall.angle);
		game->wall.distance = shoot_ray(game) *
			cos(to_radian(game->ray.angle));
		dist_opt = (game->win.width / 2) /
			tan(to_radian(game->seek_angle / 2));
		game->wall.realheight = (game->common_tsize /
				game->wall.distance) * dist_opt;
		make_ceil(game);
		make_floor(game);
		make_wall(game);
		make_sprite(game);
		game->ray.angle += game->ray_term;
	}
}
