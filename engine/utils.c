#include "../cub3d.h"

void	arg_parse(t_game *game, int argc, char **argv)
{
	int		i;

	if (argc == 1)
		return ;
	game->map.name = argv[1];
	i = 2;
	while (i < argc)
	{
		if (!ft_strncmp(argv[i], "--save", 6))
			game->flags.save = 1;
		else if (!ft_strncmp(argv[i], "--debug", 7))
			game->flags.debug = 1;
		i++;
	}
}

void	error_exit(int error_code)
{
	printf("ERROR\n");
	if (error_code == MAP_ERROR)
		printf("MAP ERROR\n");
	//여기에 다른 에러 코드 추가
	exit(0);
}

void	specify_angle(double *angle)
{
	if (*angle < 0)
		*angle += 360;
	else if (*angle > 360)
		*angle -= 360;
}

void	specify_radian(double *radian)
{
	if (*radian < 0)
		*radian += 2 * M_PI;
	else if (*radian > 2 * M_PI)
		*radian -= 2 * M_PI;
}
