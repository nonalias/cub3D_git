/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 18:03:15 by taehkim           #+#    #+#             */
/*   Updated: 2020/09/07 14:53:54 by taehkim          ###   ########.fr       */
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
}				t_debug;

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
	int			had_set_position;
	char		**splited;
	char		*line;
	char		*s[5];
	int			floor;
	int			ceil;
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
	double		common_tsize;
	double		tile_xsize;
	double		tile_ysize;
	double		ray_term;
	int			key_check[300];
}				t_game;

int		g_my_map[MAX_MAP_SIZE][MAX_MAP_SIZE];

void			make_2d(t_game *game);
void			make_rader(t_game *game);
void			make_one_rader(t_game *game);
void			make_rader_line(t_game *game, t_pos origin, t_pos target);
void			make_3d(t_game *game);
void			make_line(t_game *game, t_pos origin, t_pos target);
void			make_view(t_game *game);
void			make_tile(t_game *game, int i, int j, int color);
void			make_crosshair(t_game *game);
void			make_rectangle(t_game *game, t_pos pos[2], int color);
void			make_floor(t_game *game);
void			make_ceil(t_game *game);

int				key_press_callback(int keycode, t_game *game);
int				key_release_callback(int keycode, t_game *game);
int				exit_callback(t_game *game);

int				get_wall_distance(t_game *game);
double			shoot_ray(t_game *game);
void			check_cardinal(t_game *game);
int				check_wall(t_game *game, double x, double y);

int				hook_action(t_game *game);
void			key_matching(t_game *game);

void			init(t_game *game);
void			game_init(t_game *game);
void			win_init(t_game *game);
void			player_init(t_game *game);
void			ray_init(t_game *game);
void			wall_init(t_game *game);
void			cart_init(t_game *game);
void			sprite_init(t_game *game);

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
void			error_exit(t_game *game, int code, char *message);
void			parse(t_game *game);
void			specify_angle(double *angle);
void			specify_radian(double *radian);
void			free_line(char **line);

double			raycasting_vert(t_game *game);
double			raycasting_horz(t_game *game);

void			reset_player(t_game *game);

int				check_sprite(t_game *game, double x, double y);
void			make_sprite(t_game *game);

void			validation(t_game *game);
int				is_map_position(char c);

void			show_map(t_game *game);
double			to_proper_coord(t_game *game, double origin, int x_or_y);
int				shading(double distance, int color);

/*
** parse.c
*/

void	resolution_parse(t_game *game, char **splited);
int		str_to_color(char *str);

/*
** init2.c
*/
void	map_init(t_game *game);

/*
** utils2.c
*/
double			to_radian(double x);
double			to_degree(double x);
void	show_map(t_game *game);
int		check_sprite(t_game *game, double x, double y);

/*
** validation2.c
*/

int		is_option_valid(t_game *game);
int		is_map_element(char c);
int		is_map_position(char c);

/*
** free.c
*/

void	free_splited(char ***splited);
void	free_line(char **line);

/*
** option_parse.c
*/

int		is_option(char c);
void	option_parsing2(t_game *game);
void	option_parsing(t_game *game);

/*
** bmp.c
*/

int		save_bmp(t_game *game);

#endif
