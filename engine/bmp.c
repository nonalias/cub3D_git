/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 20:20:10 by taehkim           #+#    #+#             */
/*   Updated: 2020/09/18 22:44:29 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void
	set_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

static int
	write_bmp_header(int fd, int filesize, t_game *game)
{
	int				i;
	int				tmp;
	unsigned char	bmpfileheader[54];

	i = 0;
	while (i < 54)
		bmpfileheader[i++] = (unsigned char)(0);
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	set_int_in_char(bmpfileheader + 2, filesize);
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	tmp = game->win.width;
	set_int_in_char(bmpfileheader + 18, tmp);
	tmp = game->win.height;
	set_int_in_char(bmpfileheader + 22, tmp);
	bmpfileheader[26] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(24);
	return (!(write(fd, bmpfileheader, 54) < 0));
}

static int
	get_color(t_game *game, int x, int y)
{
	int	rgb;
	int	color;

	color = *(int*)(game->img.data + (y * (game->win.width) + x));
	rgb = (color & 0xFF0000) | (color & 0x00FF00) | (color & 0x0000FF);
	return (rgb);
}

static int
	write_bmp_data(int file, t_game *game, int pad)
{
	const unsigned char	zero[3] = {0, 0, 0};
	int					i;
	int					j;
	int					color;

	i = game->win.height - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < (int)game->win.width)
		{
			color = get_color(game, j, i);
			if (write(file, &color, 3) < 0)
				return (0);
			if (pad > 0 && write(file, &zero, pad) < 0)
				return (0);
			j++;
		}
		i--;
	}
	return (1);
}

int
	save_bmp(t_game *game)
{
	int			filesize;
	int			file;
	int			pad;

	pad = (4 - ((int)game->win.width * 3) % 4) % 4;
	filesize = 54 + (3 * ((int)game->win.width + pad) * (int)game->win.height);
	if ((file = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC, 
			S_IRUSR | S_IWUSR | S_IXUSR)) < 0)
	{
		printf("open error\n");
		return (0);
	}
	if (!write_bmp_header(file, filesize, game))
	{
		printf("header write error\n");
		return (0);
	}
	if (!write_bmp_data(file, game, pad))
	{
		printf("data write error\n");
		return (0);
	}
	close(file);
	return (1);
}
