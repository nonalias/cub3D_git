#include "cub3d.h"

void	flag_process(t_game *game)
{
	//save_process(game);
}

/*
int		valid_check(t_game *game)
{
	game->map.fd = open(game->map.name, O_RDONLY);
	if (fd < 2)
		printf("MAP ERROR");
}
*/

void	set_texture(t_game *game)
{
	int		x;
	int		y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < TEX_HEIGHT * TEX_WIDTH)
		{
			game->tex.texture[x][y] = 0x000000;
			y++;
		}
		x++;
	}
	x = 0;
	while (x < TEX_WIDTH)
	{
		y = 0;
		while (y < TEX_HEIGHT)
		{
			int xorcolor = (x * 256 / TEX_WIDTH) ^ (y * 256 / TEX_HEIGHT);
			int ycolor = y * 256 / TEX_HEIGHT;
			int xycolor = y * 128 / TEX_HEIGHT + x * 128 / TEX_WIDTH;
			game->tex.texture[0][TEX_WIDTH * y + x] = 65536 * 254 * (x != y && x != TEX_WIDTH - y);
			game->tex.texture[1][TEX_WIDTH * y + x] = xycolor + 256 * xycolor + 65536 * xycolor;
			game->tex.texture[2][TEX_WIDTH * y + x] = 256 * xycolor + 65536 * xycolor;
			game->tex.texture[3][TEX_WIDTH * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor;
			y++;
		}
		x++;
	}
}

int		main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	init(game);
	arg_parse(game, argc, argv);
	//if (!valid_check(game))
		//return (1);
	//valid_check(game);
	//flag_process(game);
	set_texture(game);
	mlx_hook(game->win_ptr, KEY_PRESSED, 0, &key_press_callback, game);
	mlx_hook(game->win_ptr, KEY_RELEASED, 0, &key_release_callback, game);
	mlx_loop_hook(game->mlx_ptr, &hook_action, game);
	mlx_loop(game->mlx_ptr);
}
