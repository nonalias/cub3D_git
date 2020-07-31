#ifndef __CUB3D_H

# define __CUB3D_H
# include "./mlx/mlx.h"
# include "./libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "const.h"

typedef struct	s_img {
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_player
{
	double		cur_x;
	double		cur_y;
	double		rot_angle;
	double		rot_speed;
	int			move_speed;
}				t_player;

typedef	struct	s_line
{
	int			color;
	double		origin_x;
	double		origin_y;
	double		target_x;
	double		target_y;
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
}				t_debug; //TODO : 끝날 때 free 해 주어야 함.

typedef struct	s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*map_name;
	t_window	win;
	t_img		img;
	t_player	player;
	t_line		line;
	t_flag		flags;
	t_debug		debug;
	int			seek_angle;
	int			seek_distance;
	double		tile_xsize;
	double		tile_ysize;
	int			key_check[300];
	int			map_xlength;
	int			map_ylength;
}				t_game;

int		my_map[11][11];

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
void			make_rader_line(t_game *game);
void			make_3d(t_game *game);
void			make_player(t_game *game);
void			make_line(t_game *game); // TODO: line 매개변수로 넣을지 game 단에서 처리할지 결정
void			make_view(t_game *game);
void			make_tile(t_game *game, int i, int j, int color);

int				key_press_callback(int keycode, t_game *game);
int				key_release_callback(int keycode, t_game *game);

int				get_wall_distance(t_game *game);
int				check_wall(t_game *game, double x, double y);

int				hook_action(t_game *game);

void			init(t_game *game);

void			move_w_a(t_game *game);
void			move_w_d(t_game *game);
void			move_w(t_game *game);
void			move_s_a(t_game *game);
void			move_s_d(t_game *game);
void			move_s(t_game *game);
void			move_a(t_game *game);
void			move_d(t_game *game);
int				to_coord(t_game *game, double x, double y);

void			debug_process(t_game *game);

#endif
