/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 18:03:15 by taehkim           #+#    #+#             */
/*   Updated: 2020/08/12 15:50:30 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CUB3D_H
# define __CUB3D_H
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <math.h>
# include "const.h"
# include <float.h>
# include <fcntl.h>
# include <unistd.h>
# define TO_RADIAN(x) (((M_PI) / (180)) * (x))
# define TO_DEGREE(x) ((x) * (180) / (M_PI))
# define HORZ_HIT 0
# define VERT_HIT 1

typedef struct	s_img {
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			height;
	int			width;
}				t_img;

typedef struct	s_player
{
	double		x;
	double		y;
	double		rot_angle;
	double		rot_speed;
	double		move_speed;
}				t_player;

typedef	struct	s_line
{
	int			color;
	/*
	double		origin_x;
	double		origin_y;
	double		target_x;
	double		target_y;
	*/
}				t_line;

typedef struct	s_window
{
	int			width;
	int			height;
}				t_window;

typedef	struct	s_flag
{
	int			debug;
	int			save;
}				t_flag;

typedef struct	s_debug
{
	char		*map_str;
	char		*x_str;
	char		*y_str;
	char		*rot_angle_str;
	char		*move_speed_str;
	char		*rot_speed_str;
}				t_debug; //TODO : 끝날 때 free 해 주어야 함.

typedef	struct	s_wall
{
	double		x;
	double		y;
	double		angle;
	double		distance;
	double		realheight;
	int			what_hit;
	int			cardinal;
}				t_wall;

typedef struct	s_ray
{
	double		angle;
	double		vertx;
	double		verty;
	double		horzx;
	double		horzy;
	double		xintercept;
	double		yintercept;
	double		xstep;
	double		ystep;
	int			foundhorzwallhit;
	int			foundvertwallhit;
	int			up_facing;
	int			down_facing;
	int			left_facing;
	int			right_facing;
}				t_ray;

typedef struct	s_map
{
	int			columns;
	int			rows;
	int			fd;
	char		*name;
}				t_map;

typedef struct	s_tex
{
	t_img		img[5];
	int			**cart;
	int			tex_x;
	int			tex_y;
	double		y_iter;
}				t_tex;

typedef	struct	s_pos
{
	double		x;
	double		y;
}				t_pos;

typedef	struct	s_sprite
{
	int			what_hit;
	double		vert_x;
	double		vert_y;
	double		horz_x;
	double		horz_y;
	double		vert_dist;
	double		horz_dist;
	int			horz_hit;
	int			vert_hit;
	double		center_x;
	double		center_y;
	t_pos		hit;
	int			coord_x;
	int			coord_y;
	double		center_angle;
	double		min_angle;
	double		max_angle;
	double		dist_opt;
	double		realheight;
	double		angle;
	double		distance;
}				t_sprite;

typedef struct	s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_window	win;
	t_img		img;
	t_player	player;
	t_line		line;
	t_flag		flags;
	t_debug		debug;
	t_wall		wall;
	t_ray		ray;
	t_map		map;
	t_tex		tex;
	t_sprite	spr;
	double		temp;
	int			seek_angle;
	int			seek_distance;
	double		tile_xsize;
	double		tile_ysize;
	int			key_check[300];
}				t_game;

int		my_map[11][15];

/*
int		my_map[11][11] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1},
	{1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};
*/

void			make_2d(t_game *game);
void			make_rader(t_game *game);
void			make_one_rader(t_game *game);
void			make_rader_line(t_game *game, t_pos origin, t_pos target);
void			make_3d(t_game *game);
void			make_player(t_game *game);
void			make_line(t_game *game, t_pos origin, t_pos target); // TODO: line 매개변수로 넣을지 game 단에서 처리할지 결정
void			make_view(t_game *game);
void			make_tile(t_game *game, int i, int j, int color);
void			make_crosshair(t_game *game);
void			make_rectangle(t_game *game, t_pos pos[2], int color);
void			make_floor(t_game *game);
void			make_ceil(t_game *game);

int				key_press_callback(int keycode, t_game *game);
int				key_release_callback(int keycode, t_game *game);

int				get_wall_distance(t_game *game);
double			shoot_ray(t_game *game);
void			check_cardinal(t_game *game);
int				check_wall(t_game *game, double x, double y);

int				hook_action(t_game *game);
void			key_matching(t_game *game);

void			init(t_game *game);
void			win_init(t_game *game);
void			game_init(t_game *game);
void			player_init(t_game *game);
void			ray_init(t_game *game);
void			wall_init(t_game *game);
void			flag_init(t_game *game);
void			cart_init(t_game *game);
void			sprite_init(t_game *game);
void			sprite_reinit(t_game *game);

void			set_pos(t_pos *pos, double x, double y);

void			move_w_a(t_game *game);
void			move_w_d(t_game *game);
void			move_w(t_game *game);
void			move_s_a(t_game *game);
void			move_s_d(t_game *game);
void			move_s(t_game *game);
void			move_a(t_game *game);
void			move_d(t_game *game);
int				move_check(t_game *game);
int				to_coord(t_game *game, double x, double y);

void			status_show(t_game *game);
void			arg_parse(t_game *game, int argc, char **argv);
void			specify_angle(double *angle);
void			free_process(t_game *game);

double			raycasting_vert(t_game *game);
double			raycasting_horz(t_game *game);

void			reset_player(t_game *game);

int				check_sprite(t_game *game, double x, double y);
void			make_sprite(t_game *game);
#endif
