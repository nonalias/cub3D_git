#ifndef __CUB3D_H

# define __CUB3D_H
# include "./mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define KEY_PRESSED 2
# define KEY_RELEASED 3
# define WIN_WIDTH 500
# define WIN_HEIGHT 500


typedef struct	s_img
{
	void		*img_ptr;
	int			data;
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

typedef struct	s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_window	win;
	t_img		img;
	t_player	player;
	t_line		line;
	int			key_check[300];
}				t_game;

int				make_2d(t_game *game);
int				make_rader(t_game *game);
void			make_3d(t_game *game);
void			make_player(t_game *game);
void			make_line(t_game *game); // TODO: line 매개변수로 넣을지 game 단에서 처리할지 결정
void			make_view(t_game *game);

int				key_press_callback(int keycode, t_game *game);
int				key_release_callback(int keycode, t_game *game);

int				get_wall_distance(t_game *game);
int				check_wall(int x, int y);

int				hook_action(t_game *game);

void			init(t_game *game);



#endif
