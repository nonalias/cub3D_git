#include "mlx/mlx.h"

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x, y, color;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "ModyHooooon");
	color = 0;
	x = 0;
	while (x < 1000)
	{
		y = 0;
		while (y < 1000)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 1255255000);
			color++;
			y++;
			if (color == 256)
				color = 0;
		}
		x++;
	}
	mlx_loop(mlx_ptr);
}
