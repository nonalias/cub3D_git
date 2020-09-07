/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 14:49:13 by taehkim           #+#    #+#             */
/*   Updated: 2020/09/07 14:51:02 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	flag_process(t_game *game)
{
	//save_process(game);
}

void	get_texture(t_game *game)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		game->tex.img[i].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
				game->map.s[i],
				&game->tex.img[i].width, &game->tex.img[i].height);
		if (game->tex.img[i].img_ptr == NULL)
			error_exit(game, TEX_ERROR, "texture error");
		game->tex.img[i].data = (int*)mlx_get_data_addr(
				game->tex.img[i].img_ptr, &game->tex.img[i].bpp,
				&game->tex.img[i].size_l, &game->tex.img[i].endian);
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	arg_parse(game, argc, argv);
	parse(game);
	init(game);
	validation(game);
	get_texture(game);
	mlx_hook(game->win_ptr, KEY_PRESSED, 0, &key_press_callback, game);
	mlx_hook(game->win_ptr, KEY_RELEASED, 0, &key_release_callback, game);
	mlx_loop_hook(game->mlx_ptr, &hook_action, game);
	mlx_loop(game->mlx_ptr);
}
