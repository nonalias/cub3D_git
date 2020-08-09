/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 14:49:13 by taehkim           #+#    #+#             */
/*   Updated: 2020/08/09 18:02:56 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	get_texture(t_game *game)
{
	game->tex.img[EAST].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/wall_1.xpm",
			&game->tex.img[EAST].width, &game->tex.img[EAST].height);
	game->tex.img[EAST].data = (int*)mlx_get_data_addr(
			game->tex.img[EAST].img_ptr, &game->tex.img[EAST].bpp,
			&game->tex.img[EAST].size_l, &game->tex.img[EAST].endian);
	game->tex.img[WEST].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/wall_2.xpm",
			&game->tex.img[WEST].width, &game->tex.img[WEST].height);
	game->tex.img[WEST].data = (int*)mlx_get_data_addr(
			game->tex.img[WEST].img_ptr, &game->tex.img[WEST].bpp,
			&game->tex.img[WEST].size_l, &game->tex.img[WEST].endian);
	game->tex.img[SOUTH].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/wall_3.xpm",
			&game->tex.img[SOUTH].width, &game->tex.img[SOUTH].height);
	game->tex.img[SOUTH].data = (int*)mlx_get_data_addr(
			game->tex.img[SOUTH].img_ptr, &game->tex.img[SOUTH].bpp,
			&game->tex.img[SOUTH].size_l, &game->tex.img[SOUTH].endian);
	game->tex.img[NORTH].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./textures/wall_4.xpm",
			&game->tex.img[NORTH].width, &game->tex.img[NORTH].height);
	game->tex.img[NORTH].data = (int*)mlx_get_data_addr(
			game->tex.img[NORTH].img_ptr, &game->tex.img[NORTH].bpp,
			&game->tex.img[NORTH].size_l, &game->tex.img[NORTH].endian);
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
	get_texture(game);
	mlx_hook(game->win_ptr, KEY_PRESSED, 0, &key_press_callback, game);
	mlx_hook(game->win_ptr, KEY_RELEASED, 0, &key_release_callback, game);
	mlx_loop_hook(game->mlx_ptr, &hook_action, game);
	mlx_loop(game->mlx_ptr);
}
